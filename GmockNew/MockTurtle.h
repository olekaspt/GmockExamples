#pragma once
#include "Turtle.h"
#include "gmock/gmock.h"  // Brings in gMock.

//This was inspired from 
// https://github.com/Ed-Yang/gturtle
// Example.  I took this and extended this to 
// to have a another example
// and migrate this to use the new Macros

class MockTurtle : public Turtle {
public:

    MOCK_METHOD(void, PenUp, ());
    MOCK_METHOD(void, PenDown, ());
    MOCK_METHOD(void, Forward, (int distance));
    MOCK_METHOD(void, Turn, (int degrees));
    MOCK_METHOD(void, GoTo, (int x, int y));
    MOCK_METHOD(int, GetX, (), (const));
    MOCK_METHOD(int, GetY, (),(const));
    MOCK_METHOD(void, SomeExpensiveOpertion, ());

};