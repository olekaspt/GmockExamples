#pragma once
#pragma once
#include "Turtle.h"

class Painter
{
    Turtle* turtle;
public:
    Painter(Turtle* turtle)
        : turtle(turtle) {}

    bool DrawCircle(int, int, int) {
        turtle->PenDown();
        return true;
    }
};