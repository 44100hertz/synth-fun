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

    enum { STATE_END, STATE_BEAT, STATE_TICK, STATE_GEN };
	int state = STATE_BEAT;

	int tick = 0;
	int timer = 0;
	while(state != STATE_END) {
		int nextTick = timer * song.BPM * song.tickRate / sampleRate / 60;

		if(nextTick % song.BPM > nextTick % song.BPM)
			state = STATE_BEAT;
		else if(nextTick > tick)
			state = STATE_TICK;

		switch (state) {
		case STATE_BEAT:
		case STATE_TICK:
			++offset;
			double slope = noteCalcChar(song.key[offset % 7]) / sampleRate;
			tick = nextTick;
		case STATE_GEN:
			phase += slope;
			phase = fmod(phase, 1.0);
			state = STATE_GEN;
			++timer;
		}

		if(timer > sampleRate * 60 / song.BPM) state = STATE_END;
		tick = nextTick;

		output_fileS16(phase, path);
	}

	return 0;
}
