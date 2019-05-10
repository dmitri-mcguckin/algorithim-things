CC=cc
FLAGS=-lm
HEAD=*.h
SRC=*.c
EXE=array

all: $(HEAD)
	$(CC) $(SRC) $(FLAGS) -o $(EXE)

e: execute
execute: all
	./$(EXE)

c: clean
clean:
	rm -rf *.o $(EXE)
