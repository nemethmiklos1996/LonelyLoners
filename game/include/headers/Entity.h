#pragma once
#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    void init();
    float getX();
    float getY();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();

private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* tex;

};