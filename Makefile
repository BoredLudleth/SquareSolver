all: solver test

solver: main.o SquareSolver.o
	g++ .\main.o .\SquareSolver.o -o solver

main.o: main.cpp
	g++ -c .\main.cpp -o main.o

SquareSolver.o: SquareSolver.cpp
	g++ -c .\SquareSolver.cpp -o SquareSolver.o

test: Tests.o SquareSolver.o
	g++ .\Tests.o .\SquareSolver.o -o test

Tests.o: Tests.cpp
	g++ -c .\Tests.cpp -o Tests.o

run_tests: test
	.\test

run_solver: solver
	.\solver
