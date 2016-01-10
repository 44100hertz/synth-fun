#include <stdio.h>
#include <math.h>
#include "song.h"
#include "gen.h"
#include "output.h"
#include "note.h"

int playback(int sampleRate, songData song)
{
	double phase = 0;
	double slope;
	int tick = -1;
	int offset = 0;
	
	for(long timer = 0; song.pattern != -1; timer++) {
		int nextTick = timer / sampleRate / 60 * song.BPM * song.tickRate;	
		if(nextTick > tick) {
			slope = noteCalcChar(song.key[offset] / sampleRate);
			++offset;
		}
		// multiplies by slope, creating a sawtooth that loops at the intended period
		phase = fmod((timer * slope), 1.0) * 2 - 1;
		// outputs a sine wave for testing
		output_printS16( gen_sine( phase ) );
	}

	return 0;
}

