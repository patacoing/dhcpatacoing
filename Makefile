BIN=bin
OBJECTS=objects
SRC=src
INCLUDE=$(SRC)/include
CC=gcc
CFLAGS=-Wall 

OBJECTS_FILES=mac_address.o sockets.o discover.o messages.o
OBJS=$(addprefix $(OBJECTS)/, $(OBJECTS_FILES))

all: $(BIN)/main
debug: CFLAGS += -g -DDEBUG
debug: all

$(BIN)/main: $(SRC)/main.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS)/%.o: $(SRC)/%.c $(INCLUDE)/*
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)/*.o $(BIN)/*
