#include "Event_handler.h"
#include "SDL.h"


void event_handler(bool &quit)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_Log("bang");
            //renderer_handler
            // 
            // wersja pierwwsza
            //colision handler w nim colision boxy sprawdzaj¹ce pozycje myszki po kliknieciu któr¹ dostan¹ w raz z wywo³aniem funkcji
            // 
            // wersja druga sprawdzaæ po kolumnie i rzêdzie
            // 
            //
        }
    }
}
