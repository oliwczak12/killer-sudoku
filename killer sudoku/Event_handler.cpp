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
            //colision handler w nim colision boxy sprawdzaj�ce pozycje myszki po kliknieciu kt�r� dostan� w raz z wywo�aniem funkcji
            // 
            // wersja druga sprawdza� po kolumnie i rz�dzie
            // 
            //
        }
    }
}
