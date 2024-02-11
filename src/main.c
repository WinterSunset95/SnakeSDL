#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "structs.h"
#include "init.h"
#include "game.h"
#include "snake.h"

App app;

struct cell snake[GRID_SIZE];
struct cell food = {5,5};

int main(int argc, char *argv[]) {
	initSdl(&app);

	snake[0].x = 2;
	snake[0].y = 2;
	snake[0].dir = RIGHT;
	snake[0].isHead = 1;
	snake[0].isFilled = 1;

	snake[1].x = 1;
	snake[1].y = 2;
	snake[1].dir = RIGHT;
	snake[1].isFilled = 1;

	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			} else {
				handleInput(&e, snake);
			}
		}
		drawBox(&app);
		updateSnake(snake);
		moveSnake(snake);
		checkCollision(&app, snake, &food);
		drawSnake(&app, snake, food);
		SDL_Delay(100);
	}

	return 0;
}
