CC=g++
FLAGS=-lm
HEAD=**/*.h
SRC=*.cpp **/*.cpp
EXE=executable

all: $(HEAD)
	$(CC) $(SRC) $(FLAGS) -o $(EXE)

e: execute
execute: all
	./$(EXE)

c: clean
clean:
	rm -rf *.o $(EXE)
