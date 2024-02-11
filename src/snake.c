#include "structs.h"

void drawSnake(App *app, struct cell snake[], struct cell food) {
	SDL_SetRenderDrawColor(app->renderer, 0, 255, 0, 255);
	for (int i = 0; i < GRID_SIZE; i++) {
		if (!snake[i].isFilled) {
			break;
		}
		SDL_Rect rect = {snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
		SDL_RenderFillRect(app->renderer, &rect);
	}
	SDL_SetRenderDrawColor(app->renderer, 255, 0, 0, 255);
	SDL_Rect foodu = {food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
	SDL_RenderFillRect(app->renderer, &foodu);
	SDL_RenderPresent(app->renderer);
}
