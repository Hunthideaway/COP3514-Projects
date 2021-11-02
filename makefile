OBJS	= summer_camp.o request.o readline.o
SOURCE	= summer_camp.c request.c readline.c
HEADER	= request.h readline.h
OUT	= summer_camp
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

summer_camp.o: summer_camp.c
	$(CC) $(FLAGS) summer_camp.c -std=c99

request.o: request.c
	$(CC) $(FLAGS) request.c -std=c99

readline.o: readline.c
	$(CC) $(FLAGS) readline.c -std=c99


clean:
	rm -f $(OBJS) $(OUT)