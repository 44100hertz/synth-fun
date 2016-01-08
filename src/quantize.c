#include <stdio.h>
#include <math.h>

// Turns a wave into a short, clipping out-of-range values

short quantize(double wave) {
	return (short)
		fmax( fmin( wave, 1.0 ), -1.0 ) * 0xff - 0x7f;
}
