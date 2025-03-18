CC = gcc
CFLASS = -Wall -Wextra -I./src/engine -I./src/game
LDFLAGS = -lSDL2

SRCS = main.c src/engine/core.core
OBJS = $(SRCS:.c=.o)

all: game

game: $(OBJS)
	$(CC) -o game $(OBJS) $(LDFLAGS)

clean:
	rm -f game $(OBJS)