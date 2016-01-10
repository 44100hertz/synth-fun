#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Turns a wave into a short, clipping out-of-range values

static
int16_t output_quantize(double wave)
{
	return (int16_t)
		(fmax( fmin( wave, 1.0 ), 0 ) * 0xffff - 0x8000);
}

void output_printS16(double wave)
{
	int16_t input = output_quantize(wave);
	putchar(input);
	putchar(input >> 8);
}
