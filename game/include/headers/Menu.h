#pragma once

#include "headers/Entity.h"
#include "headers/RenderWindow.h"
#include "headers/Settings.h"

int getR()
{
    int i = 0;
    int RES = 1;
    std::string line;
    std::ifstream set;
    set.open("user.settings");
    if (set.is_open())
    {
        while(getline(set, line))
        {
            i++;
            if (i = 1)
            {
                RES = std::stoi(line);
            } 
        }
        set.close();
    }
    
    else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 

    return RES;
}

int menu()
{
    int selectednumber;
    bool menu = true;

    RenderWindow menuWindow("LonelyLoners - LyRs kalandjai v0.1", 384 * getR(), 384 * getR());

    SDL_Texture* mnuBckGround = menuWindow.loadTexture("res/gfx/menu/menu_hatter.png");
    Entity bckground(V2F(0, 0), mnuBckGround);

    SDL_Texture* newGameButton = menuWindow.loadTexture("res/gfx/menu/menu_alap_nagy_ujjatek.png");
    Entity nGameB(V2F(384/2*getR()-125/2*getR(), 60), newGameButton);
    nGameB.setSize(125,65);
    bool menuRunning = true;

    SDL_Event event;

    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();

    while(menuRunning)
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
                    menuRunning = false;
                }
            }
            accum -= timeStep;            
        }

        const float alpha = accum / timeStep;
        
        menuWindow.render(bckground);  
        menuWindow.render(nGameB);  
        menuWindow.display();  
    }

    menuWindow.cleanUp();
    SDL_Quit();

    return selectednumber;
}