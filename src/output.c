#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Turns a wave into a short, clipping out-of-range values

static
int16_t output_quantize(double wave)
{
	return (int16_t)
		fmax( fmin( wave, 1.0 ), -1.0 ) * 0xffff - 0x7fff;
}

void output_printS16(int16_t input)
{
	putchar(input);
	putchar(input >> 8);	
}
