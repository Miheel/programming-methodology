all: test

program: main.cpp int_buffer.cpp int_sorted.cpp
	g++ -std=c++17 -Wall -Wpedantic -o lab1 main.cpp int_buffer.cpp int_sorted.cpp

test: program
	./lab1
