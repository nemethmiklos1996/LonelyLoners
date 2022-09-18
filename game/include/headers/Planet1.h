#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"


std::vector<Entity> LoadPlanet1(RenderWindow planet1) 
{
    std::vector<Entity> resEntities;
    // scopeolás a memória spórolás miatt lett alkalmazva
    SDL_Texture* background = planet1.loadTexture("res/gfx/map1_alapmap.png");
    {
        Entity pl0(V2F(0, 0), background);
        resEntities.push_back(pl0);
    }
    SDL_Texture* cloud1 = planet1.loadTexture("res/gfx/map1__felho_1.png");
    {
        Entity cl1(V2F(0, 0), cloud1);
        resEntities.push_back(cl1);
    }
    SDL_Texture* cloud2 = planet1.loadTexture("res/gfx/map1__felho_2.png");
    {
        Entity cl2(V2F(0, 0), cloud2);
        resEntities.push_back(cl2);
    }
    SDL_Texture* cloud3 = planet1.loadTexture("res/gfx/map1__felho_3.png");
    {
        Entity cl3(V2F(0, 0), cloud3);
        resEntities.push_back(cl3);
    }
    SDL_Texture* cloud4 = planet1.loadTexture("res/gfx/map1__felho_4.png");
    {
        Entity cl4(V2F(0, 0), cloud4);
        resEntities.push_back(cl4);
    }
    SDL_Texture* cloud5 = planet1.loadTexture("res/gfx/map1__felho_5.png");
    {
        Entity cl5(V2F(0, 0), cloud5);
        resEntities.push_back(cl5);  
    }
    SDL_Texture* cloud6 = planet1.loadTexture("res/gfx/map1__felho_6.png");
    {
        Entity cl6(V2F(0, 0), cloud6);
        resEntities.push_back(cl6);
    }
    SDL_Texture* cloud7 = planet1.loadTexture("res/gfx/map1__felho_7.png");
    {
        Entity cl7(V2F(0, 0), cloud7);
        resEntities.push_back(cl7);
    }
    SDL_Texture* cloud8 = planet1.loadTexture("res/gfx/map1__felho_ajtotakaro.png");
    {
        Entity cl8(V2F(0, 0), cloud8);
        resEntities.push_back(cl8);
    }
    SDL_Texture* cloud9 = planet1.loadTexture("res/gfx/map1__felho_rejtekhely.png");
    {
        Entity cl9(V2F(0, 0), cloud9);
        resEntities.push_back(cl9);
    }

    return resEntities;     
}