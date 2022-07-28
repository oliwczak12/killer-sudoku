// Example program:
// Using SDL2 to create an application window

#include "SDL.h"
#include <iostream>
#include "Render_handler.h"
#include "Event_handler.h"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

bool running = true;

bool quit;


int main(int argc, char* argv[]) {

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
        render_handler(renderer);

        if (quit)
        break; 
    }


    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}