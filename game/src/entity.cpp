#include <fstream>
#include <iostream>
#include <string.h>
#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <iostream> //include the header files like input-output streams
#include <fstream> //include the filestreamobject as the header files

#include "headers/Entity.h"

// int getRES()
// {
//     int i = 0;
//     int RES = 1;
//     std::string line;
//     std::ifstream set;
//     set.open("user.settings");
//     if (set.is_open())
//     {
//         while(getline(set, line))
//         {
//             i++;
//             if (i = 1)
//             {
//                 RES = std::stoi(line);
//             } 
//         }
//         set.close();
//     }
//     
//     else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 
// 
//     return RES;
// }

Entity::Entity(V2F p_pos, SDL_Texture*  p_tex) : posi(p_pos), tex(p_tex)
{
    // int resolution = getRES();
    
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 384 /* * resolution */;
    currentFrame.h = 384 /* * resolution */;
}

void Entity::setSize(int w, int h)
{
    // int resolution = getRES();

    currentFrame.w = w /* * resolution */;
    currentFrame.h = h /* * resolution */;    
}

void Entity::setPosi(int x, int y)
{
    posi.x = currentFrame.x += x;
    posi.y = currentFrame.y += y; 
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::collisionDetection(Entity& t)
{
    SDL_Rect r = t.getCurrentFrame();

    bool c1 = true, c2 = true, c3 = true, c4 = true;

    if (currentFrame.y >= r.y + r.h)  
        c1 = false;
    if (currentFrame.y >= r.x + r.w)
        c2 = false;
    if (currentFrame.y + currentFrame.h <= r.y)
        c3 = false;
    if (currentFrame.x + currentFrame.w <= r.x)
        c4 = false;

    // if (c1 || c2 || c3 || c4)
        // SDL_DestroyTexture(tex);
}
