#include <stdio.h>
#include <math.h>

#define MIDDLE_C 440.0
#define STARTING_NOTE 100
#define ROOT_12_2 1.059463094359 // twelfth root of 2

// Returns the frequency of a note
double noteCalc(char noteNum) {
	int relativeNote = noteNum - STARTING_NOTE;
	return MIDDLE_C * pow( ROOT_12_2, (double)relativeNote );
}
