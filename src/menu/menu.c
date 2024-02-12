#include "../structs.h"
#include <SDL2/SDL_messagebox.h>

void drawMenu(App *app) {
	SDL_MessageBoxButtonData buttons[1] = {
		{0, 0, "OK"}
	};
	SDL_MessageBoxColorScheme colorScheme = {
		{ { 255, 0, 0 }, { 0, 255, 0 }, { 255, 255, 0 }, { 0, 0, 255 }, { 255, 255, 255 } }
	};

	SDL_MessageBoxData data;
	data.window = app->window;
	data.title = "Snake";
	data.message = "Welcome to Snake!";
	data.numbuttons = 1;
	data.buttons = buttons;
	data.colorScheme = &colorScheme;

	SDL_ShowMessageBox(&data, NULL);
}
