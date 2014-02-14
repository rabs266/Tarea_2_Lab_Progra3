#ifndef MINA_H
#define MINA_H
#include "Enemigo.h"

class Mina : public Enemigo
{
    public:
        Mina(int x, int y, SDL_Surface* surface);
        void moverse();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        bool going_up;
        bool going_down;
        bool going_left;
        bool going_right;

        virtual ~Mina();
    protected:
    private:
};

#endif // MINA_H
