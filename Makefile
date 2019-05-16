CC=cc
FLAGS=-lm
HEAD=*.h
SRC=*.c
EXE=cs-350
INPUT=demo_1.txt

all: $(HEAD)
	$(CC) $(SRC) $(FLAGS) -o $(EXE)

s: single
single:
	$(CC) smartSearch6McGuckin.c $(FLAGS) -g

e: execute
execute: all
	./$(EXE) < $(INPUT)

c: clean
clean:
	rm -rf *.o $(EXE) a.out
