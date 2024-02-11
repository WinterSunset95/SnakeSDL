#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include "structs.h"

void checkCollision(App *app, struct cell *snake, struct cell *food) {
	// Check if snake eats food
	if (snake[0].x == food->x && snake[0].y == food->y) {
		food->x = rand() % GRID_WIDTH;
		food->y = rand() % GRID_HEIGHT;

		for (int i = 0; i < GRID_SIZE; i++) {
			if (!snake[i].isFilled) {
				snake[i].x = snake[i - 1].x;
				snake[i].y = snake[i - 1].y;
				snake[i].isFilled = 1;
				break;
			}
		}
	}

	// Check if snake collides with itself
	for (int i = 1; i < GRID_SIZE; i++) {

		if (!snake[i].isFilled) {
			break;
		}

		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			SDL_Delay(10000);
			SDL_DestroyWindow(app->window);
			SDL_Quit();
			break;
			exit(1);
		}
	}
}

void handleInput(SDL_Event *e, struct cell *snake) {
	if (e->type == SDL_KEYDOWN) {
		switch (e->key.keysym.sym) {
			case SDLK_UP:
				if (snake[0].dir != DOWN) {
					snake[0].dir = UP;
				}
				break;
			case SDLK_DOWN:
				if (snake[0].dir != UP) {
					snake[0].dir = DOWN;
				}
				break;
			case SDLK_LEFT:
				if (snake[0].dir != RIGHT) {
					snake[0].dir = LEFT;
				}
				break;
			case SDLK_RIGHT:
				if (snake[0].dir != LEFT) {
					snake[0].dir = RIGHT;
				}
				break;
		}
	}
}

void updateSnake(struct cell snake[]) {
	for (int i = GRID_SIZE - 1; i > 0; i--) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
}

void moveSnake(struct cell snake[]) {
	switch (snake[0].dir) {
		case UP:
			snake[0].y == 0 ? snake[0].y = GRID_HEIGHT - 1 : snake[0].y--;
			break;
		case DOWN:
			snake[0].y == GRID_HEIGHT - 1 ? snake[0].y = 0 : snake[0].y++;
			break;
		case LEFT:
			snake[0].x == 0 ? snake[0].x = GRID_WIDTH - 1 : snake[0].x--;
			break;
		case RIGHT:
			snake[0].x == GRID_WIDTH - 1 ? snake[0].x = 0 : snake[0].x++;
			break;
	}
}
