#include "../structs.h"
#include "chars.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <string.h>

char *(*characters[]) = {
	zero_xpm,
	one_xpm,
	two_xpm,
	three_xpm,
	four_xpm,
	five_xpm,
	six_xpm,
	seven_xpm,
	eight_xpm,
	nine_xpm,
	A_xpm,
	B_xpm,
	C_xpm,
	D_xpm,
	E_xpm,
	F_xpm,
	G_xpm,
	H_xpm,
	I_xpm,
	J_xpm,
	K_xpm,
	L_xpm,
	M_xpm,
	N_xpm,
	O_xpm,
	P_xpm,
	Q_xpm,
	R_xpm,
	S_xpm,
	T_xpm,
	U_xpm,
	V_xpm,
	W_xpm,
	X_xpm,
	Y_xpm,
	Z_xpm
};

int printString(App *app, char text[], int x, int y, int size) {
	for (int i=0; i<strlen(text); i++) {
		int index;
		SDL_Rect currChar = {x, y, CELL_SIZE*size, CELL_SIZE*size};

		// If the character is a number, subtract 48 to get the correct index
		// If the character is an uppercase letter, subtract 55 to get the correct index
		// If the character is a lowercase letter, subtract 87 to get the correct index
		if (text[i] >= 48 && text[i] <= 57) {
			index = text[i] - 48;
		} else if (text[i] >= 65 && text[i] <= 90) {
			index = text[i] - 55;
		} else if (text[i] >= 97 && text[i] <= 122) {
			index = text[i] - 87;
		} else {
			return -1;
		}

		SDL_Surface *surface = IMG_ReadXPMFromArray(characters[index]);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(app->renderer, surface);
		SDL_RenderCopy(app->renderer, texture, NULL, &currChar);

		x += CELL_SIZE*size + 5;

		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

	return 0;
}
