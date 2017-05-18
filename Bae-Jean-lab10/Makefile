all: rm

rm: rm.o
	g++ -o rm rm.o

rm.o: rm.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c rm.cpp


clean:
	rm -f rm
	rm -f rm.o 