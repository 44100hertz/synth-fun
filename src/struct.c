#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

songData struct_makeSong()
{
	static const char *scaleC = "cdefgab";

	return (songData) {
		.BPM = 80,
			.tickRate = 24,
			.key = strdup(scaleC),
			};
}

void song_print(songData song)
{
	printf("creating song:\n");
	printf("  BPM: \t%d\n", song.BPM);
	printf("  tickRate: \t%d\n", song.tickRate);
	printf("  key data:\t%s\n", song.key);
}
