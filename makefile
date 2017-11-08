
all: teste

teste: main.o Currency.o


Currency.o: Currency.cpp
	g++ -std=c++11 -c Currency.cpp
	

main.o: main.cpp
	g++ main.cpp -std=c++11 -o main.o

clear: 
	rm -f *.o
