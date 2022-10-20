OBJECTS = funcs.o caesar.o vigenere.o decrypt.o

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.cpp

solve.o: solve.cpp solve.h

decrypt.o: decrypt.cpp decrypt.h

vigenere.o: vigenere.cpp vigenere.h

caesar.o: caesar.cpp caesar.h

test-ascii.o: test-ascii.cpp

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h

clean:
	rm -f main.o tests.o test-ascii.o solve.o $(OBJECTS) 
