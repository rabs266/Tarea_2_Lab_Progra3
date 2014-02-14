#include "Cocodrilo.h"

Cocodrilo::Cocodrilo(int x, int y, SDL_Surface* surface)
{
    this->x = x;
    this->y = y;
    this->surface = surface;
    this->diagodm = true;
    this->diagomu = false;
    this->diagoum = false;
    this->diagomd = false;
}

void Cocodrilo::diagonalDm()
{
    if(diagodm)
    {
        x--;
        y--;
    }
}

void Cocodrilo::diagonalMu()
{
    if(diagomu)
    {
        x++;
        y--;
    }
}

void Cocodrilo::diagonalUm()
{
    if(diagoum)
    {
        x++;
        y++;
    }
}

void Cocodrilo::diagonalMd()
{
    if(diagomd)
    {
        x--;
        y++;
    }
}

void Cocodrilo::moverse()
{
    Cocodrilo::diagonalDm();

    if(x==100)
    {
        diagodm = false;
        diagomu = true;
    }

    Cocodrilo::diagonalMu();

    if(x==350)
    {
        diagomu = false;
        diagoum -= true;
    }

    Cocodrilo::diagonalUm();

    if(x==600)
    {
        diagoum = false;
        diagomd = true;
    }

    Cocodrilo::diagonalMd();

    if(y==500)
    {
        diagomd = false;
        diagodm = true;
    }
}

Cocodrilo::~Cocodrilo()
{
    //dtor
}
















