#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "playback.h"

int main(int argc, char *argv[])
{

	uint16_t freq = 48000;
	FILE *path;

	songData testSong = struct_makeSong();
//	song_print(testSong);

	if(argc>1) {
	    path = fopen(argv[1], "w");
	} else {
		path = stdout;
	}

    playback(freq, testSong, path);
}
