CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: MyParser.o MyParser_test.o
	$(CC) $(FLAGS) MyParser.o MyParser_test.o -o MyParser

MyParser.o: MyParser.cpp
	$(CC) $(FLAGS) MyParser.cpp -c

MyParser_test.o: MyParser_test.cpp
	$(CC) $(FLAGS) MyParser_test.cpp -c

test: MyParser.o MyParser_test.o
	$(CC) $(FLAGS) MyParser.o MyParser_test.o -o test
	./test

clean:
	rm -f *.o MyParser_test

