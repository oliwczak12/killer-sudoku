// Example program:
// Using SDL2 to create an application window

#include "SDL.h"
#include <iostream>
#include "Render_handler.h"
#include "Event_handler.h"
#include "SDL_ttf.h"

#define SCREEN_WIDTH 970
#define SCREEN_HEIGHT 970

bool running = true;

bool quit;

int main(int argc, char* argv[]) {
    if (TTF_Init() < 0) {
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    }
    TTF_Font* Sans = TTF_OpenFont("fonts/Oswald.ttf", 24);
    if (!Sans) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    SDL_Window* window;                    // Declare a pointer
    SDL_Renderer* renderer;


    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        SCREEN_WIDTH,                      // width, in pixels
        SCREEN_HEIGHT,                     // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


    SDL_Delay(500);
    while (running)
    {  

        event_handler(quit);
        //przenieœæ render_handler do event handler tak ¿eby renderowa³o siê tylko po kliknieciu
        render_handler(renderer, Sans);
        if (quit)
        break; 
    }

    TTF_CloseFont(Sans);
    TTF_Quit();
    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}