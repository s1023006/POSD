hw5: maintest.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 maintest.o -lgtest
else
	g++ -o hw5 maintest.o -lgtest -lpthread
endif
maintest.o: maintest.cpp utParser.h term.h variable.h atom.h number.h struct.h list.h scanner.h parser.h global.h
	g++ -std=gnu++0x -c maintest.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw5
endif
stat:
	wc *.h *.cpp