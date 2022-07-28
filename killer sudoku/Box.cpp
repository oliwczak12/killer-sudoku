#include "Box.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <sstream> 
#include <string>
#include <iostream>
void Box(SDL_Renderer* renderer, char num, int x, int y)
{
    

    if (TTF_Init() < 0) {
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rectangle;

    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = 100;
    rectangle.h = 100;

    SDL_RenderFillRect(renderer, &rectangle);

    SDL_Surface* text;
    TTF_Font* font = TTF_OpenFont("fonts/Oswald.ttf", 200);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    SDL_Color black = { 0, 0, 0 };
    std::stringstream strm;
    strm << (int)num;
    text = TTF_RenderText_Solid(font, strm.str().c_str(), black);
    SDL_Texture* text_texture;
    text_texture = SDL_CreateTextureFromSurface(renderer, text);

    SDL_RenderCopy(renderer, text_texture, NULL, &rectangle);
   
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
    TTF_Quit();
}
