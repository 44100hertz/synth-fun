#include <stdio.h>
#include <math.h>
#include "fmwaves.c"
#include "quantize.c"
#include "note.c"

#define SAMPLE_RATE 48000.0
#define NOTES_LENGTH 0.2

int sineTest() {
	double phase = 0;
	char note;
	while( (note=getchar())!=EOF ) {
		double slope = ( noteCalc(note) / SAMPLE_RATE );
		for(long timer = 0; timer < SAMPLE_RATE * NOTES_LENGTH; timer++) {
			phase = fmod((timer * slope), 1.0) * M_PI * 2.0;
			putchar(
				quantize(
					sineFM(
					    sineFM( phase ) / timer * SAMPLE_RATE / NOTES_LENGTH / 8
						)
					)
				);
		}
	}
}
