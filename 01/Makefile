CC=g++ -std=c++17 
FLAGS=-Wall -Werror -fsanitize=address -Wextra

all: task1.o task1_main.o
	$(CC) $(FLAGS) task1.o task1_main.o -o task1

task1.o: task1.cpp
	$(CC) $(FLAGS) task1.cpp -c

task1_main.o: task1_main.cpp
	$(CC) $(FLAGS) task1_main.cpp -c

test: task1.o task1_main.o
	$(CC) $(FLAGS) task1.o task1_main.o -o test
	./test

clean:
	rm -f *.o task1_main 	

