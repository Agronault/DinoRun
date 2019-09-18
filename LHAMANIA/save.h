#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

struct pontuacao {
    char name[20];
    char record[10];
};

struct pontuacao rec[11];

void saveMoeda();
void loadMoeda();
void saveRecord();
void loadRecord();
void salvar();
void ordenar();

#endif // SAVE_H_INCLUDED
