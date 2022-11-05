#pragma once

#include <vector>
#include <stdio.h>

#include "headers/Entity.h"
#include "headers/RenderWindow.h"
#include "headers/Collision.h"

std::vector<bool> renderPlanet(RenderWindow planet, std::vector<Entity> &entitii, std::vector<bool> pp, Entity& l)  
{
    int i = 0;
    bool c;

    for(bool p : pp)
    {   
        c = Collision(l, entitii[i]);

        if (c)
            pp[i] = false;

        if (p)
            planet.render(entitii[i]);

        i++;
    }

    return pp;
}
