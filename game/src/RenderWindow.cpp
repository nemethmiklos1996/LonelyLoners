#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"

RenderWindow::RenderWindow (const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL)
{
    // ablak létrehozása 
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
    // ikon megjelenítése
    SDL_Surface *surface;
    surface = IMG_Load("res/gfx/Characters/lyrs_jobb.png");
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
    // ellenőrzés, hogy létrejött-e az ablak
    if (window == NULL)
    {
        std::cout << "Ablak betöltése sikertelen Error: " << SDL_GetError() << std::endl;
    }
   
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if (texture == NULL)
    {
        std::cout << "Nem sikerült a képet betölteni. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}

int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex( window );

    SDL_DisplayMode m;

    SDL_GetDisplayMode(displayIndex, 0, &m);

    return m.refresh_rate;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

bool RenderWindow::update(Entity& p_entity, std::vector<std::pair<int, int>> spritepos, int frames, int w, int h)
{
    SDL_Rect src;

    // animáció képkockának kicserélése
    int t = (SDL_GetTicks()/100) % frames;
    src.x = spritepos[t].first;
    src.y = spritepos[t].second;

    src.h = h /* * getRRes() */;
    src.w = w /* * getRRes() */;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x;
    dst.y = p_entity.getPos().y;
    dst.w = w;
    dst.h = h;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);

    if (t == frames)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void RenderWindow::up(Entity& p_entity)
{
    p_entity.setPosi(0, -1);
}

void RenderWindow::down(Entity& p_entity)
{
    p_entity.setPosi(0, 1);
}

void RenderWindow::left(Entity& p_entity)
{
    p_entity.setPosi(-1, 0);
}

void RenderWindow::right(Entity& p_entity)
{
    p_entity.setPosi(1, 0);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x;
    dst.y = p_entity.getPos().y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display() 
{
    SDL_RenderPresent(renderer);
}

SDL_Window* RenderWindow::getWindow()
{
    return window;
}

SDL_Renderer* RenderWindow::getRenderer()
{
    return renderer;
}