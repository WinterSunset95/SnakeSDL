#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "structs.h"
#include "init.h"

App app;

struct cell snake[];

void placeholderRender() {
	SDL_RenderClear(app.renderer);
	SDL_RenderPresent(app.renderer);
}

int main(int argc, char *argv[]) {
	initSdl();

	app.window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
	if (!app.window) {
		printf("Unable to create SDL window\n");
		SDL_Quit();
		exit(1);
	}

	app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!app.renderer) {
		printf("Unable to create SDL renderer\n");
		SDL_DestroyWindow(app.window);
		SDL_Quit();
		exit(1);
	}

	SDL_SetRenderDrawColor(app.renderer, 100, 100, 100, 255);
	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			} else {
				placeholderRender();
			}
		}
	}

	return 0;
}
