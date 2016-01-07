#include <stdio.h>
#include <string.h>
#include "song.c"
#include "playback.c"

int main(int argc, char *argv[]) {

	int freq = 48000;

	songData testSong = makesong();
	
	return song(freq, testSong);
}
