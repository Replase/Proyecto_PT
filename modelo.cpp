#include "cargadorOBJ.cpp"
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
//Se cargan los modelos.
//Las texturas deben tener ina resolucion cuadrada mxm
//Pisos
//ModeloOBJ pisodepasillo11("modelos/Pisos/Piso11.obj","texturas/wood_table_001_diff_4k.jpg");
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
ModeloOBJ murospasillo2("modelos/Muros/Muros.obj","texturas/beige_wall_001_diff_4k.jpg");
//Techos
ModeloOBJ techospasillo1("modelos/Techos/Techos1.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techospasillo2("modelos/Techos/Techos2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techosegundopiso("modelos/Techos/Techos3.obj","texturas/beige_wall_001_diff_4k.jpg");
//segundo piso
ModeloOBJ segundopiso("modelos/SegPisp/Segundopiso.obj","texturas/beige_wall_001_diff_4k.jpg");



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
void dibujar_cubo(){
    glPushMatrix();
        glutSolidCube(.2);
        glTranslatef(0,.5,0);
    glPopMatrix();
}