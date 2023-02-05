#pragma once
class Turtle {

public:

    virtual ~Turtle() {}
    void PenUp() ;
    virtual void PenDown() = 0;
    virtual void SomeExpensiveOpertion() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
    

};

