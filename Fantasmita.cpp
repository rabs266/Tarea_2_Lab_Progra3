#include "Fantasmita.h"

Fantasmita::Fantasmita(int x, int y, SDL_Surface* surface)
{
    this->x=x;
    this->y=y;
    this->surface = surface;
    bool hacia_arriba = true;
}

void Fantasmita::moverse()
{
    if(hacia_arriba)
        y--;
    else
        y++;

    if(y<30)
    {
        hacia_arriba=false;
    }
    if(y>400)
    {
        hacia_arriba=true;
    }
}

Fantasmita::~Fantasmita()
{
    //dtor
}
