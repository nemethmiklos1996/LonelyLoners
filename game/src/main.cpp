#define SDL_MAIN_HANDLED

#include <iostream>
#include <stdio.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"


int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init hiba. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init hiba. Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 1280, 720);

    SDL_Texture* planet1 = game.loadTexture("res/gfx/planet1.png");
    Entity pl0(0, 0, planet1);

    SDL_Texture* lyrs = game.loadTexture("res/gfx/lyrs.png");
    Entity karakter(0, 0, lyrs);

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }

        game.clear();
        game.render(pl0);
        game.render(karakter);
        game.display();
    }

    game.cleanUp();
    SDL_Quit();

    return 0;
}
