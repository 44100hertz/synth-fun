#include <stdint.h>
#define NUM_CHANNELS 8
#define NUM_INSTRUMENTS 8
enum { KEY_STOP, KEY_ON, KEY_OFF  };

typedef struct {
	uint16_t BPM;
	uint8_t tickRate;
	char *key;
} songData;

typedef struct {
	uint8_t envState;
	uint16_t pat;
	uint8_t patRate;
	uint16_t env;
	double envSlope;
        double phase;
        double slope;
} channel[NUM_CHANNELS];

songData struct_makeSong();

void song_print(songData song);
