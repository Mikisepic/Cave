CC ?= clang
CFLAGS ?= -fsanitize=integer -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow
LDLIBS ?= -lm

cave_main: cave_main.c cave_header.h cave_mobs.c cave_loot.c
	$(CC) $(CFLAGS) -o cave_main cave_main.c $(LDLIBS)