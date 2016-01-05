#include <stdio.h>
#include <math.h>

char quantizeFMtoChar(double wave) {
	return (char)(wave / 2.0 / M_PI * 0xFF - 0x7F);
}
