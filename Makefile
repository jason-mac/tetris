#thank you to my prof anne laveergne for making show we knew makefiles lol

CC = gcc

SRC = main.c $(wildcard lib/*.c)

OUT = program

INCLUDE = -I/opt/homebrew/include -I./include
LIB = -L/opt/homebrew/lib -lraylib

FRAMEWORKS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

CFLAGS = $(INCLUDE)

LDFLAGS = $(FRAMEWORKS) $(LIB)

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
