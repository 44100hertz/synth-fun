./bin/song:
default: 
	gcc src/gen.c src/main.c src/note.c src/output.c src/playback.c src/song.c -lm -o bin/song

clean:
	rm -rf bin/song

.PHONY: default clean
