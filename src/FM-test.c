#include <stdio.h>
#include <math.h>
#include "fmwaves.c"
#include "quantize.c"

#define SAMPLE_RATE 48000.0
#define NOTE 440.0

int sineTest() {
	double phase = 0;
	double periodCount = NOTE / SAMPLE_RATE;
	
	for(long timer = 0; timer < SAMPLE_RATE * 5; timer++) {
		phase += periodCount;
		if( phase > 1.0 ) phase -= 1.0;
		putchar(
			quantize(
				sineFM(
					sineFM(phase * M_PI * 2.0) * SAMPLE_RATE / (double)timer
					 )
				)
			);
	}
}
