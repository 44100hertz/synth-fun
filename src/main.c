#include <stdio.h>
#include <string.h>
#include "song.h"
#include "playback.h"

int main(int argc, char *argv[]) {

	int freq = 48000;

	songData testSong = makesong();
	
    song(freq, testSong);
}
