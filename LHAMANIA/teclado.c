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

void teclado(unsigned char key, int x, int y){
int foi=0;
if(tela==0 && foi==0){  foi=1;
    switch(key){
    case 27:
        system("clear");
        exit(0);
        break;
    case ' ':
        if(cursor==0){
            tela=1;
            cursor=0;
            parar_musica();
            tocar_musica("./../source/musica/dia.ogg", -1);
        }
        if(cursor==1){
            tela=2;
            cursor=0;
        }
        if(cursor==2){
            tela=6;
            cursor=0;
        }
        if(cursor==3){
            tela=4;
            cursor=1;
        }
        if(cursor==4){
            exit(0);
        }

    break;

    }
}

else{
if(tela==1 && foi==0){ foi=1;
   switch(key)
   {
      case 27:
        iniciaGame();
         tela=0;
         break;
      case ' ':
      case 'W':
      case 'w':
        pulo = 1;
        break;
      case 'S':
      case 's':
       abaixado=1;
       break;
      case 'p':
      case 'P':
        pause *= (-1);
        if(pause==1){
            glutTimerFunc(16, frame, 0);
        }
        break;
      case 'r':
      case 'R':
        iniciaGame();
      break;
      default:
         break;
   }
}

else{
if(tela==2 && foi==0){ foi=1;
    switch(key){
        case 27:
            tela=0;
            break;
    }
}


else{
if(tela==4 && foi==0){
    foi=1;
    switch(key){
    case 27:
        cursor=0;
        tela=0;
        break;
    case ' ':
        if(cursor==1){
            cursor=0;
            tela=0;
        }
        if(cursor==2){
            cursor=0;
            tela=1;
            parar_musica();
            tocar_musica("./../source/musica/dia.ogg", -1);
        }


        if(cursor==7){skin=1;}
        if(cursor==8){skin=2;}
        if(cursor==9){skin=3;}
        if(cursor==10){skin=4;}
        if(cursor==11){skin=5;}

    break;

    }
} else{
  if(tela==5){
    switch (key) {
      case 27:
        tela=0;
        iniciaGame();
        break;
        default:
        break;
    }
  }
  else {
    if(tela==6){
      switch (key) {
        case 27:
          tela=0;
          break;
          default:
          break;
      }

    }


  }
}

}
}
}
}

void SpecialInput(int key, int x, int y){
if(tela==0){
    switch(key)
    {
        case GLUT_KEY_UP:
            cursor--;
            break;
        case GLUT_KEY_DOWN:
            cursor++;
            break;
        case GLUT_KEY_LEFT:
            cursor--;
            break;
        case GLUT_KEY_RIGHT:
            cursor++;
            break;
        default:
            break;
    }
if(cursor==5){cursor=0;}
if(cursor==-1){cursor=4;}

}

if(tela==1){
   switch(key)
   {
        case GLUT_KEY_UP:
            pulo = 1;
            break;
        case GLUT_KEY_DOWN:
            abaixado=1;
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        default:
            break;
    }
}

if(tela==4){

    switch(key)
    {
        case GLUT_KEY_UP:
          if(cursor>=11){cursor= cursor- 5;}
             else cursor--;
            break;
        case GLUT_KEY_DOWN:
      if(cursor>=7){cursor= cursor+ 5;}
            else cursor++;
            break;
        case GLUT_KEY_LEFT:
            cursor--;
            break;
        case GLUT_KEY_RIGHT:
            cursor++;
            break;
        default:
            break;
    }
if(cursor==42){cursor=1;}
if(cursor==0){cursor=41;}


}

}


void keyUp(unsigned char key, int x, int y){
 switch(key){
 case ' ':
 case 's':
    abaixado=0;
    break;

}

}
