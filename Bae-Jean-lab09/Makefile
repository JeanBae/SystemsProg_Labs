all: stat

stat: stat.o
	g++ -Wall -g -lncurses -o stat stat.o

stat.o: stat.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -lncurses -c stat.cpp

clean:
	rm -f stat
	rm -f stat.o