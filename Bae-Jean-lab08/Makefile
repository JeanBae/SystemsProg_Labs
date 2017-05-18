all: cat

cat: cat.o
	g++ -Wall -g -lncurses -o cat cat.o

cat.o: cat.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -lncurses -c cat.cpp

clean:
	rm -f cat
	rm -f cat.o 