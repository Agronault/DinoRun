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



int main(int argc, char **argv){

    system("clear");
    printf("___________________________\n\n\n\nDigite seu nick:\n");
    scanf("%[^\n]s", nick);

    system("clear");
    printf("___________________________\n\n\n\nVocê está jogando como: \n%s\n\n\n\n___________________________\n", nick);

    d.x = 1280;
    d.y = 720;


    glutInit(&argc, argv);
    glutTimerFunc(0, frame, 0);

    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(d.x, d.y);
    glutInitWindowPosition(0, 0);


    glutCreateWindow("Lhamania");


    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(teclado);
    glutKeyboardUpFunc(keyUp);
    inicializa();




    glutMainLoop();
    return 0;
}
