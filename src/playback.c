#include <stdio.h>
#include <math.h>
#include "struct.h"
#include "gen.h"
#include "output.h"
#include "note.h"
#include "playback.h"

double sampleUpdate(channel chan);
void tickUpdate(channel chan);

int playback(int sampleRate, FILE *readPath, FILE *path)
{
	channel chan;
        songData song = struct_makeSong();
	double envSlope = 0xffff / (double)song.tickRate;
	uint32_t tick = 0; uint32_t nextTick = 0;
	uint32_t timer = 0;
	while(1) {
		tick = nextTick;
		tickUpdate(chan);
		while(nextTick = tick) {
			double mix = sampleUpdate(chan);
			int nextTick = timer * song.BPM * song.tickRate / sampleRate / 60;
			output_fileS16(mix * 0xffff, path);
		}
	}
	return 0;
}

double sampleUpdate(channel chan) {
	uint8_t i;
	double mix;
	for(i=0; i<NUM_CHANNELS; i++) {
		if(chan[i].patRate > 0) {
			chan[i].phase += chan[i].slope;
                        if(chan[i].phase > 0xffff) chan[i].phase -= 0xffff;
		}
		mix += chan[i].phase;
	}
	return mix;
}

void tickUpdate(channel chan) {
	uint8_t i;
	for(i=0; i<NUM_CHANNELS; i++) {
                // FIXME: update envelope
	}
}
