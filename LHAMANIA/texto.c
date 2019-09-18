#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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

void escreveTexto(void * font, char *s, float x, float y, float z) {
    int j;
    glRasterPos3f(x, y, z);

    for (j = 0; j < strlen(s); j++) {
        glutBitmapCharacter(font, s[j]);
    }
}
