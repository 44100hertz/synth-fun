#include <stdio.h>
#include <math.h>
#include "song.h"
#include "gen.h"
#include "output.h"
#include "note.h"

int playback(int sampleRate, songData song)
{
	double slope;
//	int tick = -1;
	int offset = 0;

	slope = noteCalcChar(song.key[offset % 7]) / sampleRate;

//	fprintf(stderr, "%f, %f\n", slope, noteCalcChar(song.key[offset % 7]));
	
	for(int timer = 0; timer < sampleRate * 20; timer++) {
		
//		int nextTick = timer / sampleRate / 60 * song.BPM * song.tickRate;	
//		if(nextTick > tick) {

//			++offset;
//		}
		// multiplies by slope, creating a sawtooth that loops at the intended period
		double phase = fmod((timer * slope), 1.0);
		// outputs a saw wave f1or testing
		output_printS16(phase);
	}

	return 0;
}

