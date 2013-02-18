driver: driver.cpp dict.o
	g++ -Wall -g -o driver driver.cpp dict.o

dict.o: dict.cpp dict.h
	g++ -Wall -g -c dict.cpp

clean:
	rm -f driver dict.o
