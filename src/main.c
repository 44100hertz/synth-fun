#include <stdio.h>
#include <string.h>
#include "song.h"
#include "playback.h"

int main(int argc, char *argv[])
{

	int freq = 48000;
	FILE *path;

	songData testSong = song_generate();
//	song_print(testSong);

	if(argc>1) {
	    path = fopen(argv[1], "w");
	} else {
		path = stdout;
	}

    playback(freq, testSong, path);
}
