#include <stdio.h>
#include <math.h>
#include "song.h"
#include "gen.h"
#include "output.h"
#include "note.h"

int song(int sampleRate, songData song) {

	double phase = 0;
	int tick = -1;
	int offset = 0;
	short byteOut;
	
	// timer cycle
	for(long timer = 0; song.pattern != -1; timer++) {
		int nextTick = timer / sampleRate / 60 * song.BPM * song.tickRate;
		
		if(nextTick > tick) {
			slope[i] = ( noteCalcChar(song.key[i + offset]) / sampleRate );
			++offset;
		}
		
		phase = fmod((timer * slope), 1.0) * 2 - 1;

		output_printS16( gen_sine( phase ) );
	}

	return 0;
}

