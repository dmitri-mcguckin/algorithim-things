CC=cc
FLAGS=-lm
HEAD=*.h
SRC=*.cpp
EXE=executable

a: all
all: $(HEAD)
	$(CC) $(SRC) $(FLAGS) -o $(EXE)

e: execute
execute: all
	./$(EXE)

c: clean
clean:
	rm -rf *.o *.out $(EXE)
