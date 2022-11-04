#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Menu.h"
#include "headers/Entity.h"


int main(int argc, char* argv[])
{
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 384 /* * getRRes() */, 384 /* * getRRes() */);

    int choice = menu(game);

    game.clear();

    if (choice == 1)
    {
        std::vector<std::pair<int, int>> lyrsIdleR;
        std::vector<std::pair<int, int>> lyrsIdleL;
        std::vector<std::pair<int, int>> lyrsMoveR;
        std::vector<std::pair<int, int>> lyrsMoveL;
        std::vector<std::pair<int, int>> lyrsLaserR;
        std::vector<std::pair<int, int>> lyrsLaserL;
                
        lyrsIdleR       = { { 0,   0}, {64,   0}, {128,   0}, {192,  0} };

        lyrsIdleL       = { {32,  32}, {96,  32}, {160,  32}, {224, 32} };

        lyrsMoveR       = { { 0,  64}, {64,  64}, {128,  64}, {192, 64}, {256,   64} };

        lyrsMoveL       = { {32,  96}, {96,  96}, {160,  96}, {224, 96}, {290,   96} };

        lyrsLaserR      = { { 0, 128}, {64, 128}, {128, 128}, {192, 128}, {256, 128} , 
                            { 0, 160}, {64, 160}, {128, 160}, {192, 160}, {256, 160} , 
                            { 0, 192}, {64, 192}, {128, 192}, {192, 192}, {256, 192} ,
                            { 0, 224}, {64, 224}, {128, 224}, {192, 224}, {256, 224} };
        
        lyrsLaserL      = { { 0, 256}, {64, 256}, {128, 256}, {192, 256}, {256, 256} , 
                            { 0, 288}, {64, 288}, {128, 288}, {192, 288}, {256, 288} , 
                            { 0, 320}, {64, 320}, {128, 320}, {192, 320}, {256, 320} ,
                            { 0, 352}, {64, 352}, {128, 352}, {192, 352}, {256, 352} };
                          

        std::vector<Entity> planet1 = {};
        planet1 = LoadPlanet1(game);
       
        SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/lyrs_sprite_sheet.png");
        Entity l(V2F(0, 0), lyrsAnim);           
        l.setSize(64 ,32);

        bool gameRunning = true;
        bool attack = false;
        bool fel = false;
        bool le = false;
        bool jobbra = false;
        bool balra = false;
        bool flip = false;
        SDL_Event event;
        
        const float timeStep = 0.01f;
        float accum = 0.0f;
        float cTime = utils::hireTimeInSeconds();
     
        while(gameRunning)
        {
            // képkocka idők számolás
            int startTick = SDL_GetTicks();
            
            float nTime = utils::hireTimeInSeconds();
            float fTime = nTime - cTime;
            
            cTime = nTime;
            accum += fTime;
            
            while(accum >= timeStep)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        gameRunning = false;
                    }
                    if(event.type == SDL_KEYDOWN)
                    {   
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_UP:
                                std::cout << "FEL! lenyomva" << std::endl;
                                fel = true;
                                break;
                            case SDLK_DOWN:
                                std::cout << "LE! lenyomva" << std::endl;
                                le = true;
                                break;
                            case SDLK_LEFT:
                                std::cout << "BALRA! lenyomva" << std::endl;
                                balra = true;
                                break;
                            case SDLK_RIGHT: 
                                std::cout << "JOBBRA! lenyomva" << std::endl;
                                jobbra = true;
                                break;
                            case SDLK_SPACE:
                                attack = true;
                                std::cout << "SZOKOZ! lenyomva" << std::endl;
                                break;
                            default:;
                        }
                    }
                    if(event.type == SDL_KEYUP)
                    {   
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_UP:
                                std::cout << "FEL! elengedve" << std::endl; 
                                fel = false;
                                break;
                            case SDLK_DOWN:
                                std::cout << "LE! elengedve" << std::endl;
                                le = false;
                                break;
                            case SDLK_LEFT:
                                std::cout << "BALRA! elengedve" << std::endl;
                                balra = false;
                                break;
                            case SDLK_RIGHT: 
                                std::cout << "JOBBRA! elengedve" << std::endl;
                                jobbra = false;
                                break;
                            case SDLK_SPACE:
                                attack = false; 
                                std::cout << "SZOKOZ! elengedve" << std::endl;
                                break;
                            default:;
                        }
                    }
                }
                accum -= timeStep;
            }
            
            const float alpha = accum / timeStep;
            
            renderPlanet(game, planet1);

            if (fel)
            {
                if (flip)
                {
                    game.up(l);
                    game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32);
                }
                else
                {
                    game.up(l);
                    game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32);
                }
            }
    
            if (le)
            {
                if (flip)
                {
                    game.down(l);
                    game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32);
                }
                else
                {
                    game.down(l);
                    game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32);
                }
            }
            
            if (balra)
            {
                game.left(l);
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32);
                flip = false;
            }

            if (jobbra)
            {
                game.right(l);
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32);
                flip = true;
            }

            if (attack)
            {
                if (flip)
                {
                    attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32);               
                }
                else
                {
                    attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32);               
                }

            }

            if (!fel && !le && !balra && !jobbra && !attack)
            {
                if (flip)
                {
                    game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32);
                }
                else
                {
                    game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32);
                }
            }

            SDL_RenderPresent( game.getRenderer() );
        }       
        game.cleanUp();
        SDL_Quit();
    }
    else if (choice == 5)
    {
        return 0;
    }
    return 0;
}
