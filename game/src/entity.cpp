#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

#include "headers/Entity.h"


Entity::Entity(V2F p_pos, SDL_Texture*  p_tex) : posi(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 1152;
    currentFrame.h = 1152;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}
