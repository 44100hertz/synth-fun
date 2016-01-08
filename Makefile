default: 
	gcc src/main.c -lm -o bin/sineTest

clean:
	rm -rf bin/sineTest

.PHONY: default clean
