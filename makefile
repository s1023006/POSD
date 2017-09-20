INC_DIR = include

all: hw1

hw1: main.o Sort.o Shapes.o Media.o
ifeq (${OS}, Windows_NT)
	g++ -o hw1 main.o Sort.o Shapes.o Media.o -lgtest
else
	g++ -o hw1 main.o Sort.o Shapes.o Media.o -lgtest -lpthread
endif
	
main.o: main.cpp utSort.h
	g++ -std=gnu++0x -c main.cpp

Sort.o: $(INC_DIR)/Sort.h Sort.cpp
	g++ -std=gnu++0x -c Sort.cpp -o Sort.o

Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
	g++ -std=gnu++0x -c Shapes.cpp -o Shapes.o

Media.o: $(INC_DIR)/Media.h Media.cpp
	g++ -std=gnu++0x -c Media.cpp -o Media.o