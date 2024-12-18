
CC = gcc
CFLAGS = -Wall -g

# C++ 11
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

.PHONY: all clean

all: hello

hello: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
clean:
	rm -f hello
