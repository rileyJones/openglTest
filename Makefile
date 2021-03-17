.SUFFIXES:
.SUFFIXES: .c .o

CC = g++
CFLAGS = 
OBJECTS = glad.o main.o init.o
PNAME = testGL
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
