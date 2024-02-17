#include "../structs.h"
#include "../init.h"

int handleInput(int window, Snake snake[]) {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return -1;
		} else if(event.type == SDL_KEYDOWN) {
			if (window == MENU_WINDOW) {
				return SNAKE_WINDOW;
			} else if(window == GAME_OVER_WINDOW) {
				return -1;
			} else if(window == SNAKE_WINDOW) {
				switch(event.key.keysym.sym) {
					case SDLK_UP:
						snake[0].dir = snake[0].dir != DOWN ? UP : snake[0].dir;
						break;
					case SDLK_DOWN:
						snake[0].dir = snake[0].dir != UP ? DOWN : snake[0].dir;
						break;
					case SDLK_LEFT:
						snake[0].dir = snake[0].dir != RIGHT ? LEFT : snake[0].dir;
						break;
					case SDLK_RIGHT:
						snake[0].dir = snake[0].dir != LEFT ? RIGHT : snake[0].dir;
						break;
					case SDLK_ESCAPE:
						return MENU_WINDOW;
						break;
				}
			}
		}
	}

	return window;
}
