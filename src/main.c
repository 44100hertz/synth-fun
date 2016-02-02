#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "playback.h"

int main(int argc, char *argv[])
{

	uint16_t freq = 48000;
	FILE *writePath, *readPath;

//	songData testSong = struct_makeSong();
//	song_print(testSong);

        if(argc > 1)
                readPath = fopen(argv[1], "r");
        else
                readPath = fopen("./songs/song.sf", "r");
	if(argc > 2)
                writePath = fopen(argv[1], "w");
	else
		writePath = fopen("./out/test", "w");

        playback(freq, readPath, writePath);
}
