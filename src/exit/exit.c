#include "../structs.h"
#include "../init.h"
#include "../assets/exit.xpm"
#include "exit.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

void prepareExitScreen(App *app) {
	SDL_Surface *surface = IMG_ReadXPMFromArray(exit_xpm);
	if (surface == NULL) {
		SDL_Log("Unable to load exit.bmp: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
	if (texture == NULL) {
		SDL_Log("Unable to create texture: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	SDL_RenderCopy(app->renderer, texture, NULL, &rect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

