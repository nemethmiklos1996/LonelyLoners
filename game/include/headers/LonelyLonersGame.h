#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

enum class GameState {PLAY, EXIT};

class LonelyLonersGame
{
    public:
        Game();
        ~Game();

        void run();
    
    private:
        void init(const char* title, int x, int y, int w, int h, Uint32 flags);
        void gameLoop();
        void handleEvents();

        SDL_Window* _window;
        SDL_Renderer* _renderer;

        int _screenWidth;
        int _screenHeight;

        GameState _gameState;
};

