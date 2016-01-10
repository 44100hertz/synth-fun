#include <stdio.h>
#include <math.h>
#include "song.h"
#include "gen.h"
#include "output.h"
#include "note.h"

int playback(int sampleRate, songData song)
{
	int tick = 0;
	int offset = 0;
	double phase = 0;
	double slope = noteCalcChar(song.key[offset % 7]) / sampleRate;
	
	for(int timer = 0; timer < sampleRate * 20; timer++) {		
		int nextTick = timer * song.BPM * song.tickRate / sampleRate / 60;
		if(nextTick > tick) {
			++offset;
			slope = noteCalcChar(song.key[offset % 7]) / sampleRate;
			tick = nextTick;
		}

		phase += slope;
		phase = fmod(phase, 1.0);

		// outputs a sine wave f1or testing
		output_printS16(gen_sine(phase));
	}

	return 0;
}
