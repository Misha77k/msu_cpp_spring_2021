CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: Matrix.o Matrix_test.o
	$(CC) $(FLAGS) Matrix.o Matrix_test.o -o Matrix

Matrix.o: Matrix.cpp
	$(CC) $(FLAGS) Matrix.cpp -c

Matrix_test.o: Matrix_test.cpp
	$(CC) $(FLAGS) Matrix_test.cpp -c

test: Matrix.o Matrix_test.o
	$(CC) $(FLAGS) Matrix.o Matrix_test.o -o test
	./test

clean:
	rm -f *.o Matrix_test
