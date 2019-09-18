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
#include "save.h"

void testeColisao(){
    colisao(e1);
    colisao(e4);
    colisao(e2);
    colisao(c1);
}

void colisao(struct coordenadas alvo){


    if( ((alvo.y + alvo.altura) > (p.y) && (alvo.y+ alvo.altura) < (p.y+ p.altura) &&
        (alvo.x - alvo.largura) < (p.x + p.largura) && (alvo.x - alvo.largura) > (p.x - p.largura))
        || ((alvo.y + alvo.altura) > (p.y+ p.altura) && (alvo.y) < (p.y+ p.altura) &&
        (alvo.x - alvo.largura) < (p.x + p.largura) && (alvo.x - alvo.largura) > (p.x - p.largura))
        ||((alvo.y + alvo.altura) > (p.y) && (alvo.y+ alvo.altura) < (p.y+ p.altura) &&
        (alvo.x + alvo.largura) < (p.x + p.largura) && (alvo.x + alvo.largura) > (p.x - p.largura))
        || ((alvo.y + alvo.altura) > (p.y+ p.altura) && (alvo.y) < (p.y+ p.altura) &&
        (alvo.x + alvo.largura) < (p.x + p.largura) && (alvo.x + alvo.largura) > (p.x - p.largura)
        )){
          if(alvo.x==c1.x && alvo.y == c1.y){
            carry++;
            c1.x = 1300;
          }else if(indestrutivel==0){
            if(alvo.x==e2.x && alvo.y == e2.y){
              felicidade=1;
              point= point + carry;
              carry=0;
              tempo=0;
            }else if(carry==0){
                parar_musica();
                moeda += point;
                saveMoeda();
                saveRecord();
                savePoint=point;
                point=0;
                tela=5;
                iniciaGame();
                tocar_musica("./../source/musica/gfriend.ogg", -1);
            } else if(carry>0){
                carry=0;
                indestrutivel=50;
            }
          }
        }
}
