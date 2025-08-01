CC = clang
AC = nasm

#BINDIR = bin
#SRCDIR = src
#INCDIR = include
#BUILDDIR = build

BIN = app

CFILES = $(wildcard *c)
ASFILES = $(wildcard *asm)
OUT = $(patsubst %.asm,%.o,$(ASFILES))
AFLAGS = -f elf64
CFLAGS = -Wall -Werror -Wextra -pedantic -O3 -g -no-pie
LIB = `pkg-config --cflags --libs gtk+-3.0`

all: $(OUT) $(BIN)

$(OUT): %.o : %.asm
	$(AC) $(AFLAGS) $< -o $@

$(BIN): $(CFILES) $(OUT)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(BIN)

#dir:
#	mkdir -pv $(BINDIR) $(SRCDIR) $(INCDIR) $(BUILDIR)

run:
	./app

clean:
	rm -rf app *.o
