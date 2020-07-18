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

    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,25,-105);
        glVertex3f(45,-40,-105);
        glVertex3f(45,-40,-70);
        glVertex3f(45,25,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,25,-105);
        glVertex3f(45,-40,-105);
        glVertex3f(70,-40,-110);
        glVertex3f(70,25,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,-40,-110);
        glVertex3f(70,25,-110);
        glVertex3f(95,25,-130);
        glVertex3f(95,-40,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,25,-130);
        glVertex3f(95,-40,-130);
        glVertex3f(115,-40,-150);
        glVertex3f(115,25,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,-40,-150);
        glVertex3f(115,25,-150);
        glVertex3f(120,25,-180);
        glVertex3f(120,-40,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,25,-180);
        glVertex3f(120,25,-200);
        glVertex3f(120,-40,-200);
        glVertex3f(120,-40,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,-40,-220);
        glVertex3f(120,-40,-200);
        glVertex3f(120,25,-200);
        glVertex3f(120,25,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,-40,-240);
        glVertex3f(120,-40,-220);
        glVertex3f(120,25,-220);
        glVertex3f(115,25,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,-40,-240);
        glVertex3f(110,-40,-260);
        glVertex3f(110,25,-260);
        glVertex3f(115,25,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(100,-40,-280);
        glVertex3f(100,25,-280);
        glVertex3f(110,25,-260);
        glVertex3f(110,-40,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(100,25,-280);
        glVertex3f(100,-40,-280);
        glVertex3f(90,-40,-300);
        glVertex3f(90,25,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(90,25,-300);
        glVertex3f(90,-40,-300);
        glVertex3f(60,-40,-320);
        glVertex3f(60,25,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,-40,-320);
        glVertex3f(60,25,-320);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
        glVertex3f(10,-40,-280);
        glVertex3f(10,25,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,-40,-280);
        glVertex3f(10,25,-280);
        glVertex3f(-20,25,-280);
        glVertex3f(-20,-40,-280);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,25,-280);
        glVertex3f(-20,-40,-280);
        glVertex3f(-60,-40,-280);
        glVertex3f(-60,25,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,-40,-280);
        glVertex3f(-60,25,-280);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,-40,-320);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,-40,-320);
        glVertex3f(-130,-40,-310);
        glVertex3f(-130,25,-310);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-130,-40,-310);
        glVertex3f(-130,25,-310);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,-40,-270);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,-40,-270);
        glVertex3f(-160,-40,-230);
        glVertex3f(-160,25,-230);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-160,-40,-230);
        glVertex3f(-160,25,-230);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,-40,-190);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,-40,-190);
        glVertex3f(-140,-40,-145);
        glVertex3f(-140,25,-145);
    glEnd();

    //B8
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,-40,-145);
        glVertex3f(-140,25,-145);
        glVertex3f(-115,25,-105);
        glVertex3f(-115,-40,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,25,-105);
        glVertex3f(-115,-40,-105);
        glVertex3f(-115,-40,-70);
        glVertex3f(-115,25,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,-40,-70);
        glVertex3f(-115,25,-70);
        glVertex3f(-130,25,-40);
        glVertex3f(-130,-40,-40);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-130,25,-40);
        glVertex3f(-130,-40,-40);
        glVertex3f(-145,-40,-10);
        glVertex3f(-145,25,-10);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-145,-40,-10);
        glVertex3f(-145,25,-10);
        glVertex3f(-145,25,10);
        glVertex3f(-145,-40,10);
    glEnd();

    //C5
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-145,25,10);
        glVertex3f(-145,-40,10);
        glVertex3f(-125,-40,40);
        glVertex3f(-125,25,40);
    glEnd();

    //C6
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-125,-40,40);
        glVertex3f(-125,25,40);
        glVertex3f(-105,25,60);
        glVertex3f(-105,-40,60);
    glEnd();

    //C7
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-105,25,60);
        glVertex3f(-105,-40,60);
        glVertex3f(-60,-40,70);       
        glVertex3f(-60,25,70);
    glEnd();

    //C8
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-20,25,70);
        glVertex3f(-20,-40,70);
        glVertex3f(-60,-40,70);
        glVertex3f(-60,25,70);
    glEnd();



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
    gluPerspective(100.0, lebar/tinggi,5.0,900.0);
    glTranslatef(0.0,-40.0,-300.0);
    glMatrixMode(GL_MODELVIEW);
}

