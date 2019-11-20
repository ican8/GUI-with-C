# change application name here (executable output name)
TARGET=Sudoku

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe


GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=main.o sudoku_generator.o sudoku_solver.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o
	
sudoku_generator.o: src/sudoku_generator.c
	$(CC) -c $(CCFLAGS) src/sudoku_generator.c $(GTKLIB) -o sudoku_generator.o

sudoku_solver.o: src/sudoku_solver.c
	$(CC) -c $(CCFLAGS) src/sudoku_solver.c $(GTKLIB) -o sudoku_solver.o	
    
clean:
	rm -f *.o $(TARGET)
