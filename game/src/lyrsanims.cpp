#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "headers/LyrsAnims.h"

int getRR()
{
    int i = 0;
    int RES = 1;

    std::string line;
    std::ifstream set;
    set.open("user.settings");
    if (set.is_open())
    {
        while(std::getline(set, line))
        {
            i++;
            if (i = 1)
            {
                RES = std::stoi(line);
            } 
        }
        set.close();
    }
    
    else std::cout << "A beallitasok fajl serult vagy nem letezik" << std::endl; 

    return RES;
}


bool LyrsAnims::init(SDL_Window* win, int flags)
{
    if (win != nullptr)
    {
        renderer = SDL_CreateRenderer(win, -1, 0);
        if (renderer != nullptr)
        {
            // felület létrehozás a png fájlból
            SDL_Surface* lyrs = IMG_Load("res/gfx/Animations/lyrs_idle.png");
            
            // textúra a felületből
            tex1 = SDL_CreateTextureFromSurface(renderer, lyrs);

            // memória felszabadítása
            SDL_FreeSurface(lyrs);

            // cél és forrás elem dimenzióinak beállítása
            src_rec.x = dest_rec.y = 0;
            src_rec.y = dest_rec.y = 0; 
            src_rec.h = dest_rec.h = 32 * getRR();         
            src_rec.w = dest_rec.w = 32 * getRR();


        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    run = true;
    return true;
}

void LyrsAnims::render(SDL_Window* win) 
{
    SDL_RenderClear( renderer );
    // a változott képkocka kirenderelése
    SDL_RenderCopy( renderer, tex1, &src_rec, &dest_rec );
    SDL_RenderPresent( renderer );
}

void LyrsAnims::update(SDL_Window* win, SDL_Renderer* r)
{
    // animáció képkockának kicserélése
    int t = (SDL_GetTicks()/100) % 12;
    src_rec.x = spritepos[t].first;
    src_rec.y = spritepos[t].second;
}

void LyrsAnims::cleanup()
{
    SDL_DestroyTexture(tex1);
}


