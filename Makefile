.PHONY: run

run: main.o
	./main

main.o:
	gcc -o main main.cpp CApp.cpp Turtle.cpp -lSDL2 -lm -lstdc++