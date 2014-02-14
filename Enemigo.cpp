#include "Enemigo.h"

Enemigo::Enemigo(int x, int y, SDL_Surface* surface)
{
    this->x = x;
    this->y = y;
    this->surface = surface;
    bool hacia_derecha = true;
}

void Enemigo::moverse()
{
    if(hacia_derecha)
    {
        x--;
        y++;
    }
    else
    {
        x++;
        y--;
    }

    if(x<150 & y>0)
    {
        hacia_derecha=false;
    }
    if(x>30 & y<50)
    {
        hacia_derecha=true;
    }
}

Enemigo::~Enemigo()
{
    //dtor
}
