#include "Render_handler.h"
#include "Box.h"

void render_handler(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);
	Box(renderer, 1, 200, 100);
	Box(renderer, 2, 0, 0);
	
	
	SDL_RenderPresent(renderer);
}
