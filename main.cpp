#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "cargadorOBJ.cpp"
#include "camara.cpp"
#define STB_IMAGE_IMPLEMENTATION
#define VELOCIDAD_MOV .1
#define VELOCIDAD_MOV2 3
#define VELOCIDAD_ROT 0.5


//Variables para interacción con el usuario.
GLfloat tx = 0;
GLfloat ty = 0;
GLfloat tz = 0;
GLfloat rx = 0;
GLfloat ry = 0;
//Creación del objeto de cámara.
Camara cam (0,.5,2,    //Cámara posicionada en el centro.
            0,.5,-1,    //Cámara viendo hacia el fondo de la pantalla (+Z)
            0, 1, 0);   //Cámara sin rotación (UP = +Y)
//Rotación de la cámara sobre su eje X local (voltear arriba y abajo.)
GLfloat rotX = 0.0f;

//GLfloat rz = -20;
//GLfloat bx = 0;
//GLfloat by= 1;

GLfloat es = 1;
GLboolean proy_orto = GL_FALSE;
GLboolean somb_plano = GL_FALSE;

//Se cargan los modelos.
ModeloOBJ paredespasillo1("modelos/Paredes_pasillo1.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ paredespasillo2("modelos/Paredes_pasillo2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ pisodespasillo11("modelos/Piso_pasillo11.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodespasillo12("modelos/Piso_pasillo12.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodespasillo21("modelos/Piso_pasillo21.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodespasillo22("modelos/Piso_pasillo22.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ pisodespasillo23("modelos/Piso_pasillo23.obj","texturas/wood_table_001_diff_4k.jpg");
ModeloOBJ murospasillo2("modelos/Muros_pasillo2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techospasillo1("modelos/Techo_pasillo1.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techospasillo2("modelos/Techo_pasillo2.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ segundopiso("modelos/Segundo_piso.obj","texturas/beige_wall_001_diff_4k.jpg");
ModeloOBJ techosegundopiso("modelos/Techo_segundo_piso.obj","texturas/beige_wall_001_diff_4k.jpg");
//ModeloOBJ mundo("./modelos/esfera.obj", "./texturas/mundo_2k_volteado.jpg");

//Se dibujan los modelos, con sus transformaciones correspondientes.

//Dibujo de un plano con textura.

void ejes(void){
    glBegin(GL_LINES);
    
        glVertex3f(-10,0,0);
        glVertex3f(10,0,0);

        glVertex3f(0,-10,0);
        glVertex3f(0,10,0);

        glVertex3f(0,0,-10);
        glVertex3f(0,0,10);
    glEnd();
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
        pisodespasillo11.dibujar();
        pisodespasillo12.dibujar();
    glPopMatrix();
}
void dibujar_pisos_pasillo2(){
    glPushMatrix();
        glScalef(.2,.2,.2);
        glRotatef(180,0,1,0);
        pisodespasillo21.dibujar();
        pisodespasillo22.dibujar();
        pisodespasillo23.dibujar();
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
void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
        ejes();
        //glTranslatef(tx, ty, tz);
        //glRotatef(rx, 1, 0, 0);
        //glRotatef(ry, 0, 1, 0);
        //glScalef(es, es, es);
        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        gluLookAt(cam.mPos.x,  cam.mPos.y,  cam.mPos.z,
                cam.mView.x, cam.mView.y, cam.mView.z,
                cam.mUp.x,   cam.mUp.y,   cam.mUp.z);
        dibujar_paredes_pasillo1();
        dibujar_paredes_pasillo2();
        dibujar_pisos_pasillo1();
        dibujar_pisos_pasillo2();
        dibujar_muros_pasillo2();
        dibujar_techos_pasillo1();
        dibujar_techos_pasillo2();
        dibujar_segundo_piso();
        dibujar_techo_segundo_piso();
        dibujar_cubo();
        
    glPopMatrix();

    glutSwapBuffers();
}
void config_camara (void) {            
    float ancho = GLUT_WINDOW_WIDTH;
    float alto = GLUT_WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ancho/alto, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*void camara (void) {            
    float ancho = GLUT_WINDOW_WIDTH;
    float alto = GLUT_WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (proy_orto) {
        glOrtho(-5, 5, -5, 5, -5, 5);    
    }
    else {
        gluPerspective(45, ancho/alto, 0.1, 1000);
        gluLookAt(0, .5,2 ,bx, by,rz, 0, 1, 0); //poscamara(,,), lookat(0,1,-10) up(0,2,0) 0, .5, 2, 0, 1, -100
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}*/

void teclado (unsigned char key, int x, int y) {
        switch (key) {
            //TRASLACIÓN
        case 'W': case 'w': cam.desplazarZ(VELOCIDAD_MOV); break;
        case 'S': case 's': cam.desplazarZ(-VELOCIDAD_MOV); break;
        case 'A': case 'a': cam.desplazarX(-VELOCIDAD_MOV); break;
        case 'D': case 'd': cam.desplazarX(VELOCIDAD_MOV); break;
        case '+': cam.desplazarY(VELOCIDAD_MOV); break;
        case '-': cam.desplazarY(-VELOCIDAD_MOV); break;
        //ROTACIÓN
        case 'I': case 'i': rotX -= VELOCIDAD_MOV2; break;
        case 'K': case 'k': rotX += VELOCIDAD_MOV2; break;
        case 'J': case 'j': cam.rotarY(-VELOCIDAD_ROT); break;
        case 'L': case 'l': cam.rotarY(VELOCIDAD_ROT); break;
        //PROYECCIÓN
        /*case 'P': case 'p':
            proy_orto = !proy_orto;
            camara();
            break;
        //SOMBREADO
        case ' ':
            somb_plano = !somb_plano;
            somb_plano ? glShadeModel(GL_FLAT) : glShadeModel(GL_SMOOTH);
            break;
        //TRASLACIÓN
        
        case 'W': case 'w': tz += 0.2; break;
        case 'S': case 's': tz -= 0.2; break;
        case 'A': case 'a': tx -= 0.1; break;
        case 'D': case 'd': tx += 0.1; break;
        case 'R': case 'r': ty += .1; break;
        case 'F': case 'f': ty -= .1; break;
        //ROTACIÓN
        /*case 'I': case 'i': rx += 5; break;
        case 'K': case 'k': rx -= 5; break;
        case 'J': case 'j': ry += 5; break;
        case 'L': case 'l': ry -= 5; break;

        case 'I': case 'i': bx += 1;camara(); break;
        case 'K': case 'k': bx -= 1;camara(); break;

        case '8': rz =-20; bx=0; camara();break;
        case '2': rz =20; bx=0; camara();break;
        case '4': bx =-20; rz=0; camara();break;
        case '6': bx =20; rz=0; camara();break;
        
        //ESCALA
        case '+': es += 0.1; break;
        case '-': es -= 0.1; break;*/
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void redimensionar (int ancho, int alto) {
    if (alto == 0) alto = 1;
    int lado = ancho < alto ? ancho : alto;
    glViewport((ancho - lado) / 2, (alto - lado) / 2, lado, lado);
    config_camara();
}
void luz_direccionalz1(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {0.0, 0.0, 20.0, 0.0};    
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
}
void luz_puntual(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat pos[] = {0.0, 1.0, 1.5, 1.0};    
    /*//Asignación de valores de material y posición a la luz
    glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
    //Modificación de las constantes de atenuación.
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);*/

    glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
    //Modificación de las constantes de atenuación.
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);
}
void luz_direccionalz2(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {0.0, 0.0, -20.0, 0.0};    
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT1, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
}
void luz_direccionaly1(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {0.0, 20.0, 0.0, 0.0};   
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT2, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT2, GL_POSITION, pos);
}
void luz_direccionaly2(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {0.0, -20.0, 0.0, 0.0};   
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT3, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT3, GL_POSITION, pos);
}
void luz_direccionalx1(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {20.0, 0.0, 0.0, 0.0};   
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT4, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT4, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT4, GL_POSITION, pos);
}
void luz_direccionalx2(void) {
    //Valores de las componentes ambiental, difusa, especular y la posición.
    GLfloat amb[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat dif[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat esp[] = {1.0, 1.0, 1.0, 1.0};    
    GLfloat pos[] = {-20.0, 0.0, 0.0, 0.0};   
    //Asignación de valores de material y posición a la luz.
    glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT5, GL_SPECULAR, esp);
    glLightfv(GL_LIGHT5, GL_POSITION, pos);
}
void luces() {
    //Se activa la iluminación.
    glEnable(GL_LIGHTING);
    //Se inicializan todas las luces.
    
    luz_direccionalx1();
    //luz_puntual();
    luz_direccionalx2();
    luz_direccionaly1();
    luz_direccionaly2();
    luz_direccionalz1();
    luz_direccionalz2();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHT5);
    //Se activa la luz por defecto.

}
void config_GLUT(void) {
    glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Textura");
    glutDisplayFunc(dibujar);
    glutKeyboardFunc(teclado);
    glutReshapeFunc(redimensionar);
}

void config_OGL(void) {
    glClearColor(0.2, 0.2, 0.2, 1.0);
    luces();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    config_camara();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    config_GLUT();
    config_OGL();
    glutMainLoop();
    return 0;
}