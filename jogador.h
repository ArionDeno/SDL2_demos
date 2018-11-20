#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<SDL2/SDL.h>

#define LAR 320
#define ALT 240
#define TITULO "Game Loop SDL2"
#define FPS 30

#define VELO  6

typedef struct
{
  SDL_Rect pos;
  SDL_Texture *img;
} Sprite;

 Sprite bola;



  void init_bola(SDL_Renderer *r);

 void desenhar_bola(SDL_Renderer *r);

 void testar_colisao_limites(Sprite *s);

 SDL_Texture *carrega_sprite(const char caminho[80],SDL_Renderer *r);

 void mover_bola(Sprite *s);










#endif // JOGADOR_H_INCLUDED
