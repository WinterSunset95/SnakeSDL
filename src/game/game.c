#include "../structs.h"
#include "../init.h"

void handleInput(App *app, int *window, Snake *snake) {

	SDL_Event event;
	while(SDL_PollEvent(&event)) {

		if(event.type == SDL_KEYDOWN) {
			if (*window == MENU_WINDOW) {
				*window = SNAKE_WINDOW;
				break;
			} else if(*window == GAME_OVER_WINDOW) {
				closeSdl(app);
				return;
				break;
			} else if(*window == SNAKE_WINDOW) {
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
						*window = MENU_WINDOW;
						break;
				}
			}
		}

		if (event.type == SDL_QUIT) {
			closeSdl(app);
			break;
		}

	}
}
