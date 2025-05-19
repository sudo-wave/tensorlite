IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = vector.h random.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o vector.o random.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
