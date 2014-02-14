#include "Mina.h"

Mina::Mina(int x, int y, SDL_Surface* surface)
{
    this->x = x;
    this->y = y;
    this->surface = surface;
    this->going_up = false;
    this->going_down = false;
    this->going_left = true;
    this->going_right = false;
}

void Mina::moveLeft()
{
    if(going_left)
    {
        x--;
    }
}

void Mina::moveUp()
{
    if(going_up)
    {
        x=100;
        y--;
    }
}

void Mina::moveRight()
{
    if(going_right)
    {
        y=100;
        x++;
    }
}

void Mina::moveDown()
{
    if(going_down)
    {
        x=600;
        y++;
    }
}

void Mina::moverse()
{
    Mina::moveLeft();

    if(x<100)
    {
        going_left=false;
        going_up=true;
    }

    Mina::moveUp();

    if(y<100)
    {
        going_up = false;
        going_right = true;
    }

    Mina::moveRight();

    if(x>600)
    {
        going_right = false;
        going_down = true;
    }

    Mina::moveDown();

    if(y>500)
    {
        going_down = false;
        going_left = true;
    }
}

Mina::~Mina()
{
    //dtor
}
