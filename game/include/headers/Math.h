#pragma once

#include <iostream>

class V2F
{
public:
    
    V2F() : x(0.0f), y(0.0f)
    {

    }
    
    V2F(float vx, float vy) : x(vx), y(vy)
    {

    }

    void print()
    {
        std::cout << "V2F (x, y): " << x << ", " << y << std::endl;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    float x, y;

private:
};