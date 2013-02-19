driver: driver.cpp dict.o
	g++ -Wall -ansi -O2 -g -o driver driver.cpp dict.o

dict.o: dict.cpp dict.h
	g++ -Wall -ansi -O2 -g -c dict.cpp

clean:
	rm -f driver dict.o
