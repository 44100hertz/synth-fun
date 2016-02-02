#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "output.h"

// Turns a wave into a short
static
int16_t output_quantize(double wave)
{
	return (int16_t) wave - 0x7fff;
}

void output_fileS16(double wave, FILE *path)
{
	int16_t input = output_quantize(wave);
	fprintf(path, "%c%c", input >> 8, input);
}
