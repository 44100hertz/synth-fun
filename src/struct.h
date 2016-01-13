typedef struct {
	int BPM;
	int tickRate;
	char *key;
} songData;

typedef struct {
	int tickRate;
	int readPos;
	int instrument;
} channel;

songData struct_makeSong();

void song_print(songData song);
