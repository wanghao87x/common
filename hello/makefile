
CXX = g++
CFLAGS = -Wall -g

.PHONY: all clean

all: hello

hello: main.cpp
	$(CXX) $(CFLAGS) -o $@ $^
clean:
	rm -f hello
