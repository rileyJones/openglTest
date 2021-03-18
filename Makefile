.SUFFIXES:
.SUFFIXES: .c .o

CC = g++
CFLAGS = -pedantic -Wall 
OBJECTS = glad.o blocks.o init.o createProgram.o
PNAME = blocks
RM = rm -f
DEBUG = ddd
MEMTEST = valgrind
IDIR = include
LIBS = -lglfw3 -ldl -pthread


$(PNAME): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -I$(IDIR)

run: $(PNAME)
	./$(PNAME)

clean:
	$(RM) *.o
	$(RM) $(PNAME)

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS) -I$(IDIR)

glad.o: 
	$(CC) -c -o $@ include/glad/glad.c $(CFLAGS) $(LIBS) -I$(IDIR)


main.o: main.c common.h
init.o: init.c common.h
blocks.o: blocks.c common.h
createProgram.o: createProgram.c common.h
