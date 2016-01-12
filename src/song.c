#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "song.h"

songData song_generate()
{
	static const char *scaleC = "cdefgab";

	return (songData) {
		.BPM = 80,
			.tickRate = 24,
			.key = strdup(scaleC),
			.pattern = 0
			};
}

void song_print(songData song)
{
	printf("creating song:\n");
	printf("  BPM: \t%d\n", song.BPM);
	printf("  tickRate: \t%d\n", song.tickRate);
	printf("  starting pattern: \t%d\n", song.pattern);
	printf("  key data:\t%s\n", song.key);
}
