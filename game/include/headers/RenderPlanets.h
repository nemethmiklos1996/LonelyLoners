#pragma once

#include <vector>
#include <stdio.h>

#include "headers/Entity.h"
#include "headers/RenderWindow.h"

void renderPlanet(RenderWindow planet, std::vector<Entity> &entitii, Entity& l)  
{
    int i = 0;
    for(Entity& ent : entitii)
    {   
        if (i > 0)
        {
            ent.collisionDetection(l);
        }
        planet.render(ent);
        i++;
    }
}
