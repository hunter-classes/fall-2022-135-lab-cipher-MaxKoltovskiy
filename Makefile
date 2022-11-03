OBJECTS = funcs.o caesar.o vigenere.o decrypt.o solve.o
CXXFLAGS=--coverage -g -O0


main: main.o $(OBJECTS)
	g++ -o main --coverage -g -O0 main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -o tests --coverage -g -O0 tests.o $(OBJECTS)
	./tests
	gcovr 2> /dev/null > /dev/null
	gcovr -e 'doctest.h' --html-details cipher.html 

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
	rm -f main.o tests.o test-ascii.o solve.o $(OBJECTS) *gcda *html *gcno
