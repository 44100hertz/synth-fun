#include <stdio.h>
#include <math.h>

// TODO: make it easier to adjust functions' ranges
//	e.g. is it useful to have a function with less range?

// Give a sine wave.
double sineFM(double phase) {
	return sin( phase ) * M_PI + M_PI;
}

// Absolute value of a sine wave.
double absSineFM(double phase) {
	return fabs( sin( phase ) * 2.0 * M_PI );
}

// Square wave. Aliased. Used as a carrier for C64 tones.
double squareFM(double phase) {
	if( phase % PI_2 >= M_PI ) {
		return( 0 );
	} else {
		return( M_PI * 2.0 );
	}
}

// Triangle wave. Aliased.
double triangleFM(double phase) {
	if( phase % PI_2 >= M_PI ) {
		return(phase * 2.0);
	} else {
		return(-2.0 * phase + M_PI);
	}
}
