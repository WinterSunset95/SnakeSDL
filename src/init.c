#include "structs.h"
#include "init.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

void initSdl(App *app) {

	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL failed to initialize: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	app->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(app->window == NULL) {
		printf("Window failed to initialize: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(app->renderer == NULL) {
		printf("Renderer failed to initialize: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

}

void closeSdl(App *app) {
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
	exit(1);
}

void drawWindow(App *app) {
	SDL_SetRenderDrawColor(app->renderer, 10, 10, 10, 255);
	SDL_RenderClear(app->renderer);
	SDL_RenderPresent(app->renderer);
}
