#include "Render_handler.h"
#include "Box.h"
#include "vector2d.h"
#include <iostream>
#include <vector>
#include "SDL_ttf.h"
#include "SDL_gfx"


double distanceBetweenTwoPoints(double x, double y, double a, double b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

void lines(SDL_Renderer* renderer,int x,int y) {
	int offset_i = 0;
	int offset_j = 0;
	int default_value = 0;
	double min = 0;
	double best_line = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0) offset_i += 10;
		if (i % 3 != 0 && i != 0) {
			offset_i += 2;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0 && j != 0) offset_j += 10;
			else if (j % 3 != 0)offset_j += 2;
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			if (min = distanceBetweenTwoPoints((offset_j + 10 + 100 * j) + 50, (offset_i + 10 + 100 * i) + 50, x, y)) {
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			}

			SDL_RenderDrawLine(renderer, (offset_j + 10 + 100 * j)+50, (offset_i + 10 + 100 * i)+50, x, y);
		}
		offset_j = 0;

	}

}

void mouse_pos(SDL_Renderer* renderer) {
	int x, y;
	SDL_PumpEvents();  // make sure we have the latest mouse state.

	SDL_GetMouseState(&x, &y);
	lines(renderer,x,y);
}

 void grid(SDL_Renderer* renderer, TTF_Font* Sans) {
	int offset_i = 0;
	int offset_j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0) offset_i += 10;
		 if (i % 3 != 0 && i != 0) {
				offset_i +=2;
		 } 
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0 && j != 0) offset_j += 10;
			else if (j % 3 != 0)offset_j += 2;

			Box(renderer,Sans, j, offset_j + 10 + 100 * j, offset_i + 10 + 100 * i);
		}

		offset_j = 0;
	}
}

void render_handler(SDL_Renderer* renderer, TTF_Font* Sans)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);


	grid(renderer,Sans);

	mouse_pos(renderer);
	SDL_RenderPresent(renderer);
}
