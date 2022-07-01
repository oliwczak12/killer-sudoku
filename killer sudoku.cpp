#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    SDL_Window* window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    //if window wouldn't create 
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    bool gamIsRuning = true;
    while (gamIsRuning){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                gamIsRuning=false;
          }
        }
    }

    SDL_Quit();
    return 0;
}