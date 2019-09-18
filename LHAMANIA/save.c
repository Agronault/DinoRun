#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <string.h>

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
#include "save.h"

struct pontuacao rec[11];

void saveMoeda(){
    FILE *arq;
    arq = fopen ("./../save/moeda.bin", "wb");
 //   arq = fopen ("moeda.bin", "wb");
    if (arq == NULL ){
        printf ("Nao foi possivel criar o arquivo bin");
    } else{
        sprintf(pts,"%d", moeda);
        fwrite(&moeda, sizeof(int), 1, arq);
    }
    fclose(arq);
}

void loadMoeda(){
    FILE *arqL;
    arqL = fopen("./../save/moeda.bin", "rb");
 //   arqL = fopen("moeda.bin", "rb");
    if(arqL == NULL){
       // printf("Nao foi possivel carregar arquivo bin");
        moeda = 0;
    }else {
        fread(&moeda, sizeof(int), 1, arqL);
    }
    fclose(arqL);
}

void saveRecord(){
    salvar();
    ordenar();

    FILE *arqR;
    arqR = fopen("./../save/record.txt", "wb");
 //   arqR = fopen("record.txt", "wb");
    if(arqR == NULL){
        printf("Nao foi possivel criar o arquivo txt");
    } else{
    fwrite(rec,sizeof(struct pontuacao), 10, arqR);

    }

    fclose(arqR);
}

void loadRecord(){
    int m;

    for(m=0; m<10;m++){
        strcpy(rec[m].name,"x");
        strcpy(rec[m].record,"0");
    }

    FILE *arqL;
    arqL = fopen("./../save/record.txt", "rb");
 //   arqL = fopen("record.txt", "rb");
    if(arqL == NULL){
      //  printf("Nao foi possivel carregar o arquivo txt");
    } else{
        fread(rec, sizeof(struct pontuacao), 10, arqL);
    }
    fclose(arqL);
}

void salvar(){
    int m, igual=0;
    char buffer[10];

    for(m=0;m<10;m++){
        if(igual==0){
            if(strcmp(nick,rec[m].name)==0){
                if(point>atoi(rec[m].record)){
                    snprintf(buffer, 10,"%d", point);
                    strcpy(rec[m].record,buffer);
                }
                igual=1;
            }
        }
    }


    for(m=0;m<10;m++){
        if(igual==0){
            if(strcmp(rec[m].name, "x")==0 && atoi(rec[m].record)==0 && point>0){
                strcpy(rec[m].name, nick);
                snprintf(buffer, 10,"%d", point);
                strcpy(rec[m].record, buffer);
                igual=1;
            } else{
                strcpy(rec[10].name, nick);
                snprintf(buffer, 10,"%d", point);
                strcpy(rec[10].record,buffer);
                igual=1;
            }
        }
    }
    igual=0;
}

void ordenar(){
    int m, n, igual=0;
    char buffer[10];
    char auxPt[10];
    char auxName[20];
    auxPt[0] = '\0';
    auxName[0] = '\0';

    for(m=0;m<11;m++){
        for(n=0;n<11;n++){
            if(atoi(rec[m].record)>atoi(rec[n].record)){
                strcpy(auxName, rec[m].name);
                strcpy(rec[m].name, rec[n].name);
                strcpy(rec[n].name, auxName);

                strcpy(auxPt, rec[m].record);
                strcpy(rec[m].record, rec[n].record);
                strcpy(rec[n].record,auxPt);
            }
        }
    }

/*    for(m=0;m<11;m++){
        if(igual==0){
            if(strcmp(rec[m].name, "x")==0 && atoi(rec[m].record)==0 && point==0){
                strcpy(rec[m].name, nick);
                snprintf(buffer, 10,"%d", point);
                strcpy(rec[m].record, buffer);
                igual=1;
            }
        }
    }*/

    for(m=0; m<11; m++){
        for(n=0; n<20; n++){
            if(rec[m].name[n]=='\0'){
                while(n<20){
                    rec[m].name[n] = '\0';
                    n++;
                }
            }
        }
        for(n=0; n<10; n++){
            if(rec[m].record[n]=='\0'){
                while(n<10){
                    rec[m].record[n] = '\0';
                    n++;
                }
            }
        }
    }
}
