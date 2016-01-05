#include <stdio.h>
#include <math.h>

char quantize(double wave) {
	return (char)(wave / 2.0 / M_PI * 255 - 128);
}
