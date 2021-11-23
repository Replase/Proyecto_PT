#include "cargadorOBJ.cpp"
#include <stdlib.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <vector>
#define STB_IMAGE_IMPLEMENTATION
//Se cargan los modelos.
//muebles  
ModeloOBJ mesa("modelos2/mesita.obj","texturas/madera.jpg");

ModeloOBJ escritorio2("modelos2/escritorio2.obj","texturas/madera0.jpg");
ModeloOBJ telefono("modelos2/telefono.obj","texturas/gris2.jpg");
//among 2
ModeloOBJ mochila("./modelos2/mochila.obj", "./texturas/militar.jpg");
ModeloOBJ torso("./modelos2/torso.obj");
ModeloOBJ visor("./modelos2/visor.obj");

//Las texturas deben tener ina resolucion cuadrada mxm
//Pisos
//ModeloOBJ pisodepasillo11("modelos/Pisos/Piso11.obj","texturas/wood_table_001_diff_4k.jpg");

typedef struct Frame{
    //traslacion
    float px;
    float py;
    float pz;
    //rotacion
    float rx;
    float ry;
    float rz;
    //escala
    float sx;
    float sy;
    float sz;
}frame;

frame f,f2;
ModeloOBJ pisodepasillo11("modelos2/piso1.obj","texturas/piso1.jpg");
ModeloOBJ cuarto("modelos/cuarto.obj","texturas/gris1.jpg");
ModeloOBJ cuartop("modelos/pisocuert.obj","texturas/black.jpg");
ModeloOBJ muroa("modelos/muro.obj","texturas/pared2.jpg");
ModeloOBJ pisodepasillo12("modelos/Pisos/Piso12.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo21("modelos/Pisos/Piso21.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo22("modelos/Pisos/Piso22.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo23("modelos/Pisos/Piso23.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillounion("modelos/Pisos/PisoUnion.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillounion2("modelos/Pisos/Pisounion2.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ silla("modelos/GreenChair_01_4k.obj","texturas/GreenChair_01_diff_4k.jpg");
//Paredes 
//ModeloOBJ paredespasillo1("modelos/Paredes/Paredes1.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ paredespasillo1("modelos2/paredes1.obj","texturas/pared1.jpg");//uwu
//ModeloOBJ paredespasillo2("modelos/Paredes/Paredes2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ paredespasillo2("modelos2/paredes2.obj","texturas/pared2.jpg");

//Muros
//ModeloOBJ murospasillo2("modelos/Muros/Muros.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ murospasillo2("modelos2/muros.obj","texturas/muros1.jpg");

//Techos
//ModeloOBJ techospasillo1("modelos/Techos/Techos1.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techospasillo1("modelos2/techo1.obj","texturas/techo1.jpg");


ModeloOBJ techospasillo2("modelos/Techos/Techos2.obj","texturas/skulls.jpg");
ModeloOBJ techosegundopiso("modelos/Techos/Techos3.obj","texturas/pared2.jpg");
//segundo piso
ModeloOBJ segundopiso("modelos/p2.obj","texturas/fs.jpg");
//Adorno
ModeloOBJ adorno("modelos/Pisos/Adorno.obj");

//Animacion
ModeloOBJ among("modelos2/Among2.obj","texturas/amongusTextura.jpg");
ModeloOBJ vocho("modelos/Animaciones/vocho.obj","texturas/vocho.png");
//Materiales among 
void color_negro_plastic(){
    GLfloat mat_ambient[] ={0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat mat_diffuse[] ={0.01f, 0.01f, 0.01f, 1.0f };
    GLfloat mat_specular[] ={0.50f, 0.50f, 0.50f, 1.0f };
    GLfloat shine =32.0 ;
  
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shine);
}
void color_rojo(){
    GLfloat mat_ambient[] ={ 0.0f,0.00f,0.00f,1.0f };
    GLfloat mat_diffuse[] ={0.5f,0.0f,0.0f,1.0f };
    GLfloat mat_specular[] ={0.07f,0.6f,0.6f,1.0f };
    GLfloat shine =25;
   

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shine);
}
void color_blanco(){
    GLfloat mat_ambient[] ={ 0.87f, 0.87f, 0.87f, 1.0f };
    GLfloat mat_diffuse[] ={0.21f, 0.21f, 0.21f, 1.0f };
    GLfloat mat_specular[] ={0.296648f, 0.296648f, 0.296648f, 1.0f };
    GLfloat shine =20;


    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shine);
}


void aplicar_material_chrome(){
    //Definición de las componentes ambiental, difusa, especular y brillo.
    GLfloat comp_amb[] = {0.0f, 0.2f, 0.0f, 1.0f  };
    GLfloat comp_dif[] = {0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat comp_esp[] = {0.774597f, 0.774597f, 0.774597f, 1.0f };
    GLfloat emision[] ={.1,.1,.1,.1};
    GLfloat shine = 76.8f;
    //Aplicación de las componentes ambiental, difusa, especular y brillo.
    glMaterialfv(GL_FRONT, GL_AMBIENT, comp_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, comp_dif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, comp_esp);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);
    glMaterialfv(GL_FRONT, GL_SHININESS, &shine);
}
void dibujar_among_mochila(){  
    glPushMatrix();
        glTranslated(0.5,0,1.1);
        glRotatef(180, 0, 1, 0);
        glScalef(.15,.15,.15);
        mochila.dibujar();
        color_rojo();
        torso.dibujar();
        color_negro_plastic();
        visor.dibujar();
        color_blanco();
    glPopMatrix();

   
}



void dibujar_muebles(){  
    glPushMatrix();
        glTranslated(0.455,0.02,-1.1);
        glScalef(.0002,.0004,.0004);
        mesa.dibujar();
    glPopMatrix();

    glPushMatrix();
        glTranslated(3.05,-0.025,-4.6);
        glRotatef(-90,0,1,0);
        glScalef(.028,.025,.0435);
        escritorio2.dibujar();
    glPopMatrix();
    glPushMatrix();
        glTranslated(3.4,0.0,-3.4);
        glScalef(.4,.4,.4);
        glRotatef(-135,0,1,0);
        silla.dibujar();
    glPopMatrix();
    glPushMatrix();
        glTranslated(2.99,0.245,-4.55);
        glRotatef(-90,0,1,0);
        glScalef(.03,.030,.030);
        telefono.dibujar();
    glPopMatrix();
}

void dibujar_among() {
    
    glTranslatef(-6, 0, 0);
        glTranslatef(f.px, f.py, f.pz);
        glRotatef(f.rx, 1, 0, 0);
        glRotatef(f.ry, 0, 1, 0);
        glRotatef(f.rz, 0, 0, 1);
        glScalef(f.sx, f.sy, f.sz);
        among.dibujar();
    
}
void dibujar_paredes_pasillo1(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        paredespasillo1.dibujar();
    glPopMatrix();
}
void dibujar_paredes_pasillo2(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        paredespasillo2.dibujar();
    glPopMatrix();
}
void dibujar_pisos_pasillo1(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        pisodepasillo11.dibujar();
        pisodepasillo12.dibujar();
        pisodepasillounion.dibujar();
        pisodepasillounion2.dibujar();
        dibujar_among();
    glPopMatrix();
}
void dibujar_pisos_pasillo2(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        pisodepasillo21.dibujar();
        pisodepasillo22.dibujar();
        pisodepasillo23.dibujar();
    glPopMatrix();
}
void dibujar_muros_pasillo2(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        murospasillo2.dibujar();
    glPopMatrix();
}
void dibujar_techos_pasillo1(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        techospasillo1.dibujar();
    glPopMatrix();
}
void dibujar_techos_pasillo2(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        techospasillo2.dibujar();
    glPopMatrix();
}
void dibujar_segundo_piso(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        muroa.dibujar();
        segundopiso.dibujar();
    glPopMatrix();
}
void dibujar_techo_segundo_piso(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        techosegundopiso.dibujar();
    glPopMatrix();
}
void dibujar_cuarto(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        cuarto.dibujar();
        cuartop.dibujar();
    glPopMatrix();
}
void dibujar_adorno(){
    glPushMatrix();
        aplicar_material_chrome();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        adorno.dibujar();
    glPopMatrix();
}


