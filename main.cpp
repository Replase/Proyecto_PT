#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "camara.cpp"
#include "modelo.cpp"
#define STB_IMAGE_IMPLEMENTATION
#define VELOCIDAD_MOV .1 //vel de movimiento
#define VELOCIDAD_MOV2 3 //rotar arriba abajo
#define VELOCIDAD_ROT 0.25 //rotar derecha izquerda
#define NUM_KF 5
#define NUM_F 10   //fragmentos entre cada frame clave
#define FPS 30  //miniimo de fps para ser animacion


//Variables para interacción con el usuario.
GLfloat tx = 0;
GLfloat ty = 0;
GLfloat tz = 0;
GLfloat rx = 0;
GLfloat ry = 0;
GLfloat rz = 0;
GLfloat esc = 1;

//Creación del objeto de cámara.
Camara cam (0,.5,2,    //Cámara posicionada en el centro.
            0,.5,-1,    //Cámara viendo hacia el fondo de la pantalla (-Z)
            0, 1, 0);   //Cámara sin rotación (UP = +Y)
//Rotación de la cámara sobre su eje X local (voltear arriba y abajo.)
GLfloat rotX = 0.0f;

//GLfloat rz = -20;
//GLfloat bx = 0;
//GLfloat by= 1;

GLfloat es = 1;
GLboolean proy_orto = GL_FALSE;
GLboolean somb_plano = GL_FALSE;
GLboolean reproduciendo = GL_TRUE;


frame kf[NUM_KF]={{0,0,0,  0,0,0,  1,1,1},
                {-5,0,0,     0,0,0, 1,1,1},
                {-10,0,0,     0,0,0,  1,1,1},
                {-5,0,0,    0,0,0,  1,1,1},
                {0,0,0,    0,0,0,  1,1,1}};
int i_kf = 0;
int i_f = 0;

//Se dibujan los modelos, con sus transformaciones correspondientes.
//animacion
void animacion(int value){
    if(reproduciendo){
        if(i_kf == 0 && i_f == 0){
            f = kf[0];
        }else{
            f.px += (kf[i_kf+1].px-kf[i_kf].px)/NUM_F;
            f.py += (kf[i_kf+1].py-kf[i_kf].py)/NUM_F;
            f.pz += (kf[i_kf+1].pz-kf[i_kf].pz)/NUM_F;

            f.rx += (kf[i_kf+1].rx-kf[i_kf].rx)/NUM_F;
            f.ry += (kf[i_kf+1].ry-kf[i_kf].ry)/NUM_F;
            f.rz += (kf[i_kf+1].rz-kf[i_kf].rz)/NUM_F;

            f.sx += (kf[i_kf+1].sx-kf[i_kf].sx)/NUM_F;
            f.sy += (kf[i_kf+1].sy-kf[i_kf].sy)/NUM_F;
            f.sz += (kf[i_kf+1].sz-kf[i_kf].sz)/NUM_F;
        }
        i_f ++;
        if(i_f >= NUM_F){
            i_kf ++;
            i_f = 0;
            if(i_kf >= NUM_KF-1){
                i_kf = 0;
                i_f = 0;
            }
        }
        glutPostRedisplay();
    }
    glutTimerFunc(1000/FPS,animacion,0);

}

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

void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
        ejes();
        glRotatef(rotX, 1.0f, 0.0f, 0.0f);
        gluLookAt(cam.mPos.x,  cam.mPos.y,  cam.mPos.z,
                cam.mView.x, cam.mView.y, cam.mView.z,
                cam.mUp.x,   cam.mUp.y,   cam.mUp.z);
        //dibujar_among();
        dibujar_paredes_pasillo1();
        dibujar_paredes_pasillo2();
        dibujar_pisos_pasillo1();
        dibujar_pisos_pasillo2();
        dibujar_muros_pasillo2();
        dibujar_techos_pasillo1();
        dibujar_techos_pasillo2();
        dibujar_segundo_piso();
        dibujar_techo_segundo_piso();
        dibujar_adorno();
        //dibujar_among();
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

void teclado (unsigned char key, int x, int y) {
        switch (key) {
        //ANIMACION
        case 'P': case 'p':
            reproduciendo = !reproduciendo;
            break;
        case 'R': case 'r':
            i_kf =0;
            i_f =0;
            break;
	//SOMBREADO
	case ' ':
            somb_plano = !somb_plano;
            somb_plano ? glShadeModel(GL_FLAT) : glShadeModel(GL_SMOOTH);
            break;
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
    glutCreateWindow("Proyecto");
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
    animacion(0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    config_GLUT();
    config_OGL();
    glutMainLoop();
    return 0;
}