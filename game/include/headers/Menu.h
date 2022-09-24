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

    SDL_Texture* newGame = nullptr;


    RenderWindow menuWindow("LonelyLoners - LyRs kalandjai v0.1", 384 * getR(), 384 * getR());

    SDL_Texture* mnuBckGround = menuWindow.loadTexture("res/gfx/menu/menu_hatter.png");
    Entity bckground(V2F(0, 0), mnuBckGround);

    SDL_Texture* newGameButton = menuWindow.loadTexture("res/gfx/menu/menu_alap_nagy_ujjatek.png");

    Entity nGameB(V2F(384/2*getR()-125/2*getR(), 60*getR()), newGameButton);
    nGameB.setSize(125,65);

    SDL_Texture* newGameButtonDown = menuWindow.loadTexture("res/gfx/menu/menu_alap_nagy_benyomott_ujjatek.png");

    Entity nGameBD(V2F(384/2*getR()-125/2*getR(), 60*getR()), newGameButtonDown);
    nGameBD.setSize(125,65);

    SDL_Texture* exitGameButton = menuWindow.loadTexture("res/gfx/menu/menu_alap_kilepes.png");

    Entity eGameB(V2F(384/2*getR()-125/2*getR(), 180*getR()), exitGameButton);
    eGameB.setSize(125,65);

    SDL_Texture* exitGameButtonDown = menuWindow.loadTexture("res/gfx/menu/menu_alap_benyomott_kilepes.png");

    Entity eGameBD(V2F(384/2*getR()-125/2*getR(), 180*getR()), exitGameButtonDown);
    eGameBD.setSize(125,65);

    bool menuRunning = true;

    newGame = newGameButton;

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

        bool nGameDown = false;
        bool nGameUp = false;
        bool eGameDown = false;
        bool eGameUp = false;


        while(accum >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {

                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    if (event.button.button = SDL_BUTTON_LEFT
                    and event.button.x > 384/2*getR()-125/2*getR() 
                    and event.button.x < 384/2*getR()+125/2*getR()
                    and event.button.y > 60*getR() 
                    and event.button.y < (60+65)*getR()
                    ) 
                    {
                        nGameDown = true;
                    }
                    else if (event.button.button = SDL_BUTTON_LEFT
                    and event.button.x > 384/2*getR()-125/2*getR() 
                    and event.button.x < 384/2*getR()+125/2*getR()
                    and event.button.y > 180*getR() 
                    and event.button.y < (180+65)*getR()
                    ) 
                    {
                        eGameDown = true;
                    }
 
                }
                if (event.type == SDL_MOUSEBUTTONUP)
                {
                    if (event.button.button = SDL_BUTTON_LEFT
                    and event.button.x > 384/2*getR()-125/2*getR() 
                    and event.button.x < 384/2*getR()+125/2*getR()
                    and event.button.y > 60*getR() 
                    and event.button.y < (60+65)*getR()
                    ) 
                    {
                        selectednumber = 1;
                        nGameUp = true;

                    }
                    else if (event.button.button = SDL_BUTTON_LEFT
                    and event.button.x > 384/2*getR()-125/2*getR() 
                    and event.button.x < 384/2*getR()+125/2*getR()
                    and event.button.y > 180*getR() 
                    and event.button.y < (180+65)*getR()
                    ) 
                    {
                        selectednumber = 2;
                        eGameUp = true;
                    }
                }
             }
            accum -= timeStep;  
        }

        const float alpha = accum / timeStep;       

        if (nGameDown)
        {
            menuWindow.render(nGameBD);
            menuWindow.display();
            SDL_Delay(1000);
        }

        if (eGameDown)
        {
            menuWindow.render(eGameBD);
            menuWindow.display();
            SDL_Delay(1000);
        }

        if ( nGameUp )
        {
            selectednumber = 1;
            menuRunning = false;
        }
        if(eGameUp) 
        {
            selectednumber = 2;
            menuRunning = false;
        }        
        
        menuWindow.render(bckground);  

        menuWindow.render(nGameB);

        menuWindow.render(eGameB);  

        menuWindow.display();
        
        eGameUp = false;
        nGameDown = false;
        nGameUp = false;
    }

    menuWindow.cleanUp();

    return selectednumber;
}