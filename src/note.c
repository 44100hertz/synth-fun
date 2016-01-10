#include <stdio.h>
#include <math.h>

#include "note.h"

// Returns the frequency of a note. Uses MIDI.

#define MIDDLE_C 440.0
#define ROOT_12_2 1.05946309435929526456 // twelfth root of 2

static char parseScale(char noteChar)
{
	switch(noteChar) {
	case 'a': return 57;
	case 'A': return 58;
	case 'b':
	case 'B': return 59;
	case 'c': return 60;
	case 'C': return 61;
	case 'd': return 62;
	case 'D': return 63;
	case 'e': return 64;
	case 'E': return 65;
	case 'f':
	case 'F': return 66;
	case 'g': return 67;
	default: return 0;
	}
}

double noteCalcChar(char noteChar)
{
	return noteCalc(parseScale(noteChar));
}

double noteCalc(double noteNum)
{
	double relativeNote = noteNum - 60.0;
	return MIDDLE_C * pow( ROOT_12_2, relativeNote );
}
