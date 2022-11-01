#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/Entity.h"

class RenderWindow
{
    public:

        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePAth);
        
        int getRefreshRate();

        void cleanUp();
        void clear();
        void render(Entity& p_entity);
        bool update(Entity& p_entity, std::vector<std::pair<int, int>> spritepos, int frames, int w, int h);
        void display();
        
        void up(Entity& p_entity);        
        void down(Entity& p_entity);
        void left(Entity& p_entity);   
        void right(Entity& p_entity);   
        
        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        const char* p_title;
        int p_w;
        int p_h;
};
