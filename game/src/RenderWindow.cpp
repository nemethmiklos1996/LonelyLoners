#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"

RenderWindow::RenderWindow (const char* p_title, int p_w, int p_h) : _window(NULL), _renderer(NULL)
{
    _window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if (_window == NULL)
    {
        std::cout << "Ablak betöltése sikertelen Error: " << SDL_GetError() << std::endl;
    }
   
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}


void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(_window);
}