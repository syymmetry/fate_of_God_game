CC = gcc
CFLAGS = -Wall -Wextra -I./src/engine -I./src/game
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SRCS = main.c src/engine/core.c src/engine/render.c
OBJS = $(SRCS:.c=.o)

all: game

game: $(OBJS)
	$(CC) -o game $(OBJS) $(LDFLAGS)

clean:
	rm -f game $(OBJS)