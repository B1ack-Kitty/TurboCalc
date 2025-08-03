CC = clang
AC = nasm

BINDIR = bin
SRCDIR = src
#INCDIR = include
BUILDDIR = build
ASMDIR = asm

BIN = app

CFILES = $(wildcard $(SRCDIR)/*.c)
ASFILES = $(wildcard $(ASMDIR)/*.asm)
OUT = $(patsubst $(ASMDIR)/%.asm,$(BUILDDIR)/%.o,$(ASFILES))
AFLAGS = -f elf64
CFLAGS = -Wall -Werror -Wextra -pedantic -O3 -g -no-pie `pkg-config --cflags gtk+-3.0`
LIB = `pkg-config --libs gtk+-3.0`

all: dir $(BUILDDIR) $(BINDIR)/$(BIN)

$(BUILDDIR)/%.o: $(ASMDIR)/%.asm
	$(info Building -> $<)
	$(AC) $(AFLAGS) $< -o $@

$(BINDIR)/$(BIN): $(CFILES) $(OUT)
	$(info Building -> $<)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose $(BINDIR)/$(BIN)

dir:
	$(info Creating File Tree)
	mkdir -pv $(BINDIR) $(SRCDIR) $(ASMDIR) $(BUILDDIR)

clean:
	$(info Removing All)
	rm -rf $(BINDIR) $(BUILDDIR)
