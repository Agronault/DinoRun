#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "inicializa.h"
#include "global.h"
#include "desenha_cena.h"
#include "teclado.h"
#include "colisao.h"
#include "MENU_char.h"
#include "MENU_credit.h"
#include "MENU_icons.h"
#include "MENU_inventario.h"
#include "MENU_util.h"

void inicializa(void){



    glClearColor(1, 1, 1, 0);



    iniciaGame();

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    tocar_musica("./../source/musica/gfriend.ogg", -1);

    icon_menu_fundo = SOIL_load_OGL_texture(
       "../source/UI/menu_enquadramento.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );

MENU_loading();
   MENU_load();

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);


}

void redimensiona(int w, int h){
 //  glutFullScreen();
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1280, 1280, -720, 720, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
