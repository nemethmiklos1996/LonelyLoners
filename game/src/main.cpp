#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "headers/LonelyLonersGame.h"

int main(int argc, char* argv[])
{
    LonelyLonersGame game;

    game.run();

    return 0;    
}
