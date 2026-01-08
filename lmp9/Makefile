all: gauss testy

gauss:
	mkdir -p bin
	cc src/main.c src/mat_io.c src/gauss.c src/backsubst.c -o bin/gauss -lm

testy:
	mkdir -p bin
	cc -Wall src/testy.c src/mat_io.c src/gauss.c src/backsubst.c -o bin/testy -lm

test: testy
	./bin/testy

clean:
	rm -f bin/gauss bin/testy
