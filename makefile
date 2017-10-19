hw3: maintest.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 maintest.o -lgtest
else
	g++ -o hw3 maintest.o -lgtest -lpthread
endif
maintest.o: maintest.cpp utVariable.h utStruct.h term.h variable.h atom.h number.h struct.h
	g++ -std=gnu++0x -c maintest.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif
stat:
	wc *.h *.cpp