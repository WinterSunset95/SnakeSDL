#include <SDL2/SDL.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

struct cell {
	int x;
	int y;
};

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} App;
