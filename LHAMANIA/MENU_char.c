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
#include "MENU_char.h" //mander
#include "MENU_credit.h"
#include "MENU_icons.h"
#include "MENU_inventario.h"
#include "MENU_util.h"
#include "texto.h"

void MENU_load(){

  icon_cursor = SOIL_load_OGL_texture(
        "../source/misc/cursor.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 icon_skin1 = SOIL_load_OGL_texture(
        "../source/char/animCHAR.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_skin2 = SOIL_load_OGL_texture(
        "../source/char/animCHAR2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_skin3 = SOIL_load_OGL_texture(
        "../source/char/animCHAR3.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_skin4 = SOIL_load_OGL_texture(
        "../source/char/animCHAR4.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  icon_skin5 = SOIL_load_OGL_texture(
        "../source/char/animCHAR5.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  jump_skin1 = SOIL_load_OGL_texture(
       "../source/char/jumpCHAR.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );

 jump_skin2 = SOIL_load_OGL_texture(
       "../source/char/jumpCHAR2.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );

 jump_skin3 = SOIL_load_OGL_texture(
       "../source/char/jumpCHAR3.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );

 jump_skin4 = SOIL_load_OGL_texture(
       "../source/char/jumpCHAR4.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );

 jump_skin5 = SOIL_load_OGL_texture(
       "../source/char/jumpCHAR5.png",
       SOIL_LOAD_AUTO,
       SOIL_CREATE_NEW_ID,
   SOIL_FLAG_INVERT_Y
 );


 down_skin1 = SOIL_load_OGL_texture(
      "../source/char/downANIM.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);

down_skin2 = SOIL_load_OGL_texture(
      "../source/char/downANIM2.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);

down_skin3 = SOIL_load_OGL_texture(
      "../source/char/downANIM3.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);

down_skin4 = SOIL_load_OGL_texture(
      "../source/char/downANIM4.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);

down_skin5 = SOIL_load_OGL_texture(
      "../source/char/downANIM5.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);




	icon_avatar1 = SOIL_load_OGL_texture(
        "../source/char/skin1_icon.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_avatar2 = SOIL_load_OGL_texture(
        "../source/char/skin2_icon.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_avatar3 = SOIL_load_OGL_texture(
        "../source/char/skin3_icon.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	icon_avatar4 = SOIL_load_OGL_texture(
        "../source/char/skin4_icon.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  icon_avatar5 = SOIL_load_OGL_texture(
        "../source/char/skin5_icon.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);



  cout = SOIL_load_OGL_texture(
        "../source/char/COUTanim2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  montanhatex= SOIL_load_OGL_texture(
        "../source/char/gramaANIM.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  matinho= SOIL_load_OGL_texture(
        "../source/char/arbusto.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);




	 icon_menu_controle = SOIL_load_OGL_texture(
        "../source/misc/controle.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 icon_menu_credit = SOIL_load_OGL_texture(
        "../source/misc/credit.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 icon_menu_exit = SOIL_load_OGL_texture(
        "./../source/misc/exit.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 icon_menu_tip = SOIL_load_OGL_texture(
        "./../source/misc/tip.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 icon_menu_play = SOIL_load_OGL_texture(
        "./../source/misc/play.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

    icon_menu_splash = SOIL_load_OGL_texture(
        "./../source/UI/lhamaSplash.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

  PRLXsky = SOIL_load_OGL_texture(
      "./../source/paralax/PRLX_sky.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);


PRLXsun = SOIL_load_OGL_texture(
    "./../source/paralax/PRLX_sun.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

PRLXcloud = SOIL_load_OGL_texture(
    "./../source/paralax/PRLX_cloud.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

PRLXmontanha = SOIL_load_OGL_texture(
    "./../source/paralax/PRLX_montanha.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

turtle = SOIL_load_OGL_texture(
    "./../source/char/turtleANIM.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

splash = SOIL_load_OGL_texture(
    "./../source/char/poster.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

guacamole2 = SOIL_load_OGL_texture(
    "./../source/char/guacamole2.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

creditos = SOIL_load_OGL_texture(
    "./../source/UI/creditos.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);


sad = SOIL_load_OGL_texture(
    "./../source/char/humanoSAD.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);

felizo = SOIL_load_OGL_texture(
    "./../source/char/humanoFELIZ.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);


}



void desenhaMenu (){

glColor3f(1, 1, 1);


desenhaFundo();

desenhaIcons();

glColor3f(0, 0, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_24, nick, 615, 215, 0);
glColor3f(1, 1, 1);
}

void desenhaControles(){

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, icon_menu_splash);

HitBox(0, -720, 2*720, 1280);

      glDisable(GL_TEXTURE_2D);


}
