IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = random.h activation.h linalg.h perceptron.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = random.o activation.o linalg.o perceptron.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
