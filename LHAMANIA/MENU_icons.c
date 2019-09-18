#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <math.h>

#include "inicializa.h"
#include "global.h"
#include "desenha_cena.h"
#include "teclado.h"
#include "colisao.h"
#include "MENU_char.h" //mander
#include "MENU_credit.h"
#include "MENU_icons.h"
#include "MENU_inventario.h"
#include "MENU_util.h"

void desenhaFundo(){


glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_fundo);

HitBox(0, -720, 2*720, 1280);

      glDisable(GL_TEXTURE_2D);

}


void desenhaIcons(){


glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_play);
HitBox(680, -50 , 200, 100);

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_controle);
HitBox(840, -50 , 200, 100);

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_credit);
HitBox(665, -260 , 100, 50);

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_tip);
HitBox(789, -260 , 100, 50);

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_exit);
HitBox(900, -260 , 100, 50);

switch(cursor){
  case(0):
      glBindTexture(GL_TEXTURE_2D, icon_cursor);
      HitBox(670, -50 , 200, 100);
    break;
  case(1):
       glBindTexture(GL_TEXTURE_2D, icon_cursor);
       HitBox(840, -50 , 200, 100);
    break;
  case(2):
       glBindTexture(GL_TEXTURE_2D, icon_cursor);
       HitBox(669, -260 , 100, 50);
    break;
  case(3):
       glBindTexture(GL_TEXTURE_2D, icon_cursor);
       HitBox(789, -260 , 100, 50);
    break;
  case(4):
       glBindTexture(GL_TEXTURE_2D, icon_cursor);
       HitBox(905, -260 , 100, 50);
    break;

}

glDisable(GL_TEXTURE_2D);
}


void MENU_loading(){

    glClear(GL_COLOR_BUFFER_BIT);


glColor3f(1, 1, 1);

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, icon_menu_fundo);

  HitBox(0, -720, 2*720, 1280);

        glDisable(GL_TEXTURE_2D);

glutSwapBuffers();




}

void MENU_creditos(){

  glColor3f(1, 1, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, creditos);

    HitBox(0, -720, 2*720, 1280);

          glDisable(GL_TEXTURE_2D);



}
