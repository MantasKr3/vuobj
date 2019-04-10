CXX=c++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

main: open.o
	g++ -std=c++11 -o functions functions.cpp open.o
open:
	g++ -std=c++11 -c apdorojimas.cpp
clean:
	rm *.o functions