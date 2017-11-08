
all: main.o Currency.o
	g++ -o main.cpp	

Currency.o: Currency.cpp
	g++ -std=c++11 -c Currency.cpp
	

main.o: main.cpp
	g++ -o main.cpp -std=c++11

clear: 
	rm -f *.o
