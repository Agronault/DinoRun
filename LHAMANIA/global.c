#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

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

int pulo = 0;
int sobe = 1;
int pause = 1;

int xVelocidade= 15;
float i = 1;

int skin=2;
int felicidade=0;
int tela=0;

int tempo = 200;

int sky = 0;
int sun= 0;
int cloud = 0;
int mountain = 0;
//-----------------
int sky2 = -2560;
int sun2 = -2560;
int cloud2 = -2560;
int mountain2 = -2560;

float f5f=0;
float f10f=0;
float fmf=0;



int point=0;
int carry=0;
int indestrutivel=0;
int moeda;
char nick[15];
char pts[100];


int randomic;
int hard= 10000;
int contador= 0;


float anguloDeRotacao = -15;
float incremento= 0.005;
int chao = -200;
int cursor=0;

int abaixado=0;

void HitBox(int x, int y, int altura, int largura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0, 0);  glVertex3f(-largura+x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(1, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0, 1);  glVertex3f(-largura+x, altura+y, 0);
    glEnd();
}


void HitBox5f(int x, int y, int altura, int largura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0+ f5f, 0);  glVertex3f(-largura+x, y, 0);
        glTexCoord2f(0.2+ f5f, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(0.2+ f5f, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0+ f5f, 1);  glVertex3f(-largura+x, altura+y, 0);
    glEnd();
}


void HitBox10f(int x, int y, int altura, int largura){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0+ f10f, 0);  glVertex3f(-largura+x, y, 0);
        glTexCoord2f(0.1+ f10f, 0); glVertex3f(largura+x, y, 0);
        glTexCoord2f(0.1+ f10f, 1); glVertex3f(largura+x, altura+y, 0);
        glTexCoord2f(0+ f10f, 1);  glVertex3f(-largura+x, altura+y, 0);
    glEnd();
}


void montanha(){
switch(skin){
default:


fmf= fmf+ 0.0005;
if(fmf>=0.93){fmf=0;}


    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);
    glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, montanhatex);
    glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(0+ fmf, 0);    glVertex3f(-1500, chao, 0);
            glTexCoord2f(0.1+ fmf, 0);  glVertex3f(1500, chao, 0);
            glTexCoord2f(0.1+ fmf, 1);  glVertex3f(1500, -1300, 0);
            glTexCoord2f(0+ fmf, 1);    glVertex3f(-1500, -1300, 0);
    glEnd();
glDisable(GL_TEXTURE_2D);
    glPopMatrix();
break;
}
}

void jogador(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);
    HitBox10f(p.x, p.y, p.altura, p.largura);
    glPopMatrix();
}

void inimigo1(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);

    HitBox10f(e1.x, e1.y, e1.altura, e1.largura);

    if(e1.x<= -1280){
      randomic= rand()%hard;
        e1.x= 1280 + randomic;
    }
    glPopMatrix();
}

void inimigo2(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);

    HitBox(e2.x, e2.y, e2.altura, e2.largura);

    if(e2.x<= -1280){
      felicidade=0;
        e2.x= 5580;
    }
    glPopMatrix();
}

void inimigo3(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);

    HitBox(e3.x, e3.y, e3.altura, e3.largura);
    if(e3.x<= -1280){
        e3.x= 1280;
    }
    glPopMatrix();
}


void mundo1(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);

    HitBox(m1.x, m1.y, m1.altura, m1.largura);
    if(m1.x<= -1280){
        m1.x= 1280;
    }
    glPopMatrix();
}

void inimigoVoador(){
  float lados=120;
  float angRot = (2*M_PI)/lados;
  if(i<lados){
    i++;
  } else{
    i=1;
  }
  float raio = 13;
  e4.x += raio*cos(i*angRot) - xVelocidade/1.25;
  e4.y += raio*sin(i*angRot);

  glPushMatrix();
  glRotatef(anguloDeRotacao, 0, 0, 1);

  HitBox5f(e4.x, e4.y, e4.altura, e4.largura);
  if(e4.x <= -1280){
    randomic= rand()%hard;
      e4.x= 1280+ randomic;
  }
  glPopMatrix();
}

void iniciaGame(){

  p.x=-500;
  p.y=chao;

  e1.x = 1280;
  e1.y = chao;

  m1.x = 1280;
  m1.y = chao;

  e4.x = 1680;
  e4.y = -100;
  i=1;
  tempo=160;

  e2.x = 3000;
  e2.y= chao;

  c1.x = 1280;
  point = 0;

  anguloDeRotacao = -15;

  loadMoeda();
  loadRecord();
}



void coin1(){
    glPushMatrix();
    glRotatef(anguloDeRotacao, 0, 0, 1);

    HitBox(c1.x, c1.y, c1.altura, c1.largura);
    if(c1.x<= -1280){
        c1.x= 1280;
    }
    glPopMatrix();
}
