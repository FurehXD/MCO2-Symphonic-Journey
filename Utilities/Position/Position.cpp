#include "Position.h"

Position::Position()
{

}

Position::Position(int x, int y) : x(0), y(0) 
{
    
}

int Position::getX()
{
    return this->x;
}

int Position::getY()
{
    return this->y;
}

void Position::setX(int x)
{
    this->x = x;
}

void Position::setY(int y)
{
    this->y = y;
}

void Position::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

