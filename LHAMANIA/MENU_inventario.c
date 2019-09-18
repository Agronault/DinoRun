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


void desenhaSkins(){

desenhaAtual();

glColor4f(0, 0, 0, 0.5);

HitBox( 1260 - 500, -700, 1400, 500);

HitBox (0, -700, 500, 240);


glColor3f(1, 1, 1);

desenhaAvatar();



}


void desenhaAtual(){


glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);




glBindTexture(GL_TEXTURE_2D, icon_menu_fundo);
//tem que dar switch aqui  switch(cursor){




HitBox( 0, -720, 1440, 1280);

glDisable(GL_TEXTURE_2D);


}




void desenhaAvatar(){



glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, icon_avatar1);
  HitBox(360, 500 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar2);
  HitBox(560, 500 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar3);
  HitBox(760, 500 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, 500 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar5);
  HitBox(1160, 500 , 200, 100);

  glColor3f(0.5, 0.5, 0.5);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, 300 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, 300 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, 300 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, 300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, 300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, 100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, 100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, 100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, 100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, 100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, -100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, -100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, -100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, -100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, -100 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, -300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, -300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, -300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, -300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, -300 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, -500 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, -500 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, -500 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, -500 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, -500 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(360, -700 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(560, -700 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(760, -700 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(960, -700 , 200, 100);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(1160, -700 , 200, 100);


  //----------------------------------------------------


  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(-120, -460 , 240, 120);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(120, -460 , 240, 120);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(-120, -700 , 240, 120);

  glBindTexture(GL_TEXTURE_2D, icon_avatar4);
  HitBox(120, -700 , 240, 120);


glColor3f(1, 1, 1);

  glBindTexture(GL_TEXTURE_2D, icon_menu_exit);
  HitBox(-1160, 500 , 200, 100);


  glBindTexture(GL_TEXTURE_2D, icon_menu_play);
  HitBox(-960, 500 , 200, 100);



desenhaCursor();


glDisable(GL_TEXTURE_2D);

}



void desenhaCursor(){

  glBindTexture(GL_TEXTURE_2D, icon_cursor);

switch (cursor){


  case 1:

  HitBox(-1160, 500 , 200, 100);


    break;

  case 2:

  HitBox(-960, 500 , 200, 100);

  break;

  case 3:

  HitBox(-120, -460 , 240, 120);

  break;

  case 4:

  HitBox(120, -460 , 240, 120);

  break;

  case 5:

  HitBox(-120, -700 , 240, 120);

  break;

  case 6:

  HitBox(120, -700 , 240, 120);

  break;

  case 7:

  HitBox(360, 500 , 200, 100);

  break;

  case 8:

  HitBox(560, 500 , 200, 100);


  break;

  case 9:

  HitBox(760, 500 , 200, 100);

  break;

  case 10:

  HitBox(960, 500 , 200, 100);

  break;

  case 11:

  HitBox(1160, 500 , 200, 100);

  break;

  case 12:

  HitBox(360, 300 , 200, 100);

  break;

  case 13:

  HitBox(560, 300 , 200, 100);

  break;

  case 14:

  HitBox(760, 300 , 200, 100);

  break;

  case 15:

  HitBox(960, 300 , 200, 100);

  break;

  case 16:

  HitBox(1160, 300 , 200, 100);

  break;

  case 17:

  HitBox(360, 100 , 200, 100);

  break;

  case 18:

  HitBox(560, 100 , 200, 100);

  break;

  case 19:

  HitBox(760, 100 , 200, 100);

  break;

  case 20:

  HitBox(960, 100 , 200, 100);

  break;

  case 21:

  HitBox(1160, 100 , 200, 100);

  break;

  case 22:

  HitBox(360, -100 , 200, 100);

  break;

  case 23:

  HitBox(560, -100 , 200, 100);

  break;

  case 24:

    HitBox(760, -100 , 200, 100);

  break;

  case 25:

  HitBox(960, -100 , 200, 100);

  break;

  case 26:

  HitBox(1160, -100 , 200, 100);

  break;

  case 27:

  HitBox(360, -300 , 200, 100);

  break;

  case 28:

  HitBox(560, -300 , 200, 100);

  break;

  case 29:

    HitBox(760, -300 , 200, 100);

  break;

  case 30:

  HitBox(960, -300 , 200, 100);

  break;

  case 31:

    HitBox(1160, -300 , 200, 100);

  break;

  case 32:

  HitBox(360, -500 , 200, 100);

  break;

  case 33:

    HitBox(560, -500 , 200, 100);

  break;

  case 34:

  HitBox(760, -500 , 200, 100);

  break;

  case 35:

    HitBox(960, -500 , 200, 100);

  break;

  case 36:

    HitBox(1160, -500 , 200, 100);

  break;

  case 37:

    HitBox(360, -700 , 200, 100);

  break;

  case 38:

  HitBox(560, -700 , 200, 100);

  break;

  case 39:

    HitBox(760, -700 , 200, 100);

  break;

  case 40:

    HitBox(960, -700 , 200, 100);

  break;

  case 41:

    HitBox(1160, -700 , 200, 100);

  break;

  case 42:

  break;



default:
break;
}





}
