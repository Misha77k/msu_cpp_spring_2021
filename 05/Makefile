CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: Serializer_test.o
	$(CC) $(FLAGS) Serializer_test.o -o Serializer

Serializer_test.o:Serializer_test.cpp
	$(CC) $(FLAGS) Serializer_test.cpp -c

test: Serializer_test.o
	$(CC) $(FLAGS) Serializer_test.o -o test
	./test

clean:
	rm -f *.o Serializer_test

