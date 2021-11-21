#include "cargadorOBJ.cpp"
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
//Se cargan los modelos.
//muebles  
ModeloOBJ mesa("modelos2/mesita.obj","texturas/madera.jpg");

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

ModeloOBJ pisodepasillo12("modelos/Pisos/Piso12.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo21("modelos/Pisos/Piso21.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo22("modelos/Pisos/Piso22.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillo23("modelos/Pisos/Piso23.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillounion("modelos/Pisos/PisoUnion.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodepasillounion2("modelos/Pisos/Pisounion2.obj","texturas/wood_table_001_diff_4k.jpg");
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


ModeloOBJ techospasillo2("modelos/Techos/Techos2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techosegundopiso("modelos/Techos/Techos3.obj","texturas/beige_wall_001_diff_4k.jpg");
//segundo piso
ModeloOBJ segundopiso("modelos/SegPisp/Segundopiso.obj","texturas/beige_wall_001_diff_4k.jpg");
//Adorno
ModeloOBJ adorno("modelos/Pisos/Adorno.obj");

//Animacion
ModeloOBJ among("./modelos/Animaciones/among.obj");
ModeloOBJ vocho("modelos/Animaciones/vocho.obj","texturas/vocho.png");

void aplicar_material_chrome(){
    //Definición de las componentes ambiental, difusa, especular y brillo.
    GLfloat comp_amb[] = {0.25f, 0.25f, 0.25f, 1.0f  };
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
void dibujar_vocho(){
    glPushMatrix();
        glTranslatef(3, 0, 0);
        glScalef(.25,.25,.25);
        glTranslatef(f2.px, f2.py, f2.pz);
        glRotatef(f2.rx, 1, 0, 0);
        glRotatef(f2.ry, 0, 1, 0);
        glRotatef(f2.rz, 0, 0, 1);
        glScalef(f2.sx, f2.sy, f2.sz);
        vocho.dibujar();
    glPopMatrix();
}
void dibujar_muebles(){
    
        
    glPushMatrix();
        glTranslated(0.45,0.12,-1.1);
        glScalef(.0002,.0004,.0004);
        
        //glRotatef(180,0,1,0);
        mesa.dibujar();
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
void dibujar_adorno(){
    glPushMatrix();
        aplicar_material_chrome();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        adorno.dibujar();
    glPopMatrix();
}
