SRC = $(wildcard *.cpp)
FLAG = g++ -std=c++17 -Wall -Wpedantic

EXE = lab_
all: test

program: $(SRC)
	$(FLAG) -o $(EXE) $(SRC)

test: program
	./$(EXE)
