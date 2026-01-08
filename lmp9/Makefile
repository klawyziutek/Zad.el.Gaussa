SOURCES = $(wildcard src/*.c)
A = $(filter-out src/testy.c, $(SOURCES))
B = $(filter-out src/main.c, $(SOURCES))
all:
	gcc -Wall --pedantic $(A) -o bin/gauss

test: all
	bin/gauss dane/A dane/b

testy: 
	cc -Wall --pedantic $(B) -o bin/testy

Testy:
	bin/testy dane/DaneTestowe dane/b
