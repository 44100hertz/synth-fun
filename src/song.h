typedef struct {
	int BPM;
	int tickRate;

	int pattern;
	
	char *key;
} songData;

songData song_generate();

void song_print(songData song);
