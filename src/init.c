#include "init.h"
#include <SDL2/SDL.h>
#include <stdio.h>

void initSdl() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("unable to initialize sdl\n");
		exit(1);
	}
}
