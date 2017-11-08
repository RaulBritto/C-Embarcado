
programa: main.cpp
	g++ main.cpp -o main.o -std=c++11

all: main.o
	g++ -o main.cpp	

main.o: main.cpp
	g++ -o main.cpp -std=c++11

clear: 
	rm -f *.o
