#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "Personaje.h"
#include "Fantasmita.h"
#include "Mina.h"
#include "Cocodrilo.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

Mix_Music *music = NULL;

SDL_Surface *background = NULL;

SDL_Surface *screen = NULL;

SDL_Event event;

TTF_Font *font = NULL;

SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *load_image( std::string filename )
{
    return IMG_Load(filename.c_str());
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL )
    {
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "background.png" );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    music = Mix_LoadMUS( "DissonantWaltz.ogg" );

    if( music == NULL )
    {
        return false;
    }

    return true;
}

void clean_up()
{
    SDL_FreeSurface( background );
    Mix_FreeMusic( music );
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    bool quit = false;

    if( init() == false )
    {
        return 1;
    }

    if( load_files() == false )
    {
        return 1;
    }

    int j;
    int x_pichingo = 0;
    int y_pichingo = 0;

    SDL_Surface* pichingo[4];
    pichingo[0] = load_image("Personaje01.png");
    pichingo[1] = load_image("Personaje02.png");
    pichingo[2] = load_image("Personaje03.png");
    pichingo[3] = load_image("Personaje04.png");
    //Personaje Personaje ( 20, 50, load_image ("Personaje01.png"));

    SDL_Surface* goal = load_image("Ganaste.png");

    //Usar solo apuntadores en los vectores
    vector <Enemigo*> enemigos;
    enemigos.push_back(new Fantasmita(350,500,load_image("Fantasma.png")));
    enemigos.push_back(new Enemigo (100,500,load_image("Fantasma.png")));
    enemigos.push_back(new Mina (600,500,load_image("Mina.png")));
    enemigos.push_back(new Cocodrilo(350, 500, load_image("Cocodrilo01.png")));

    SDL_Surface* meta = load_image ( "Meta.png");

    while( quit == false )
    {
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        apply_surface( 0, 0, background, screen );

        if(j > 3)
        {
            j= 0;
        }

        for(int i= 0; i<enemigos.size(); i++)
        {
            apply_surface (enemigos[i]->x,enemigos[i]->y, enemigos[i]->surface, screen);
            enemigos[i]->moverse();
        }

        apply_surface ( 650, 500, meta, screen);

        Uint8 *keystates = SDL_GetKeyState( NULL );

        if( Mix_PlayingMusic() == 0 )
        {
            if( Mix_PlayMusic( music, -1 ) == -1 )
            {
                return 1;
            }
        }

        if( keystates[ SDLK_UP ] )
        {
            y_pichingo-=2;
//            apply_surface(x_pichingo, y_pichingo, pichingo[j], screen);
//            j++;
        }

        else if( keystates[ SDLK_DOWN ] )
        {
            y_pichingo+=2;
//            apply_surface(x_pichingo, y_pichingo, pichingo[j], screen);
//            j++;
        }

        else if( keystates[ SDLK_LEFT ] )
        {
            x_pichingo-=2;
//            apply_surface(x_pichingo, y_pichingo, pichingo[j], screen);
//            j++;
        }

        else if( keystates[ SDLK_RIGHT ] )
        {
            x_pichingo+=2;
//            apply_surface(x_pichingo, y_pichingo, pichingo[j], screen);
//            j++;
        }

            apply_surface( x_pichingo, y_pichingo, pichingo[j], screen );
            j++;


        if(x_pichingo > 650 && y_pichingo >500)
        {
            apply_surface(145,145,goal,screen);
            //exit(0);
        }

        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        SDL_Delay(1);
    }

    clean_up();

    return 0;
}
