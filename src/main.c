#include "structs.h"
#include "init.h"
#include "menu/menu.h"
#include "game/game.h"
#include "snake/snake.h"
#include "exit/exit.h"

int main(int argc, char *argv[]) {

	App app;
	Snake snake[GRID_SIZE];
	Snake apple;
	int window = MENU_WINDOW;
	int score = 0;

	// Initialize apple
	apple.x = 5;
	apple.y = 6;
	apple.render = 1;

	// Initialize snake
	for (int i=0; i<GRID_SIZE; i++) {
		snake[i].x = 0;
		snake[i].y = 0;
		snake[i].render = 0;
	}
	
	snake[0].x = 0;
	snake[0].y = 0;
	snake[0].dir = RIGHT;
	snake[0].render = 1;
	snake[1].x = 1;
	snake[1].y = 0;
	snake[1].dir = RIGHT;
	snake[1].render = 1;

	initSdl(&app);

	while(1) {
		prepareScene(&app);
		handleInput(&app, &window, snake);
		if(window == MENU_WINDOW) {
			prepareMenu(&app);
		} else if(window == SNAKE_WINDOW) {
			prepareSnake(&app, snake, &apple, &window, &score);
			prepareScoreScreen(&app, &score);
		} else if(window == GAME_OVER_WINDOW) {
			prepareExitScreen(&app);
		}
		presentScene(&app);
		SDL_Delay(100);
	}

	closeSdl(&app);
	return 0;

}
