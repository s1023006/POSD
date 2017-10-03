hw2: mainTerm.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o -lgtest
else
	g++ -o hw2 mainTerm.o -lgtest -lpthread
endif
mainTerm.o: mainTerm.cpp match.o utTerm.h
	g++ -std=gnu++0x -c mainTerm.cpp

match.o: match.cpp variable.h atom.h number.h predicate.h
	g++ -std=gnu++0x -c match.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
stat:
	wc *.h *.cpp