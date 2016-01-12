#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "output.h"

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
	printf("%c%c", input, input >> 8);
}

void output_fileS16(double wave, FILE *path)
{
	int16_t input = output_quantize(wave);
	fprintf(path, "%c%c", input, input >> 8);
}
