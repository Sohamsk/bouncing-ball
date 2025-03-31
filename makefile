CC = g++
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt

game.out: main.cpp
	$(CC) main.cpp $(CFLAGS) -o game.out

.phony: clean
clean:
	rm -rf game.out

