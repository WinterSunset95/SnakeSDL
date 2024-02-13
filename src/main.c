#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "structs.h"
#include "init.h"
#include "menu/menu.h"
#include "game/game.h"

int main(int argc, char *argv[]) {

	App app;
	int window = MENU_WINDOW;

	initSdl(&app);

	while(1) {
		prepareScene(&app);
		handleInput(&app);
		if(window == MENU_WINDOW) {
			prepareMenu(&app);
		} else if(window == SNAKE_WINDOW) {
		} else if(window == GAME_OVER_WINDOW) {
		}
		presentScene(&app);
		SDL_Delay(100);
	}

	closeSdl(&app);
	return 0;

}
