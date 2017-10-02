hw2: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp Number.h atom.h utTerm.h
	g++ -std=c++11 -c mainTerm.cpp
	
clean:
	rm -f *.o hw2
stat:
	wc *.h *.cpp