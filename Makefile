game: cards.o main.o
	g++ cards.o main.o -o game

main.o: main.cpp cards.h
	g++ main.cpp -c

cards.o: cards.cpp cards.h
	g++ cards.cpp -c

testcards.o: testcards.cpp testcards.h
	g++ testcards.cpp -c

test: testcards.o cards.o
	g++ testcards.o cards.o -o test
