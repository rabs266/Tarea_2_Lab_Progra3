#ifndef COCODRILO_H
#define COCODRILO_H
#include "Enemigo.h"

class Cocodrilo : public Enemigo
{
    public:
        Cocodrilo(int x, int y, SDL_Surface* surface);
        //Funciones de movimiento
        void moverse();
        void diagonalDm();
        void diagonalMu();
        void diagonalUm();
        void diagonalMd();

        //Booleanos para checar direccion
        bool diagodm;
        bool diagomu;
        bool diagoum;
        bool diagomd;

        bool avance;
        virtual ~Cocodrilo();
    protected:
    private:
};

#endif // COCODRILO_H
