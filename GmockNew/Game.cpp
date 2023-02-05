#include "Game.h"

Game::Game(Turtle* turtle)
    : turtle(turtle) {}

void Game::ChaseTurtle()
{
    for (int i = 0; i < 8; i++)
    {
        x = turtle->GetX();
        turtle->GetY();

        if (x >= 200)
        {
            turtle->SomeExpensiveOpertion();
        }

        turtle->Forward(80);
        turtle->GoTo(50, x);
        moves++;
    }
}

void Game::DoStuff()
{

    turtle->GetX();
    turtle->GetY();
    turtle->GoTo(5, 13);
    turtle->PenDown();
}

int Game::GetDogX()
{
    return this->x;
}

int Game::GetMoves()
{
    return this->moves;
}