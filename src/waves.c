#include <stdio.h>
#include <math.h>

// Sine wave.
double sineWave(double phase) {
	return sin( phase * M_PI );
}

// Square wave w/aliasing.
double squareWave(double phase) {
	if( phase >= M_PI ) {
		return( -1 );
	} else {
		return( 1 );
	}
}

// Triangle wave w/aliasing
double triangleWave(double phase) {
	if( phase < 1.0 ) {
		return(phase * 2.0);
	} else {
		return(phase * -2.0);
	}
}
