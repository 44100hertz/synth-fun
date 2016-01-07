#include <stdio.h>
#include <math.h>

// Turns an FM wave (normally range 0 - 2pi) into a char
// Out-of-range values are clipped
char quantizeFMtoChar(double wave) {
	return (char)fmax(
		fmin(
			(wave / 2.0 / M_PI * 0xFF - 0x7F),
			1.0 ),
		-1.0 );
}
