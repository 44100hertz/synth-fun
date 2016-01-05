#include <stdio.h>
#include <math.h>

// Returns the frequency of a note. Uses MIDI.

#define MIDDLE_C 440.0
#define STARTING_NOTE 60
#define ROOT_12_2 1.05946309435929526456 // twelfth root of 2

double noteCalcChar(char noteNum) {
	int relativeNote = noteNum - STARTING_NOTE;
	return MIDDLE_C * pow( ROOT_12_2, (double)relativeNote );
}

double noteCalc(double noteNum) {
	double relativeNote = noteNum - STARTING_NOTE;
	return MIDDLE_C * pow( ROOT_12_2, (double)relativeNote );
}
