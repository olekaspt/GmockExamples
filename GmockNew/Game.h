#pragma once
#include "Turtle.h"

class Game
{
    Turtle* turtle;
    int moves = 0;
    int x = 0;
public:
    Game(Turtle* turtle);

    int GetDogX();
    int GetMoves();
    void ChaseTurtle();
    void DoStuff();
};

