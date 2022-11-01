#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Menu.h"
#include "headers/Entity.h"


int main(int argc, char* argv[])
{
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 384 /* * getRRes() */, 384 /* * getRRes() */);

    int choice = menu(game); 

    if (choice == 1)
    {
        std::vector<std::pair<int, int>> lyrs;
        lyrs = { {0, 0}, {32, 0}, {64, 0}, {96, 0} };
        
        std::vector<Entity> planet1 = {};
        planet1 = LoadPlanet1(game);
    
        
        SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/lyrs_idle.png");
        Entity l(V2F(64, 64), lyrsAnim);           
        l.setSize(32,32);
        

        bool gameRunning = true;

        SDL_Event event;
        
        const float timeStep = 0.01f;
        float accum = 0.0f;
        float cTime = utils::hireTimeInSeconds();
     
        while(gameRunning)
        {
            // képkocka idők számolás
            int startTick = SDL_GetTicks();
            
            float nTime = utils::hireTimeInSeconds();
            float fTime = nTime - cTime;
            
            cTime = nTime;
            accum += fTime;
            
            while(accum >= timeStep)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        gameRunning = false;
                    }
                }
                accum -= timeStep;
            }
            
            const float alpha = accum / timeStep;

            renderPlanet(game, planet1);

            game.update(l, lyrs);

            SDL_RenderPresent( game.getRenderer() );

        }       
        game.cleanUp();
        SDL_Quit();
    }
    else if (choice == 5)
    {
        return 0;
    }
    return 0;
}
