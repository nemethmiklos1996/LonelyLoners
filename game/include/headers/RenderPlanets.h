#pragma once

#include <vector>
#include <stdio.h>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"
#include "headers/Utils.h"


void renderPlanet(RenderWindow planet, std::vector<Entity> &entitii, LyRs lirs)  
{
    planet.clear();
    
    for(Entity& ent : entitii)
    {
        planet.render(ent);  
        planet.renderLyRs(lirs);
  
    }

    planet.display();

}
