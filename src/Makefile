CC=g++
FLAGS=-Wall -Werror -Wextra -std=c++17
GTEST=-lgtest -pthread -lgtest_main 
MATRIX_C=s21*.cc
MATRIX_H=s21*.h
MATRIX_O=s21*.o
TESTS=tests/test.cc

all: clean test

s21_matrix_oop.a:
	$(CC) $(MATRIX_C)  -c
	ar rc s21_matrix_oop.a $(MATRIX_O)
	ranlib s21_matrix_oop.a

style:
	clang-format -style=google -i $(TESTS).c $(TESTS).h $(MATRIX_C) $(MATRIX_H)

test: clean s21_matrix_oop.a
	$(CC) $(FLAGS) $(TESTS) s21_matrix_oop.a -o test $(GTEST)
	./test

mem: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --tool=memcheck ./test
else
	leaks --atExit -- ./test
endif

clean:
	rm -rf *.o *.a test