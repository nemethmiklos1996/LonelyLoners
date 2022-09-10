#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

class RenderWindow
{
    public:

        RenderWindow(const char* p_title, int p_w, int p_h);

        void cleanUp();
   
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};

