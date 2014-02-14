#ifndef FANTASMITA_H
#define FANTASMITA_H
#include "Enemigo.h"

class Fantasmita : public Enemigo
{
    public:
        Fantasmita(int x, int y, SDL_Surface* surface);
        void moverse();
        bool hacia_arriba;

        virtual ~Fantasmita();
    protected:
    private:
};

#endif // FANTASMITA_H
