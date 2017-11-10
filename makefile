TARGET = prog
CC = g++
CFLAGS = -g -Wall -std=c++11

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

default: $(TARGET)
all: default

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	-rm -f $(TARGET)
	-rm -f *.o
