default: bin/song

./bin/song: src/*.c src/*.h
	gcc src/*.c -lm -o bin/song

clean:
	rm -rf bin/song

.PHONY: default clean
