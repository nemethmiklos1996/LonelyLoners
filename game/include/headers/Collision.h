#pragma once

#include <stdio.h>

#include "headers/Entity.h"
#include "headers/RenderWindow.h"

bool Collision(Entity& first, Entity& second)
{
    V2F pos1;
    pos1 = first.getPos();

    V2F pos2;
    pos2 = second.getPos();

    bool x_overlaps = (pos1.getX() < pos2.getX() + second.getCurrentFrame().w) && (pos1.getX() + 32 > pos2.getX());
    bool y_overlaps = (pos1.getY() < pos2.getY() + second.getCurrentFrame().h) && (pos1.getY() + 32 > pos2.getY());

    return (x_overlaps && y_overlaps);
}