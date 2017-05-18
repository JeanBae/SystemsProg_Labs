FLAGS = -Wall -O0 -g -std=c++14 -pedantic-errors

.PHONY: all clean doc

all: p1

p1: p1.o Matrix.o
	g++ $(FLAGS) -o p1 p1.o Matrix.o

p1.o: p1.cpp
	g++ $(FLAGS) -c p1.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(FLAGS) -c Matrix.cpp

doc:
	doxygen

clean:
	rm -f p1
	rm -f *.o
	rm -rf doc