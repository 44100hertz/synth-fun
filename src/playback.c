#include <stdio.h>
#include <math.h>
#include "instrument.c"
#include "fmwaves.c"
#include "quantize.c"
#include "note.c"
#include "testsong.c"

int song(int sampleRate, song song) {

	double phase = 0;
	for(int timer = 0; timer < SAMPLE_RATE * 120; 
}
