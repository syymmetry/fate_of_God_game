CC = gcc
CFLASS = -Wall -Wextra -I./src/engine -I./src/game
LDFLAGS = -lSDL2 -lSDL2_image 

SRCS = SRCS = main.c src/engine/core.c src/engine/render.c
OBJS = $(SRCS:.c=.o)

all: game

game: $(OBJS)
	$(CC) -o game $(OBJS) $(LDFLAGS)

clean:
	rm -f game $(OBJS)