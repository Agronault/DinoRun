#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED


struct coordenadas {
    float x, y, z, altura, largura;
};

struct coordenadas vetor;
struct coordenadas alvo;
struct coordenadas d;
struct coordenadas p;
struct coordenadas e1;
struct coordenadas e2;
struct coordenadas e3;
struct coordenadas e4; //inimigo voador
struct coordenadas m1;
struct coordenadas c1;

void HitBox(int x, int y, int altura, int largura);
void HitBox5f(int x, int y, int altura, int largura);
void HitBox10f(int x, int y, int altura, int largura);

void montanha();
void jogador();
void inimigo1();
void inimigo2();
void inimigo3();
void inimigoVoador();
void mundo1();
void coin1();


int felicidade;
int tempo;
char pts[100];
void guacamole();
void iniciaGame();

int pulo;
int sobe;
float i;
int indestrutivel;
int moeda;
char nick[15];
int savePoint;
int pause;


int randomic;
int hard;
int contador;
int xVelocidade;

int sky;
int sun;
int cloud;
int mountain;
//-----------------
int sky2;
int sun2;
int cloud2;
int mountain2;

float f5f;
float f10f;
float fmf;

float anguloDeRotacao;
int chao;
int abaixado;
int tela;
int skin;
int cursor;
int point;
int carry;
float incremento;
GLuint icon_cursor;
GLuint icon_skin1;
GLuint icon_skin2;
GLuint icon_skin3;
GLuint icon_skin4;
GLuint icon_skin5;
GLuint jump_skin1;
GLuint jump_skin2;
GLuint jump_skin3;
GLuint jump_skin4;
GLuint jump_skin5;
GLuint down_skin1;
GLuint down_skin2;
GLuint down_skin3;
GLuint down_skin4;
GLuint down_skin5;
GLuint icon_menu_fundo;
GLuint icon_menu_controle;
GLuint icon_menu_credit;
GLuint icon_menu_exit;
GLuint icon_menu_tip;
GLuint icon_menu_play;
GLuint icon_menu_splash;
GLuint icon_avatar1;
GLuint icon_avatar2;
GLuint icon_avatar3;
GLuint icon_avatar4;
GLuint icon_avatar5;
GLuint PRLXsky;
GLuint PRLXsun;
GLuint PRLXcloud;
GLuint PRLXmontanha;
GLuint cout;
GLuint montanhatex;
GLuint matinho;
GLuint turtle;
GLuint splash;
GLuint creditos;
GLuint guacamole2;
GLuint sad;
GLuint felizo;
#endif
