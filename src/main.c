#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "structs.h"
#include "init.h"
#include "menu/menu.h"

int main(int argc, char *argv[]) {

	App app;
	int window = MENU_WINDOW;

	initSdl(&app);

	while(1) {

		SDL_Event event;
		if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			} else if (event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						break;
					default:
						break;
				}
			}
		}

		SDL_Delay(100);
		drawMenu(&app);
		drawWindow(&app);

	}

	closeSdl(&app);
	return 0;

}
