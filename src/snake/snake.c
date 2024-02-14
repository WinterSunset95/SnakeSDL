#include "../structs.h"
#include "../init.h"
#include "../assets/apple.xpm"
#include "../helpers/chars.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

void prepareSnake(App *app, Snake *snake, Snake *apple, int *window, int *score) {

	// Check for collisions
	// Snake head with itself
	for (int i=4; i<GRID_SIZE; i++) {
		if (!snake[i].render) {
			break;
		}
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			*window = GAME_OVER_WINDOW;
			return;
		}
	}
	
	// Snake head with apple
	if (snake[0].x == apple->x && snake[0].y == apple->y) {
		// Move apple to random location
		apple->x = rand() % GRID_X;
		apple->y = rand() % GRID_Y;

		// Increase score
		*score += 10;

		for (int i=0; i<GRID_SIZE; i++) {
			if (!snake[i].render) {
				snake[i].render = 1;
				break;
			}
		}
	}
	
	// Snake movement
	// Replace snake[n] with snake[n-1]
	for (int i=GRID_SIZE; i>0; i--) {
		if (snake[i].render) {
			snake[i].x = snake[i-1].x;
			snake[i].y = snake[i-1].y;
			snake[i].dir = snake[i-1].dir;
		}
	}
	
	// Move snake head
	switch(snake[0].dir) {
		case UP:
			snake[0].y = snake[0].y == 0 ? GRID_Y-1 : snake[0].y-1;
			break;
		case DOWN:
			snake[0].y = snake[0].y == GRID_Y-1 ? 0 : snake[0].y+1;
			break;
		case LEFT:
			snake[0].x = snake[0].x == 0 ? GRID_X-1 : snake[0].x-1;
			break;
		case RIGHT:
			snake[0].x = snake[0].x == GRID_X-1 ? 0 : snake[0].x+1;
			break;
	}

	// Draw the snake
	for (int i=0; i<GRID_SIZE; i++) {
		if (snake[i].render) {
			SDL_SetRenderDrawColor(app->renderer, 0, 255, 0, 255);
			SDL_Rect rect = {snake[i].x*CELL_SIZE, snake[i].y*CELL_SIZE, CELL_SIZE, CELL_SIZE};
			SDL_RenderFillRect(app->renderer, &rect);
		}
	}

	// Draw the apple
	SDL_Surface *appleSurface = IMG_ReadXPMFromArray(apple_xpm);
	//SDL_Surface *appleSurface = SDL_LoadBMP("src/assets/apple.bmp");
	if(apple == NULL) {
		SDL_Log("Unable to load apple.bmp: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	SDL_Texture *appleTexture = SDL_CreateTextureFromSurface(app->renderer, appleSurface);
	if(appleTexture == NULL) {
		SDL_Log("Unable to create texture: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	SDL_Rect appleRect = {apple->x*CELL_SIZE, apple->y*CELL_SIZE, CELL_SIZE, CELL_SIZE};
	SDL_RenderCopy(app->renderer, appleTexture, NULL, &appleRect);

	SDL_FreeSurface(appleSurface);
	SDL_DestroyTexture(appleTexture);

}

void prepareScoreScreen(App *app, int *score) {
	char scoreStr[10];
	sprintf(scoreStr, "%d", *score);
	printString(app, "Score", SCORE_X+CELL_SIZE, CELL_SIZE, 1);
	printString(app, scoreStr, SCORE_X+CELL_SIZE, CELL_SIZE*4, 2);
}
