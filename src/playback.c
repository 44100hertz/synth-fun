#include <stdio.h>
#include <math.h>
#include "song.h"
#include "gen.h"
#include "output.h"
#include "note.h"

int playback(int sampleRate, songData song, FILE *path)
{
	int offset = 0;
	double phase = 0;
	double slope;
	double env = 0;

    enum { STATE_END, STATE_BEAT, STATE_TICK, STATE_GEN };
	int state = STATE_BEAT;

	int tick = 0;
	int timer = 0;
	while(state != STATE_END) {
		int nextTick = timer * song.BPM * song.tickRate / sampleRate / 60;

		if((int)(nextTick / song.tickRate) > (int)(tick / song.tickRate))
			state = STATE_BEAT;
		else if(nextTick > tick)
			state = STATE_TICK;

		switch (state) {
		case STATE_BEAT:
			++offset;
			env = 0;
			double envslope = 1.0 / (double)song.tickRate;
		case STATE_TICK:
			slope = noteCalcChar(song.key[offset % 7]) / (double)sampleRate;
			env += envslope;
			tick = nextTick;
		case STATE_GEN:
			phase += slope;
			phase = fmod(phase, 1.0);
			state = STATE_GEN;
			++timer;
		}

		if(timer > sampleRate * 60 * 16 / song.BPM) // HARD CODE
			state = STATE_END;
		tick = nextTick;
		output_fileS16(gen_sine(phase * gen_1poly(env, 1.0, 1.0)), path);
	}

	return 0;
}
