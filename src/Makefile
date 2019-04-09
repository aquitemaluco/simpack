CC := gcc
CFLAGS := -c -Wall
INCLUDES := -I../include
SOURCES := simplepack.c
OUT := ../bin/simplepack

all: simplepack

simplepack:
	@echo "Generating ../bin/neanderc"
	$(CC) $(INCLUDES) simplepack.c  -o $(OUT)

clean:
	rm -f $(OBJECTS) $(NEANDERLIB) $(OUT)

