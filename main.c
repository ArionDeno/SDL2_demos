#include <stdio.h>
#include <stdlib.h>
#include<SDL2/SDL.h>
#include"jogador.h"




int main(int argc, char *argv[])
{
 SDL_Window *janela= NULL;
 SDL_Renderer *render= NULL;
 SDL_Event ev;
 SDL_bool gameloop = SDL_TRUE;

  int t_ini=0, deltatm =0, tm_fps=0,fps=0;

  //inicializando a SDL2
  if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_TIMER|SDL_INIT_VIDEO|SDL_INIT_TIMER)>=0)
  {
    // cria a janela
    janela = SDL_CreateWindow(TITULO,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LAR,ALT,SDL_WINDOW_SHOWN);
    if(janela == NULL)
    {
      printf("Erro ao inciiarlizar a janela\n%s",SDL_GetError());
      return(EXIT_FAILURE);
    }
    // cria o render
    render = SDL_CreateRenderer(janela,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);
  }
  else
  {
    printf("Erro ao inciiarlizar a SDL2\n%s",SDL_GetError());
    return(EXIT_FAILURE);
  }
/*----------LOAD-------------*/

  init_bola(render);

/*----------LOAD-------------*/

 while(gameloop != SDL_FALSE)
 {
    t_ini= SDL_GetTicks();
  /*----------INPUT-------------*/
    if(SDL_PollEvent(&ev))
    {
      // testando sair do jogo
      if(ev.type == SDL_QUIT|| ev.key.keysym.sym == SDLK_ESCAPE)
      {
        gameloop = SDL_FALSE;
      }

      // testando o mouse
      if(ev.type == SDL_MOUSEBUTTONDOWN)
      {
          if(ev.button.button == SDL_BUTTON_LEFT)
          {
             SDL_Log("mouse clicado");
          }
      }

    }
  /*----------INPUT-------------*/

  /*----------UPDATE-------------*/
      //bola.pos.x+= VELO;
      mover_bola(&bola);
      testar_colisao_limites(&bola);
  /*----------UPDATE-------------*/

  /*----------DRAW-------------*/


 SDL_SetRenderDrawColor(render, 0, 162, 232, 255);
    SDL_RenderClear(render);
//---------------------
  desenhar_bola(render);
//--------------------
    SDL_RenderPresent(render);

    //----------------------

  //---------------

  /*----------DRAW-------------*/

  /*----------FPS-------------*/
    tm_fps += SDL_GetTicks();
    fps++;
    deltatm = t_ini - SDL_GetTicks();
    // regula o FPS
    if(deltatm < FPS)
    {
     SDL_Delay( FPS- deltatm);
     printf("atraso = %d \n", FPS- deltatm);
    }

    if(tm_fps >= 1000)
    {
      printf(" - FPS %d\n",FPS/fps);
      fps = 0;
      tm_fps = 0;
    }
      /*----------FPS-------------*/
 }
//---UNLOAD-----------------------
 SDL_DestroyRenderer(render);
 SDL_DestroyWindow(janela);
 SDL_Quit();


  return EXIT_SUCCESS;
}
