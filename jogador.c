#include"jogador.h"


//  incializa o objeto sprite bola
 void init_bola(SDL_Renderer *r)
 {
    bola.img = carrega_sprite("bola.bmp",r);
    bola.pos.h = 32;
    bola.pos.w = 32;
    bola.pos.x = 128;
    bola.pos.y = 150;
 }


// desenha a bola
void desenhar_bola(SDL_Renderer *r)
{
  SDL_RenderCopy(r,bola.img,NULL,&bola.pos);
}


// testa colisão  com o cenario trata
 void testar_colisao_limites(Sprite *s)
 {
     if(s->pos.x <0)
     {
        s->pos.x += VELO;
        printf("Colisão parede esquerda\n");
     }

     if(  s->pos.x + s->pos.w  >= LAR )
        {
            s->pos.x -= VELO;
            printf("Colisão parede direita\n");
        }

        if(s->pos.y  <0)
        {
          s->pos.y +=VELO;
          printf("Colisão parede teto\n");
        }

      if( s->pos.y + s->pos.h >= ALT)
         {
             s->pos.y -=VELO;
             printf("Colisão chao\n");
         }
 }

// carrega a imagem

 SDL_Texture *carrega_sprite(const char caminho[80], SDL_Renderer *r)
 {
  SDL_Surface *sur = SDL_LoadBMP(caminho);
  SDL_SetColorKey(sur,SDL_TRUE,SDL_MapRGB(sur->format,255,0,255));
  SDL_Texture *tex = SDL_CreateTextureFromSurface(r,sur);
  SDL_FreeSurface(sur);
  return tex;
 }

 // move a bola pelo cenario
 void mover_bola(Sprite *s)
 {
  const Uint8 *tecla;
  tecla = SDL_GetKeyboardState(NULL);

  if(tecla[SDL_SCANCODE_UP])
  {
   s->pos.y -= VELO;
  }

  if(tecla[SDL_SCANCODE_DOWN])
  {
   s->pos.y += VELO;
  }

  if(tecla[SDL_SCANCODE_LEFT])
  {
   s->pos.x -= VELO;
  }

  if(tecla[SDL_SCANCODE_RIGHT])
  {
   s->pos.x += VELO;
  }

 }
