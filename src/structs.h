#include <SDL2/SDL.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define CELL_SIZE 20
#define GRID_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)
#define GRID_SIZE (GRID_WIDTH * GRID_HEIGHT)

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

struct cell {
	int x;
	int y;
	int dir;
	int isHead;
	int isFilled;
	struct cell *next;
};

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} App;
