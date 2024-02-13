#include "../structs.h"
#include "../init.h"
#include <SDL2/SDL_events.h>

void handleInput(App *app) {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			closeSdl(app);
			break;
		}
	}
}
