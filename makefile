hw3: maintest.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 maintest.o -lgtest
else
	g++ -o hw4 maintest.o -lgtest -lpthread
endif
maintest.o: maintest.cpp utList.h term.h variable.h atom.h number.h struct.h list.h
	g++ -std=gnu++0x -c maintest.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif
stat:
	wc *.h *.cpp