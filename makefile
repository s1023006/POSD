hw7: maintest.o struct.o term.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 maintest.o struct.o term.o list.o -lgtest
else
	g++ -o hw7 maintest.o struct.o term.o list.o -lgtest -lpthread
endif
maintest.o: maintest.cpp utIterator.h variable.h atom.h number.h list.h iterator.h
	g++ -std=gnu++0x -c maintest.cpp

struct.o: struct.h struct.cpp
	g++ -std=gnu++0x -c struct.cpp
	
term.o: term.h term.cpp
	g++ -std=gnu++0x -c term.cpp

list.o: list.h list.cpp
	g++ -std=gnu++0x -c list.cpp
	
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw7
endif
stat:
	wc *.h *.cpp