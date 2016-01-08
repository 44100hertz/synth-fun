#include <stdlib.h>
#include <string.h>

char *makeScale(char root);

typedef struct {
	int BPM;
	int tickRate;

	int pattern;
	
	char *key;
} songData;
	
songData makesong() {

	static const char *scaleC = "cdefga";
	
	return (songData) {
		.BPM = 80,
			.tickRate = 24,
			.key = strdup(scaleC),
			.pattern = 0
			};
}
