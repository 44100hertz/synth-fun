#include <stdio.h>
#include <string.h>
#include "song.c"

enum { 8_BIT, 16_BIT };

int main(int argc, char *argv[]) {

	int freq = 48000;
	int depth = 2;
	
	for(int i=1; i<(argc-1); i++) {
		if (strncmp(argv[i], "-r", 2)) {
			freq = atoi(argv[i+1]);
			i++;
		} else if(strncmp(argv[i], "-d", 2)) {
			int depthBits = atoi(argv[i+1]);
		}
	}
	
	return song(freq, depth);
}
