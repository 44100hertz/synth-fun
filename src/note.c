#include <stdio.h>
#include <math.h>

#include "note.h"

// Returns the frequency of a note. Uses MIDI.

#define MIDDLE_C 440.0
#define ROOT_12_2 1.05946309435929526456 // twelfth root of 2

double noteCalcChar(char noteNum)
{
	return noteCalc(noteNum - 'c' + 60.0);
}

double noteCalc(double noteNum)
{
	double relativeNote = noteNum - 60.0;
	return MIDDLE_C * pow( ROOT_12_2, (double)relativeNote );
}

