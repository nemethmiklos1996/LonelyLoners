#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

#include "headers/Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture*  p_tex) : x(p_x), y(p_y), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 1280;
    currentFrame.h = 720;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}
