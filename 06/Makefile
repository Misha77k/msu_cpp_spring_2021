CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: MyFormat_test.o
	$(CC) $(FLAGS) MyFormat_test.o -o MyFormat

MyFormat_test.o:MyFormat_test.cpp
	$(CC) $(FLAGS) MyFormat_test.cpp -c

test: MyFormat_test.o
	$(CC) $(FLAGS) MyFormat_test.o -o test
	./test

clean:
	rm -f *.o MyFormat_test
