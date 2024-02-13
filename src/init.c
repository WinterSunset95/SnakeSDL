#include "structs.h"
#include "init.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

void initSdl(App *app) {

	if(IMG_Init(IMG_INIT_JPG) == 0) {
		SDL_Log("IMG_Init failed: %s\n", IMG_GetError());
		closeSdl(app);
		exit(1);
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	app->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(app->window == NULL) {
		SDL_Log("Window failed to initialize: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(app->renderer == NULL) {
		SDL_Log("Renderer failed to initialize: %s\n", SDL_GetError());
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

void prepareScene(App *app) {
	SDL_SetRenderDrawColor(app->renderer, 10, 10, 10, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App *app) {
	SDL_RenderPresent(app->renderer);
}
