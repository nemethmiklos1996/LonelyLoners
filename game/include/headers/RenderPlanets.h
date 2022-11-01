#pragma once

#include <vector>
#include <stdio.h>

#include "headers/RenderWindow.h"


void renderPlanet(RenderWindow planet, std::vector<Entity> &entitii)  
{
    for(Entity& ent : entitii)
    {      
        planet.render(ent); 
    }
}
