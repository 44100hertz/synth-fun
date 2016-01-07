#include <stdio.h>
#include <math.h>
#include "song.c"
#include "waves.c"
#include "quantize.c"
#include "note.c"
#include "testSong.c"

int song(int sampleRate, songData song) {
	double phase = 0;
	int tick = -1;
	int offset = 0;
	short byteOut;
	
	// timer cycle
	for(long timer = 0; song.pattern != -1; timer++) {
		if(tick < (tick=timer / sampleRate / 60 * BPM * tickRate)) {
			slope[i] = ( noteCalcChar(song.key[i + offset]) / sampleRate );
			++offset;
		}
		phase = fmod((timer * slope), 1.0) * 2 - 1;

		byteOut = quantize( sineWave(phase) );
		
		putchar(byteOut << 8);
		putchar(byteOut >> 8);
	}
}

