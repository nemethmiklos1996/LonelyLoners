#pragma once

#include <fstream>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>


class LyrsAnims
{
public:
    LyrsAnims() : run(false)
    {
        std::vector<std::pair<int, int>> temp = { {0, 32}, {0, 64}, {0, 96}, {0, 128} };
        spritepos = temp;
    }

    bool init(SDL_Window* win, int flags);
    void render(SDL_Window* win);
    void update(SDL_Window* win, SDL_Renderer* r);
    void handleEvents(SDL_Window* win, SDL_Renderer* renderer);
    void cleanup();

    bool animate() { return run; }
    
private:
    bool run;
    std::vector<std::pair<int, int>> spritepos;
    SDL_Rect src_rec, dest_rec, text_rec;
    SDL_Texture* tex1,* tex2;
    SDL_Renderer* renderer;
};