#include <stdio.h>
#include <math.h>

#define TAU (M_PI * 2.0)

// Sine wave.
double gen_sine(double phase)
{
	return sin( phase * TAU );
}

// Square wave w/aliasing.
double gen_square(double phase)
{
	if( phase >= 0.5 ) {
		return( 0 );
	} else {
		return( 1 );
	}
}

// Triangle wave w/aliasing
double gen_triangle(double phase)
{
	return( fabs(phase - 1.0) * 2.0 );
}
