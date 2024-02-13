#include "../structs.h"
#include "../init.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

void prepareMenu(App *app) {
	const char *menu = "src/assets/menu.bmp";

	SDL_Surface *surface = SDL_LoadBMP(menu);
	if(surface == NULL) {
		SDL_Log("Unable to load menu.bmp: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
	if(texture == NULL) {
		SDL_Log("Unable to create texture from surface: %s\n", SDL_GetError());
		closeSdl(app);
		exit(1);
	}

	SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	SDL_RenderCopy(app->renderer, texture, NULL, &rect);
}
