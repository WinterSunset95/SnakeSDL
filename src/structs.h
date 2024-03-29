#ifndef STRUCTS_H
#define STRUCTS_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_log.h>
#include <SDL_quit.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <SDL_events.h>
#include <SDL_timer.h>
#include <SDL_keycode.h>
#include <SDL_error.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_quit.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_error.h>
#endif

// For the different windows
#define SNAKE_WINDOW 0
#define MENU_WINDOW 1
#define GAME_OVER_WINDOW 2
// For the screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Snake dimensions
#define CELL_SIZE 20

// The snake window dimensions
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define GRID_X WINDOW_WIDTH / CELL_SIZE
#define GRID_Y WINDOW_HEIGHT / CELL_SIZE
#define GRID_SIZE GRID_X * GRID_Y

// The snake directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// The score window
#define SCORE_X 600
#define SCORE_Y 0
#define SCORE_WIDTH 200
#define SCORE_HEIGHT 600

// The snake structure
typedef struct {
	int x, y;
	int dir;
	int render;
} Snake;

typedef struct {
	SDL_Window *window;
	SDL_Renderer *renderer;
} App;

typedef struct {
	int x, y;
} Food;

#endif
