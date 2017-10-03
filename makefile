hw2: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread

mainTerm.o: mainTerm.cpp match.o utTerm.h
	g++ -std=gnu++0x -c mainTerm.cpp

match.o: match.cpp variable.h atom.h number.h predicate.h
	g++ -std=gnu++0x -c match.cpp
clean:
	rm -f *.o hw2
stat:
	wc *.h *.cpp