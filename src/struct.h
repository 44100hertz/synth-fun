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
	uint8_t sustainTick;
} instrument;

typedef struct {
	instrument inst;
	uint8_t envState;
	uint16_t readPos;
	uint8_t readRate;
	uint16_t env;
	double envSlope;
	uint16_t phase;
    double slope;
} channel[NUM_CHANNELS];

songData struct_makeSong();

void song_print(songData song);
