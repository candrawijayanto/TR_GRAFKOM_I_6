#include<windows.h>
#ifdef APPLE
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GLUquadricObj *Cylinder;
GLUquadricObj *Disk;
GLfloat angle1;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);
double pin=0;

float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,750);
    glutInitWindowPosition(250,80);
    glutCreateWindow("DANIEL HARLIANO SITORUS - 672018275");
    init();

    glutDisplayFunc(tampil);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}
void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(xrot, 1,0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-100.0,-140.0,100.0);
    glVertex3f(100.0,-140.0,100.0);
    glVertex3f(100.0,-140.0,-50.0);
    glVertex3f(-100.0,-140.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(-100.0,-140.0,100.0);
    glVertex3f(-100.0,0.0,100.0);
    glVertex3f(-100.0,0.0,-50.0);
    glVertex3f(-100.0,-140.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(100.0,-140.0,100.0);
    glVertex3f(100.0,0.0,100.0);
    glVertex3f(100.0,0.0,-50.0);
    glVertex3f(100.0,-140.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-100.0,0.0,100.0);
    glVertex3f(-80.0,0.0,100.0);
    glVertex3f(-80.0,0.0,-50.0);
    glVertex3f(-100.0,0.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(100.0,0.0,100.0);
    glVertex3f(80.0,0.0,100.0);
    glVertex3f(80.0,0.0,-50.0);
    glVertex3f(100.0,0.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(100.0,0.0,100.0);
    glVertex3f(80.0,0.0,100.0);
    glVertex3f(80.0,-140.0,100.0);
    glVertex3f(100.0,-140.0,100.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-100.0,0.0,100.0);
    glVertex3f(-80.0,0.0,100.0);
    glVertex3f(-80.0,-140.0,100.0);
    glVertex3f(-100.0,-140.0,100.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-100.0,0.0,-50.0);
    glVertex3f(-80.0,0.0,-50.0);
    glVertex3f(-80.0,-140.0,-50.0);
    glVertex3f(-100.0,-140.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(100.0,0.0,-50.0);
    glVertex3f(80.0,0.0,-50.0);
    glVertex3f(80.0,-140.0,-50.0);
    glVertex3f(100.0,-140.0,-50.0);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-90.0,1.0,95.0);
    glVertex3f(-70.0,1.0,95.0);
    glVertex3f(-70.0,140.0,95.0);
    glVertex3f(-90.0,140.0,95.0);
    glEnd();

     //depan
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(-90.1,140.0,100.0);
    glVertex3f(-70.1,1.0,100.0);
    glVertex3f(-70.1,1.0,-50.0);
    glVertex3f(-90.1,140.0,-50.0);
    glEnd();




    /*
    //atap depan
    glBegin(GL_TRIANGLES);
    glColor3ub(224,255,255);
    glVertex3f(-50.0,-80.0,0.0);
    glVertex3f(50.0,-80.0,0.0);
    glVertex3f(0.0,-80.0,50.0);
    glEnd();

    //atap depan
    glBegin(GL_TRIANGLES);
    glColor3ub(0,191,255);
    glVertex3f(-100.0,-80.0,0.0);
    glVertex3f(-50.0,-80.0,0.0);
    glVertex3f(0.0,-80.0,50.0);
    glEnd();

    /*
    //atap depan
    glBegin(GL_TRIANGLES);
    glColor3ub(224,255,255);
    glVertex3f(-25.0,20.0,10.0);
    glVertex3f(25.0,20.0,10.0);
    glVertex3f(0.0,35.0,10.0);
    glEnd();

    //jendela depan kiri
    glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex3f(-20.0,0.0,10.1);
    glVertex3f(-10.0,0.0,10.1);
    glVertex3f(-10.0,10.0,10.1);
    glVertex3f(-20.0,10.0,10.1);
    glEnd();

    //jendela depan kanan
    glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex3f(10.0,0,10.1);
    glVertex3f(20.0,0,10.1);
    glVertex3f(20.0,10.0,10.1);
    glVertex3f(10.0,10.0,10.1);
    glEnd();

    //Pintu Depan
    glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex3f(-5.0,-20,10.1);
    glVertex3f(5.0,-20,10.1);
    glVertex3f(5.0,-5.0,10.1);
    glVertex3f(-5.0,-5.0,10.1);
    glEnd();


    //rumput
    glBegin(GL_QUADS);
    glColor3ub(0,255,0);
    glVertex3f(-25.0,-19.5,20.2);
    glVertex3f(25.0,-19.5,20.2);
    glVertex3f(25.0,-19.5,-40.2);
    glVertex3f(-25.0,-19.5,-40.2);
    glEnd();


    //lantai
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(-50.0,-20.0,20.0);
    glVertex3f(60.0,-20.0,20.0);
    glVertex3f(60.0,-20.0,-40.0);
    glVertex3f(-50.0,-20.0,-40.0);
    glEnd();

    //Tembok Kanan
    glBegin(GL_QUADS);
    glColor3ub(173,216,230);
    glVertex3f(25.0,-20.0,10.0);
    glVertex3f(25.0,20.0,10.0);
    glVertex3f(25.0,20.0,-30.0);
    glVertex3f(25.0,-20.0,-30.0);
    glEnd();

    //TEMBOK BELAKANG
    glBegin(GL_QUADS);
    glColor3ub(0,191,255);
    glVertex3f(-25.0,-20.0,-30.0);
    glVertex3f(25.0,-20.0,-30.0);
    glVertex3f(25.0,20.0,-30.0);
    glVertex3f(-25.0,20.0,-30.0);
    glEnd();

    //Ventilasi Tembok Belakang
    glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex3f(-10.0,0.0,-30.1);
    glVertex3f(-10.0,10.0,-30.1);
    glVertex3f(10.0,10.0,-30.1);
    glVertex3f(10.0,0.0,-30.1);
    glEnd();

    //Tembok Kiri
    glBegin(GL_QUADS);
    glColor3ub(173,216,230);
    glVertex3f(-25.0,-20.0,10.0);
    glVertex3f(-25.0,20.0,10.0);
    glVertex3f(-25.0,20.0,-30.0);
    glVertex3f(-25.0,-20.0,-30.0);
    glEnd();

    //Atap Belakang
    glBegin(GL_TRIANGLES);
    glColor3ub(224,255,255);
    glVertex3f(-25.0,20.0,-30.0);
    glVertex3f(25.0,20.0,-30.0);
    glVertex3f(0.0,35.0,-30.0);
    glEnd();

    //Atap Atas Kanan
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(0.0,35.0,10.0);
    glVertex3f(25.0,20.0,10.0);
    glVertex3f(25.0,20.0,-30.0);
    glVertex3f(0.0,35.0,-30.0);
    glEnd();

    //Atao Atas kiri
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(0.0,35.0,10.0);
    glVertex3f(-25.0,20.0,10.0);
    glVertex3f(-25.0,20.0,-30.0);
    glVertex3f(0.0,35.0,-30.0);
    glEnd();

    //Garasi
    glBegin(GL_QUADS);
    glColor3ub(224,255,255);
    glVertex3f(25.0, 10.0, 10.0);
    glVertex3f(50.0, 0.0, 10.0);
    glVertex3f(50.0, 0.0, -30.0);
    glVertex3f(25.0, 10.0, -30.0);
    glEnd();

    //Tembok kanan Garasi
    glBegin(GL_QUADS);
    glColor3ub(205,133,63);
    glVertex3f(50.0, -20.0, 10.0);
    glVertex3f(50.0, 0.0, 10.0);
    glVertex3f(50.0, 0.0, -30.0);
    glVertex3f(50.0, -20.0, -30.0);
    glEnd();

    //Tembok Belakang Garasi
    glBegin(GL_QUADS);
    glColor3ub(205,133,63);
    glVertex3f(25.0, -20.0, -30.0);
    glVertex3f(25.0, 0.0, -30.0);
    glVertex3f(50.0, 0.0, -30.0);
    glVertex3f(50.0, -20.0, -30.0);
    glEnd();

    //kursi sandaran
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-25.0,0.0,-28.0);
    glVertex3f(-10.0,0.0,-28.0);
    glVertex3f(-10.0,-10.0,-28.0);
    glVertex3f(-25.0,-10.0,-28.0);

    //duduk
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-25.0,-10.0,-28.1);
    glVertex3f(-10.0,-10.0,-28.1);
    glVertex3f(-10.0,-10.0,-19.1);
    glVertex3f(-25.0,-10.0,-19.1);
    glEnd();

    //kaki kursi depan kiri
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-25.0,-10.1,-20.1);
    glVertex3f(-25.0,-20.1,-20.1);
    glVertex3f(-25.0,-20.1,-19.1);
    glVertex3f(-25.0,-10.1,-19.1);
    glEnd();

    //kaki kursi belakang kiri
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-25.0,-10.0,-28.1);
    glVertex3f(-25.0,-20.1,-28.1);
    glVertex3f(-25.0,-20.1,-27.1);
    glVertex3f(-25.0,-10.0,-27.1);
    glEnd();

     //kaki kursi belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-10.0,-10.0,-28.1);
    glVertex3f(-10.0,-20.1,-28.1);
    glVertex3f(-10.0,-20.1,-27.1);
    glVertex3f(-10.0,-10.0,-27.1);
    glEnd();

    //kaki kursi depan kanan
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(-10.0,-10.0,-20.1);
    glVertex3f(-10.0,-20.1,-20.1);
    glVertex3f(-10.0,-20.1,-19.1);
    glVertex3f(-10.0,-10.0,-19.1);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(-8.0,-10.0,-28.1);
    glVertex3f(10.0,-10.0,-28.1);
    glVertex3f(10.0,-10.0,-19.1);
    glVertex3f(-8.0,-10.0,-19.1);
    glEnd();

     //kaki meja depan kiri
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(-8.0,-10.1,-20.1);
    glVertex3f(-8.0,-20.1,-20.1);
    glVertex3f(-8.0,-20.1,-19.1);
    glVertex3f(-8.0,-10.1,-19.1);
    glEnd();

    //kaki meja belakang kiri
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(-8.0,-10.0,-28.1);
    glVertex3f(-8.0,-20.1,-28.1);
    glVertex3f(-8.0,-20.1,-27.1);
    glVertex3f(-8.0,-10.0,-27.1);
    glEnd();

     //kaki kursi belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(10.0,-10.0,-28.1);
    glVertex3f(10.0,-20.1,-28.1);
    glVertex3f(10.0,-20.1,-27.1);
    glVertex3f(10.0,-10.0,-27.1);
    glEnd();

    //kaki kursi depan kanan
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(10.0,-10.0,-20.1);
    glVertex3f(10.0,-20.1,-20.1);
    glVertex3f(10.0,-20.1,-19.1);
    glVertex3f(10.0,-10.0,-19.1);
    glEnd();

    //lemari depan
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(12.0,0.0,-28.0);
    glVertex3f(24.0,0.0,-28.0);
    glVertex3f(24.0,-20.0,-28.0);
    glVertex3f(12.0,-20.0,-28.0);
    glEnd();

    //lemari atas
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(12.1,0.0,-28.1);
    glVertex3f(24.1,0.0,-28.1);
    glVertex3f(24.1,0.0,-30.1);
    glVertex3f(12.1,0.0,-30.1);
    glEnd();

    //lemari belakang
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(12.0,0.0,-29.9);
    glVertex3f(24.0,0.0,-29.9);
    glVertex3f(24.0,-20.0,-29.9);
    glVertex3f(12.0,-20.0,-29.9);
    glEnd();

    //Kiri lemari
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(12.0,0.0,-28.0);
    glVertex3f(12.0,-20.0,-28.0);
    glVertex3f(12.0,-20.0,-30.0);
    glVertex3f(12.0,0.0,-30.0);
    glEnd();

    //kanan lemari
    glBegin(GL_QUADS);
    glColor3ub(218,165,32);
    glVertex3f(24.0,0.0,-28.0);
    glVertex3f(24.0,-20.0,-28.0);
    glVertex3f(24.0,-20.0,-30.0);
    glVertex3f(24.0,0.0,-30.0);
    glEnd();

    //lemari garis1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(12.0,-4.0,-28.0);
    glVertex3f(24.0,-4.0,-28.0);
    glVertex3f(24.0,-5.0,-28.0);
    glVertex3f(12.0,-5.0,-28.0);
    glEnd();

    //lemari garis2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(12.0,-9.0,-28.0);
    glVertex3f(24.0,-9.0,-28.0);
    glVertex3f(24.0,-10.0,-28.0);
    glVertex3f(12.0,-10.0,-28.0);
    glEnd();

    //lemari garis3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex3f(12.0,-14.0,-28.0);
    glVertex3f(24.0,-14.0,-28.0);
    glVertex3f(24.0,-15.0,-28.0);
    glVertex3f(12.0,-15.0,-28.0);
    glEnd();

    //kasur
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(12.0,-15.0,-25.1);
    glVertex3f(24.0,-15.0,-25.1);
    glVertex3f(24.0,-15.0,0.1);
    glVertex3f(12.0,-15.0,0.1);
    glEnd();

    //Kanan kasur
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(24.0,-15.0,-25.1);
    glVertex3f(24.0,-20.0,-25.1);
    glVertex3f(24.0,-20.0,0.1);
    glVertex3f(24.0,-15.0,0.1);
    glEnd();

    //Kiri kasur
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(12.0,-15.0,-25.1);
    glVertex3f(12.0,-20.0,-25.1);
    glVertex3f(12.0,-20.0,0.1);
    glVertex3f(12.0,-15.0,0.1);
    glEnd();

    //kasur belakang
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(12.0,-10.0,-25.0);
    glVertex3f(24.0,-10.0,-25.0);
    glVertex3f(24.0,-20.0,-25.0);
    glVertex3f(12.0,-20.0,-25.0);
    glEnd();

    //kasur depan
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
    glVertex3f(12.0,-15.0,0.0);
    glVertex3f(24.0,-15.0,0.0);
    glVertex3f(24.0,-20.0,0.0);
    glVertex3f(12.0,-20.0,0.0);
    glEnd();

    //selimut
    glBegin(GL_QUADS);
    glColor3ub(0,255,255);
    glVertex3f(13.0,-15.0,-24.1);
    glVertex3f(23.0,-15.0,-24.1);
    glVertex3f(23.0,-15.0,0.1);
    glVertex3f(13.0,-15.0,0.1);
    glEnd();

    //TV
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-5.0,0.0,-25.0);
    glVertex3f(7.0,0.0,-25.0);
    glVertex3f(7.0,-10.0,-25.0);
    glVertex3f(-5.0,-10.0,-25.0);

    //Jendela Tembok Kiri
    glBegin(GL_QUADS);
    glColor3ub(188,143,143);
    glVertex3f(-25.1,5.0,5.0);
    glVertex3f(-25.1,-5.0,5.0);
    glVertex3f(-25.1,-5.0,-5.0);
    glVertex3f(-25.1,5.0,-5.0);
    glEnd();
    */
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    }else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
    case 'w':
    case 'W':
        xrot -=1;
        glTranslatef(0.0,0.0,xrot);
        break;
    case 'd':
    case 'D':
        yrot +=1;
        glTranslatef(yrot,0.0,0.0);
        break;
    case 's':
    case 'S':
        xrot +=1;
        glTranslatef(0.0,0.0,xrot);
        break;
    case 'a':
    case 'A':
        yrot -=1;
        glTranslatef(yrot,0.0,0.0);
        break;
    case 'p':
    case 'P':
            if(pin==0)
                pin=1;
            else
                pin=0;
        break;
    case '2':
        xrot +=1;
        glRotatef(xrot,1.0,0.0,0.0);
        break;
    case '8':
        xrot -=1;
        glRotatef(xrot,1.0,0.0,0.0);
        break;
    case '6':
        yrot +=1;
        glRotatef(yrot,0.0,1.0,0.0);
        break;
    case '4':
        yrot -=1;
        glRotatef(yrot,0.0,1.0,0.0);
        break;
    case '5':
        if(is_depth){
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    }
    tampil();
}
void ukuran(int lebar,int tinggi){
    if (tinggi==0)tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport (0, 0, lebar, tinggi);
    gluPerspective(150.0, lebar/tinggi,5.0,700.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
