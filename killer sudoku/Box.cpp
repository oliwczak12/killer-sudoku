#include "Box.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <sstream> 
#include <string>
#include <iostream>
void Box(SDL_Renderer* renderer, TTF_Font* Sans, char num, int x, int y)
{
    
    SDL_Color black = { 0, 0, 0 };
    std::stringstream strm;
    strm << (int)num;
    SDL_Surface* surfaceMessage =
        TTF_RenderText_Solid(Sans, strm.str().c_str(), black);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rectangle;

    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = 100;
    rectangle.h = 100;

    SDL_RenderFillRect(renderer, &rectangle);


    SDL_RenderCopy(renderer, Message, NULL, &rectangle);

   
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);

}
