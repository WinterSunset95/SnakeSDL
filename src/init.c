#include <SDL2/SDL.h>
#include <stdio.h>
#include "structs.h"
#include "init.h"


void initSdl(App *app) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("unable to initialize sdl\n");
		exit(1);
	}

	app->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!app->window) {
		printf("Unable to create SDL window\n");
		SDL_Quit();
		exit(1);
	}

	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!app->renderer) {
		printf("Unable to create SDL renderer\n");
		SDL_DestroyWindow(app->window);
		SDL_Quit();
		exit(1);
	}

}

void drawBox(App *app) {
	SDL_SetRenderDrawColor(app->renderer, 100, 100, 100, 255);
	SDL_RenderClear(app->renderer);
	SDL_RenderPresent(app->renderer);
}
