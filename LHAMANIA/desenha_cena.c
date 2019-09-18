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
#include "GAME.h"

void frame(int a){

    float force = 9.8;

    if(pulo==1){
        p.y += ((sobe*((chao+460)-p.y))/force);

        if(p.y>(chao+420))
            sobe=-1;
        if(p.y<chao+5){
            p.y =chao;
            sobe=1;
            pulo=0;
        }
    }

    glutPostRedisplay();
    testeColisao();
    if(pause==1){
        glutTimerFunc(16, frame, 0);
    }
}

void desenhaCena(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    switch(tela){
    case(0):
        desenhaMenu();
    break;

    case(1):
        desenhaPRLX();
        desenhaGame();
    break;

    case(2):
        desenhaControles();
    break;
    case(4):
        desenhaSkins();
    break;
    case(5):
        desenhaGameOver();
    break;

    case (6):
        MENU_creditos();
    break;
    }

    glutSwapBuffers();
}
