#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "SDL/SDL_image.h"

class Personaje
{
    public:

        int x;
        int y;
        SDL_Surface* surface;

        Personaje(int x, int y, SDL_Surface* surface);
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
