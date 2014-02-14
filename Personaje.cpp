#include "Personaje.h"

Personaje::Personaje(int x, int y, SDL_Surface* surface)
{
    this->x = x;
    this->y = y;
    this->surface = surface;
}

Personaje::~Personaje()
{
    //dtor
}
