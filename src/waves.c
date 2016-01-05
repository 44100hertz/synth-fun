#include <stdio.h>
#include <math.h>
#include format.h

// TODO: make it easier to adjust functions' ranges
//	e.g. is it useful to have a function with less range?

// Give a sine wave.
double sineWave(double phase) {
	return sin( phase ) + M_PI;
}

// Absolute value of a sine wave.
double absSineWave(double phase) {
	return fabs( sin( phase ) * 2.0 );
}

// Square wave. Aliased. Used as a carrier for C64 tones.
double squareWave(double phase) {
	if( phase % PI_2 >= M_PI ) {
		return(0);
	} else {
		return( M_PI * 2.0 );
	}
}

// Triangle wave. Aliased.
double triangleWave(double phase) {
	if( phase % PI_2 >= M_PI ) {
		return(phase * 2.0);
	} else {
		return(-2.0 * phase + M_PI);
	}
}
