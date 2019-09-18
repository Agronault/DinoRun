CC=gcc
OPCOES_COMPILADOR=-I. -lglut -lGLU -lGLEW -lGL -lSDL -lSDL_mixer -lSOIL -lm
TODOS_ARQUIVOS_PONTOH =
TODOS_ARQUIVOS_OBJ = main.o colisao.o desenha_cena.o GAME.o global.o inicializa.o MENU_char.o MENU_credit.o MENU_icons.o MENU_inventario.o MENU_util.o teclado.o texto.o save.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	./main

clean:
	rm *.o main
