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
#include "MENU_char.h"
#include "MENU_credit.h"
#include "MENU_icons.h"
#include "MENU_inventario.h"
#include "MENU_util.h"
#include "texto.h"
#include "save.h"

void escreveRanking(int x, int y){  contador++;

if(contador%10==0){if(hard>0){hard = hard--;}}


    glPushMatrix();
    glColor3f(1,1,1);

    int espacamento, k;
    espacamento = 90;

    sprintf(pts,"TOP 10 ENTREGADORES");
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, x, y+30, 0);

    sprintf(pts,"GAME OVER!");
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, x-920, y+30, 0);

    sprintf(pts,"%s,", nick);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -1190, -40, 0);

    sprintf(pts,"voce entregou %d guacamole(s)!", savePoint);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -1190, -100, 0);

    for(k=0; k<10; k++){
        sprintf(pts,"%2d. %s:",k+1, rec[k].name);
        escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, x, y-(espacamento*(k+1)), 0);
        escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, rec[k].record, x+570, y-(espacamento*(k+1)), 0);
    }

    glPopMatrix();
}

void desenhaGameOver(){
    glPushMatrix();
    glColor4f(1,1,1,1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, splash);


    HitBox(0,-720,1440,1280); //coloca uma imagem de fundo bem legal aqui

glDisable(GL_TEXTURE_2D);

    glColor4f(0,0,0,0.5);
    HitBox(340, -680, 1360, 380); //hitbox que fica atras do TOP 10 MOTHERFOCKER

    HitBox(-700, -680, 1360, 540); //hitbox que fica atras das informacoes de GAME OVER

    HitBox(-700, 20, 520, 490);  //coloca uma lhama tisti por ter perdido

    HitBox(-700, -640, 500, 490); //Aqui fica as instrucoes, P-PAUSE, R-RESET, M-MENU, ESC-MENU

    escreveRanking(20, 540);
    glPopMatrix();
}

void desenhaGame(){


  f5f= f5f + 0.2;
  if(f5f>=1){f5f=0;}

f10f= f10f + 0.1;
if(f10f>=1){f10f=0;}

    glColor3f(0, 0, 0);

    sprintf(pts,"Guacamole capturada: %d", carry);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -1250, 670, 0);

    sprintf(pts,"Guacamoles: %d", moeda);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -500, 670, 0);

    if(pause==-1){
        sprintf(pts,"PAUSE- aperte P para voltar");
        escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -100, 0, 0);
    }

    if(tempo<160){
      tempo++;
      sprintf(pts,"Guacamole entregue: %d", point);
      escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, pts, -1250, 610, 0);
    }

    if(indestrutivel>0){
      indestrutivel--;
    }

    anguloDeRotacao= anguloDeRotacao+ incremento;

    if(anguloDeRotacao >= 15){ incremento= -0.005;}
    if(anguloDeRotacao <= -15){ incremento= 0.005;}


    glColor3f( 1, 1, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, turtle);

    e1.altura = 80;
    e1.largura = 60;
    inimigo1();
    e1.x= e1.x - xVelocidade;


if(felicidade==0)  {glBindTexture(GL_TEXTURE_2D, sad); }
if(felicidade==1)  {glBindTexture(GL_TEXTURE_2D, felizo);}
    e2.altura = 160;
    e2.largura = 80;
    inimigo2();
    e2.x= e2.x - xVelocidade;


    glBindTexture(GL_TEXTURE_2D, cout);
    e4.altura = 80;
    e4.largura = 40;
    inimigoVoador();


    glBindTexture(GL_TEXTURE_2D, matinho);
    m1.altura = 80;
    m1.largura = 40;
    mundo1();
    m1.x= m1.x - (xVelocidade/1.2);



switch(skin){
 case 1: glBindTexture(GL_TEXTURE_2D, icon_skin1); break;
  case 2: glBindTexture(GL_TEXTURE_2D, icon_skin2); break;
   case 3: glBindTexture(GL_TEXTURE_2D, icon_skin3); break;
    case 4: glBindTexture(GL_TEXTURE_2D, icon_skin4); break;
    case 5: glBindTexture(GL_TEXTURE_2D, icon_skin5); break;
}
    glColor3f(1, 1, 1);

        if(pulo==1){
          switch(skin){
           case 1: glBindTexture(GL_TEXTURE_2D, jump_skin1); break;
            case 2: glBindTexture(GL_TEXTURE_2D, jump_skin2); break;
             case 3: glBindTexture(GL_TEXTURE_2D, jump_skin3); break;
              case 4: glBindTexture(GL_TEXTURE_2D, jump_skin4); break;
              case 5: glBindTexture(GL_TEXTURE_2D, jump_skin5); break;
          }



         }

        if(abaixado==0){
        p.altura = 140;
        }
        if(abaixado==1){
          switch(skin){
           case 1: glBindTexture(GL_TEXTURE_2D, down_skin1); break;
            case 2: glBindTexture(GL_TEXTURE_2D, down_skin2); break;
             case 3: glBindTexture(GL_TEXTURE_2D, down_skin3); break;
              case 4: glBindTexture(GL_TEXTURE_2D, down_skin4); break;
              case 5: glBindTexture(GL_TEXTURE_2D, down_skin5); break;
          }
         p.altura = 70;
        }
        p.largura = 80;

        if(indestrutivel%5==0){
          jogador();
        }



    glColor3f(1, 1, 1);
glBindTexture(GL_TEXTURE_2D, guacamole2);
    c1.altura = 60;
    c1.largura = 30;
    coin1();
    c1.x= c1.x - xVelocidade;
 glDisable(GL_TEXTURE_2D);

glColor3f(1, 1, 1);

    montanha();

}

void desenhaPRLX(){

sky= sky + 1;

sun= sun + 0;

cloud= cloud + 2;

mountain= mountain + 5;

sky2= sky2 + 1;

sun2= sun2 + 0;

cloud2= cloud2 + 2;

mountain2= mountain2 + 5;



if(sky>= 2560){
sky = -2560;
}

if(sky2>= 2560){
sky2 = -2560;
}

if(sun>= 2560){
sun = -2560;
}

if(sun2>= 2560){
sun2 = -2560;
}

if(cloud>= 2560){
cloud = -2560;
}

if(cloud2>= 2560){
cloud2 = -2560;
}

if(mountain>= 2560){
mountain = -2560;
}

if(mountain2>= 2560){
mountain2 = -2560;
}


    glEnable(GL_TEXTURE_2D);


glBindTexture(GL_TEXTURE_2D, PRLXsky);
    HitBox( - sky, -720, 2*720, 1280);
        HitBox( - sky2, -720, 2*720, 1280);

glBindTexture(GL_TEXTURE_2D, PRLXsun);
    HitBox( - sun, -720, 2*720, 1280);
        HitBox( - sun2, -720, 2*720, 1280);

glBindTexture(GL_TEXTURE_2D, PRLXcloud);
    HitBox( - cloud, -720, 2*720, 1280);
        HitBox( - cloud2, -720, 2*720, 1280);

/*
glBindTexture(GL_TEXTURE_2D, PRLXmontanha);
    HitBox( - mountain, -720, 2*720, 1280);
        HitBox( - mountain2, -720, 2*720, 1280);
*/









   glDisable(GL_TEXTURE_2D);
}
