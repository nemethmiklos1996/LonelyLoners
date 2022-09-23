#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"
#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Utils.h"
#include "headers/Entity.h"

int getR()
{
    int i = 0;
    int RES = 1;
    std::string line;
    std::ifstream set;
    set.open("user.settings");
    if (set.is_open())
    {
        while(getline(set, line))
        {
            i++;
            if (i = 1)
            {
                RES = std::stoi(line);
            } 
        }
        set.close();
    }
    
    else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 

    return RES;
}

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
    // ablak kirajzolása
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 384 * getR(), 384 * getR());

    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet1(game);

    SDL_Texture* lyrsPNG = game.loadTexture("res/gfx/lyrs.png");
    LyRs lirs(V2F(90 * getR(), 16 * getR()), lyrsPNG);

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
      
        renderPlanet(game, planet1, lirs);     

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
