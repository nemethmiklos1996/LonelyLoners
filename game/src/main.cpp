#define SDL_MAIN_HANDLED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"
#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Utils.h"


int main(int argc, char* argv[])
{
    int i;
    std::string name;
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init hiba. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init hiba. Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 1152, 1152);

    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet1(game);
    bool gameRunning = true;

    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while(gameRunning)
    {
        // képkocka idők számolás    
        int startTick = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = utils::hireTimeInSeconds() - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while(accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }
            accumulator -= timeStep;            
        }

        const float alpha = accumulator / timeStep;
      
        renderPlanet(game, planet1);     

        int frameTicks = SDL_GetTicks() - startTick;

        if (frameTicks < 1000 / game.getRefreshRate())
        {
            SDL_Delay(1000 / game.getRefreshRate() - frameTicks);
        } 
    }

    game.cleanUp();
    SDL_Quit();

    return 0;
}
