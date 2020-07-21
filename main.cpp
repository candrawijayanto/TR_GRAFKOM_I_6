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
    // glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    // glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}


// LANTAI
void lantai1(){

    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,25,-95);
        glVertex3f(45,-40,-95);
        glVertex3f(45,-40,-70);
        glVertex3f(45,25,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,25,-95);
        glVertex3f(45,-40,-95);
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
        glVertex3f(-20,25,-265);
        glVertex3f(-20,-40,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,-40,-265);
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
        glVertex3f(-115,25,0);
        glVertex3f(-115,-40,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-115,25,0);
        glVertex3f(-115,-40,0);
        glVertex3f(-95,-40,40);
        glVertex3f(-95,25,40);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-95,-40,40);
        glVertex3f(-95,25,40);
        glVertex3f(-50,25,60);
        glVertex3f(-50,-40,60);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-50,25,60);
        glVertex3f(-50,-40,60);
        glVertex3f(-20,-40,60);
        glVertex3f(-20,25,60);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(25,-40,40);
        glVertex3f(25,25,40);
        glVertex3f(-20,25,60);
        glVertex3f(-20,-40,60);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,25,0);
        glVertex3f(45,-40,0);
        glVertex3f(25,-40,40);
        glVertex3f(25,25,40);
    glEnd();

        //D4
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,-40,-70);
        glVertex3f(45,25,-70);
        glVertex3f(45,25,0);
        glVertex3f(45,-40,0);
    glEnd();



}

void lantai2(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,60,-95);
        glVertex3f(45,30,-95);
        glVertex3f(45,30,-70);
        glVertex3f(45,60,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,60,-95);
        glVertex3f(45,30,-95);
        glVertex3f(70,30,-110);
        glVertex3f(70,60,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,30,-110);
        glVertex3f(70,60,-110);
        glVertex3f(95,60,-130);
        glVertex3f(95,30,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,60,-130);
        glVertex3f(95,30,-130);
        glVertex3f(115,30,-150);
        glVertex3f(115,60,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,30,-150);
        glVertex3f(115,60,-150);
        glVertex3f(120,60,-180);
        glVertex3f(120,30,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,60,-180);
        glVertex3f(120,60,-200);
        glVertex3f(120,30,-200);
        glVertex3f(120,30,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,30,-220);
        glVertex3f(120,30,-200);
        glVertex3f(120,60,-200);
        glVertex3f(120,60,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,30,-240);
        glVertex3f(120,30,-220);
        glVertex3f(120,60,-220);
        glVertex3f(115,60,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,30,-240);
        glVertex3f(110,30,-260);
        glVertex3f(110,60,-260);
        glVertex3f(115,60,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(100,30,-280);
        glVertex3f(100,60,-280);
        glVertex3f(110,60,-260);
        glVertex3f(110,30,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(100,60,-280);
        glVertex3f(100,30,-280);
        glVertex3f(90,30,-300);
        glVertex3f(90,60,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(90,60,-300);
        glVertex3f(90,30,-300);
        glVertex3f(60,30,-320);
        glVertex3f(60,60,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,30,-320);
        glVertex3f(60,60,-320);
        glVertex3f(30,60,-300);
        glVertex3f(30,30,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(30,60,-300);
        glVertex3f(30,30,-300);
        glVertex3f(10,30,-280);
        glVertex3f(10,60,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,30,-280);
        glVertex3f(10,60,-280);
        glVertex3f(-20,60,-265);
        glVertex3f(-20,30,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,60,-265);
        glVertex3f(-20,30,-265);
        glVertex3f(-60,30,-280);
        glVertex3f(-60,60,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,30,-280);
        glVertex3f(-60,60,-280);
        glVertex3f(-100,60,-290);
        glVertex3f(-100,30,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,60,-290);
        glVertex3f(-100,30,-290);
        glVertex3f(-130,30,-280);
        glVertex3f(-130,60,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-130,60,-280);
        glVertex3f(-130,30,-280);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,60,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,60,-230);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,30,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,30,-190);
        glVertex3f(-140,30,-145);
        glVertex3f(-140,60,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,30,-145);
        glVertex3f(-140,60,-145);
        glVertex3f(-115,60,-105);
        glVertex3f(-115,30,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,60,-105);
        glVertex3f(-115,30,-105);
        glVertex3f(-115,30,-70);
        glVertex3f(-115,60,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,30,-70);
        glVertex3f(-115,60,-70);
        glVertex3f(-95,60,0);
        glVertex3f(-95,30,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-95,60,0);
        glVertex3f(-95,30,0);
        glVertex3f(-55,30,40);
        glVertex3f(-55,60,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,60,40);
        glVertex3f(-55,30,40);
        glVertex3f(-10,30,40);
        glVertex3f(-10,60,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(25,60,0);
        glVertex3f(25,30,0);
        glVertex3f(-10,30,40);
        glVertex3f(-10,60,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,30,-70);
        glVertex3f(45,60,-70);
        glVertex3f(25,60,0);
        glVertex3f(25,30,0);
    glEnd();
}

void lantai3(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,95,-95);
        glVertex3f(45,65,-95);
        glVertex3f(45,65,-70);
        glVertex3f(45,95,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,95,-95);
        glVertex3f(45,65,-95);
        glVertex3f(70,65,-110);
        glVertex3f(70,95,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,65,-110);
        glVertex3f(70,95,-110);
        glVertex3f(95,95,-130);
        glVertex3f(95,65,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,95,-130);
        glVertex3f(95,65,-130);
        glVertex3f(115,65,-150);
        glVertex3f(115,95,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,65,-150);
        glVertex3f(115,95,-150);
        glVertex3f(120,95,-180);
        glVertex3f(120,65,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,95,-180);
        glVertex3f(120,95,-200);
        glVertex3f(120,65,-200);
        glVertex3f(120,65,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,65,-220);
        glVertex3f(120,65,-200);
        glVertex3f(120,95,-200);
        glVertex3f(120,95,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,65,-240);
        glVertex3f(120,65,-220);
        glVertex3f(120,95,-220);
        glVertex3f(115,95,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,65,-240);
        glVertex3f(110,65,-260);
        glVertex3f(110,95,-260);
        glVertex3f(115,95,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(100,65,-280);
        glVertex3f(100,95,-280);
        glVertex3f(110,95,-260);
        glVertex3f(110,65,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(100,95,-280);
        glVertex3f(100,65,-280);
        glVertex3f(90,65,-300);
        glVertex3f(90,95,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(90,95,-300);
        glVertex3f(90,65,-300);
        glVertex3f(60,65,-320);
        glVertex3f(60,95,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,65,-320);
        glVertex3f(60,95,-320);
        glVertex3f(30,95,-300);
        glVertex3f(30,65,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(30,95,-300);
        glVertex3f(30,65,-300);
        glVertex3f(10,65,-280);
        glVertex3f(10,95,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,65,-280);
        glVertex3f(10,95,-280);
        glVertex3f(-20,95,-265);
        glVertex3f(-20,65,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,95,-265);
        glVertex3f(-20,65,-265);
        glVertex3f(-60,65,-280);
        glVertex3f(-60,95,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,65,-280);
        glVertex3f(-60,95,-280);
        glVertex3f(-100,95,-290);
        glVertex3f(-100,65,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,95,-290);
        glVertex3f(-100,65,-290);
        glVertex3f(-130,65,-280);
        glVertex3f(-130,95,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-130,95,-280);
        glVertex3f(-130,65,-280);
        glVertex3f(-160,65,-230);
        glVertex3f(-160,95,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-160,65,-230);
        glVertex3f(-160,95,-230);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,65,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,65,-190);
        glVertex3f(-140,65,-145);
        glVertex3f(-140,95,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,65,-145);
        glVertex3f(-140,95,-145);
        glVertex3f(-115,95,-105);
        glVertex3f(-115,65,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,95,-105);
        glVertex3f(-115,65,-105);
        glVertex3f(-115,65,-70);
        glVertex3f(-115,95,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,65,-70);
        glVertex3f(-115,95,-70);
        glVertex3f(-95,95,0);
        glVertex3f(-95,65,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-95,95,0);
        glVertex3f(-95,65,0);
        glVertex3f(-55,65,40);
        glVertex3f(-55,95,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,95,40);
        glVertex3f(-55,65,40);
        glVertex3f(-10,65,40);
        glVertex3f(-10,95,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(25,95,0);
        glVertex3f(25,65,0);
        glVertex3f(-10,65,40);
        glVertex3f(-10,95,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,65,-70);
        glVertex3f(45,95,-70);
        glVertex3f(25,95,0);
        glVertex3f(25,65,0);
    glEnd();
}

void lantai4(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,100,-95);
        glVertex3f(45,130,-95);
        glVertex3f(45,130,-70);
        glVertex3f(45,100,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,100,-95);
        glVertex3f(45,130,-95);
        glVertex3f(70,130,-110);
        glVertex3f(70,100,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,130,-110);
        glVertex3f(70,100,-110);
        glVertex3f(95,100,-130);
        glVertex3f(95,130,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,100,-130);
        glVertex3f(95,130,-130);
        glVertex3f(115,130,-150);
        glVertex3f(115,100,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,130,-150);
        glVertex3f(115,100,-150);
        glVertex3f(120,100,-180);
        glVertex3f(120,130,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,100,-180);
        glVertex3f(120,100,-200);
        glVertex3f(120,130,-200);
        glVertex3f(120,130,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,130,-220);
        glVertex3f(120,130,-200);
        glVertex3f(120,100,-200);
        glVertex3f(120,100,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,130,-240);
        glVertex3f(120,130,-220);
        glVertex3f(120,100,-220);
        glVertex3f(115,100,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,130,-240);
        glVertex3f(110,130,-260);
        glVertex3f(110,100,-260);
        glVertex3f(115,100,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,130,-300);
        glVertex3f(60,100,-300);
        glVertex3f(110,100,-260);
        glVertex3f(110,130,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,100,-300);
        glVertex3f(60,130,-300);
        glVertex3f(10,130,-280);
        glVertex3f(10,100,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,130,-280);
        glVertex3f(10,100,-280);
        glVertex3f(-20,100,-265);
        glVertex3f(-20,130,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,100,-265);
        glVertex3f(-20,130,-265);
        glVertex3f(-60,130,-280);
        glVertex3f(-60,100,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,130,-280);
        glVertex3f(-60,100,-280);
        glVertex3f(-100,100,-290);
        glVertex3f(-100,130,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,100,-290);
        glVertex3f(-100,130,-290);
        glVertex3f(-130,130,-280);
        glVertex3f(-130,100,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-130,100,-280);
        glVertex3f(-130,130,-280);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,100,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,100,-230);
        glVertex3f(-160,100,-190);
        glVertex3f(-160,130,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,100,-190);
        glVertex3f(-160,130,-190);
        glVertex3f(-140,130,-145);
        glVertex3f(-140,100,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,130,-145);
        glVertex3f(-140,100,-145);
        glVertex3f(-115,100,-105);
        glVertex3f(-115,130,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,100,-105);
        glVertex3f(-115,130,-105);
        glVertex3f(-115,130,-70);
        glVertex3f(-115,100,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,130,-70);
        glVertex3f(-115,100,-70);
        glVertex3f(-95,100,0);
        glVertex3f(-95,130,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-95,100,0);
        glVertex3f(-95,130,0);
        glVertex3f(-55,130,40);
        glVertex3f(-55,100,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,100,40);
        glVertex3f(-55,130,40);
        glVertex3f(-10,130,40);
        glVertex3f(-10,100,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(25,100,0);
        glVertex3f(25,130,0);
        glVertex3f(-10,130,40);
        glVertex3f(-10,100,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,130,-70);
        glVertex3f(45,100,-70);
        glVertex3f(25,100,0);
        glVertex3f(25,130,0);
    glEnd();
}

void lantai5(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,160,-95);
        glVertex3f(45,135,-95);
        glVertex3f(45,135,-70);
        glVertex3f(45,160,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,160,-95);
        glVertex3f(45,135,-95);
        glVertex3f(70,135,-110);
        glVertex3f(70,160,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,135,-110);
        glVertex3f(70,160,-110);
        glVertex3f(95,160,-130);
        glVertex3f(95,135,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,160,-130);
        glVertex3f(95,135,-130);
        glVertex3f(115,135,-150);
        glVertex3f(115,160,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,135,-150);
        glVertex3f(115,160,-150);
        glVertex3f(120,160,-180);
        glVertex3f(120,135,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,160,-180);
        glVertex3f(120,160,-200);
        glVertex3f(120,135,-200);
        glVertex3f(120,135,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,135,-220);
        glVertex3f(120,135,-200);
        glVertex3f(120,160,-200);
        glVertex3f(120,160,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,135,-240);
        glVertex3f(120,135,-220);
        glVertex3f(120,160,-220);
        glVertex3f(115,160,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,135,-240);
        glVertex3f(110,135,-260);
        glVertex3f(110,160,-260);
        glVertex3f(115,160,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,135,-300);
        glVertex3f(60,160,-300);
        glVertex3f(110,160,-260);
        glVertex3f(110,135,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,160,-300);
        glVertex3f(60,135,-300);
        glVertex3f(10,135,-280);
        glVertex3f(10,160,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,135,-280);
        glVertex3f(10,160,-280);
        glVertex3f(-20,160,-265);
        glVertex3f(-20,135,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,160,-265);
        glVertex3f(-20,135,-265);
        glVertex3f(-60,135,-280);
        glVertex3f(-60,160,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,135,-280);
        glVertex3f(-60,160,-280);
        glVertex3f(-100,160,-290);
        glVertex3f(-100,135,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,160,-290);
        glVertex3f(-100,135,-290);
        glVertex3f(-130,135,-280);
        glVertex3f(-130,160,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-130,160,-280);
        glVertex3f(-130,135,-280);
        glVertex3f(-160,135,-230);
        glVertex3f(-160,160,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-160,135,-230);
        glVertex3f(-160,160,-230);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,135,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,135,-190);
        glVertex3f(-140,135,-145);
        glVertex3f(-140,160,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,135,-145);
        glVertex3f(-140,160,-145);
        glVertex3f(-115,160,-105);
        glVertex3f(-115,135,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,160,-105);
        glVertex3f(-115,135,-105);
        glVertex3f(-115,135,-70);
        glVertex3f(-115,160,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,135,-70);
        glVertex3f(-115,160,-70);
        glVertex3f(-80,160,0);
        glVertex3f(-80,135,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-80,160,0);
        glVertex3f(-80,135,0);
        glVertex3f(-55,135,10);
        glVertex3f(-55,160,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,160,10);
        glVertex3f(-55,135,10);
        glVertex3f(-10,135,10);
        glVertex3f(-10,160,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(10,160,0);
        glVertex3f(10,135,0);
        glVertex3f(-10,135,10);
        glVertex3f(-10,160,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,135,-70);
        glVertex3f(45,160,-70);
        glVertex3f(10,160,0);
        glVertex3f(10,135,0);
    glEnd();
}

void lantai6(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,210,-95);
        glVertex3f(45,165,-95);
        glVertex3f(45,165,-70);
        glVertex3f(45,210,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,210,-95);
        glVertex3f(45,165,-95);
        glVertex3f(70,165,-110);
        glVertex3f(70,210,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,165,-110);
        glVertex3f(70,210,-110);
        glVertex3f(95,210,-130);
        glVertex3f(95,165,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,210,-130);
        glVertex3f(95,165,-130);
        glVertex3f(115,165,-150);
        glVertex3f(115,210,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,165,-150);
        glVertex3f(115,210,-150);
        glVertex3f(120,210,-180);
        glVertex3f(120,165,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(120,210,-180);
        glVertex3f(120,210,-200);
        glVertex3f(120,165,-200);
        glVertex3f(120,165,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(120,165,-220);
        glVertex3f(120,165,-200);
        glVertex3f(120,210,-200);
        glVertex3f(120,210,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(115,165,-240);
        glVertex3f(120,165,-220);
        glVertex3f(120,210,-220);
        glVertex3f(115,210,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(115,165,-240);
        glVertex3f(110,165,-260);
        glVertex3f(110,210,-260);
        glVertex3f(115,210,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,165,-300);
        glVertex3f(60,210,-300);
        glVertex3f(110,210,-260);
        glVertex3f(110,165,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(60,210,-300);
        glVertex3f(60,165,-300);
        glVertex3f(10,165,-280);
        glVertex3f(10,210,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,165,-280);
        glVertex3f(10,210,-280);
        glVertex3f(-20,210,-265);
        glVertex3f(-20,165,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,210,-265);
        glVertex3f(-20,165,-265);
        glVertex3f(-60,165,-280);
        glVertex3f(-60,210,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,165,-280);
        glVertex3f(-60,210,-280);
        glVertex3f(-95,210,-270);
        glVertex3f(-95,165,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,210,-270);
        glVertex3f(-95,165,-270);
        glVertex3f(-123,165,-260);
        glVertex3f(-123,210,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-123,210,-260);
        glVertex3f(-123,165,-260);
        glVertex3f(-150,165,-230);
        glVertex3f(-150,210,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-150,165,-230);
        glVertex3f(-150,210,-230);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,165,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,165,-190);
        glVertex3f(-140,165,-145);
        glVertex3f(-140,210,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,165,-145);
        glVertex3f(-140,210,-145);
        glVertex3f(-115,210,-105);
        glVertex3f(-115,165,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,210,-105);
        glVertex3f(-115,165,-105);
        glVertex3f(-115,165,-70);
        glVertex3f(-115,210,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,165,-70);
        glVertex3f(-115,210,-70);
        glVertex3f(-80,210,0);
        glVertex3f(-80,165,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-80,210,0);
        glVertex3f(-80,165,0);
        glVertex3f(-55,165,10);
        glVertex3f(-55,210,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,210,10);
        glVertex3f(-55,165,10);
        glVertex3f(-10,165,10);
        glVertex3f(-10,210,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(10,210,0);
        glVertex3f(10,165,0);
        glVertex3f(-10,165,10);
        glVertex3f(-10,210,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,165,-70);
        glVertex3f(45,210,-70);
        glVertex3f(10,210,0);
        glVertex3f(10,165,0);
    glEnd();
}

void lantai7(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,255,-95);
        glVertex3f(45,215,-95);
        glVertex3f(45,215,-70);
        glVertex3f(45,255,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,255,-95);
        glVertex3f(45,215,-95);
        glVertex3f(70,215,-110);
        glVertex3f(70,255,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,215,-110);
        glVertex3f(70,255,-110);
        glVertex3f(95,255,-130);
        glVertex3f(95,215,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,255,-130);
        glVertex3f(95,215,-130);
        glVertex3f(95,215,-210);
        glVertex3f(95,255,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,215,-210);
        glVertex3f(95,255,-210);
        glVertex3f(60,255,-270);
        glVertex3f(60,215,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,255,-270);
        glVertex3f(60,215,-270);
        glVertex3f(10,215,-280);
        glVertex3f(10,255,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,215,-280);
        glVertex3f(10,255,-280);
        glVertex3f(-20,255,-265);
        glVertex3f(-20,215,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,255,-265);
        glVertex3f(-20,215,-265);
        glVertex3f(-60,215,-280);
        glVertex3f(-60,255,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,215,-280);
        glVertex3f(-60,255,-280);
        glVertex3f(-95,255,-270);
        glVertex3f(-95,215,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,255,-270);
        glVertex3f(-95,215,-270);
        glVertex3f(-123,215,-260);
        glVertex3f(-123,255,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-123,255,-260);
        glVertex3f(-123,215,-260);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,255,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,255,-230);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,215,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,215,-190);
        glVertex3f(-140,215,-145);
        glVertex3f(-140,255,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,215,-145);
        glVertex3f(-140,255,-145);
        glVertex3f(-115,255,-105);
        glVertex3f(-115,215,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,255,-105);
        glVertex3f(-115,215,-105);
        glVertex3f(-115,215,-70);
        glVertex3f(-115,255,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,215,-70);
        glVertex3f(-115,255,-70);
        glVertex3f(-80,255,0);
        glVertex3f(-80,215,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-80,255,0);
        glVertex3f(-80,215,0);
        glVertex3f(-55,215,10);
        glVertex3f(-55,255,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,255,10);
        glVertex3f(-55,215,10);
        glVertex3f(-10,215,10);
        glVertex3f(-10,255,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(10,255,0);
        glVertex3f(10,215,0);
        glVertex3f(-10,215,10);
        glVertex3f(-10,255,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,215,-70);
        glVertex3f(45,255,-70);
        glVertex3f(10,255,0);
        glVertex3f(10,215,0);
    glEnd();
}

void lantai8(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,290,-95);
        glVertex3f(45,260,-95);
        glVertex3f(45,260,-70);
        glVertex3f(45,290,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,290,-95);
        glVertex3f(45,260,-95);
        glVertex3f(70,260,-110);
        glVertex3f(70,290,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,260,-110);
        glVertex3f(70,290,-110);
        glVertex3f(95,290,-130);
        glVertex3f(95,260,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,290,-130);
        glVertex3f(95,260,-130);
        glVertex3f(95,260,-210);
        glVertex3f(95,290,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,260,-210);
        glVertex3f(95,290,-210);
        glVertex3f(60,290,-270);
        glVertex3f(60,260,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,290,-270);
        glVertex3f(60,260,-270);
        glVertex3f(10,260,-280);
        glVertex3f(10,290,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,260,-280);
        glVertex3f(10,290,-280);
        glVertex3f(-20,290,-265);
        glVertex3f(-20,260,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,290,-265);
        glVertex3f(-20,260,-265);
        glVertex3f(-60,260,-280);
        glVertex3f(-60,290,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,260,-280);
        glVertex3f(-60,290,-280);
        glVertex3f(-95,290,-270);
        glVertex3f(-95,260,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,290,-270);
        glVertex3f(-95,260,-270);
        glVertex3f(-123,260,-260);
        glVertex3f(-123,290,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-123,290,-260);
        glVertex3f(-123,260,-260);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,290,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,290,-230);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,260,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,260,-190);
        glVertex3f(-140,260,-145);
        glVertex3f(-140,290,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,260,-145);
        glVertex3f(-140,290,-145);
        glVertex3f(-115,290,-105);
        glVertex3f(-115,260,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,290,-105);
        glVertex3f(-115,260,-105);
        glVertex3f(-115,260,-70);
        glVertex3f(-115,290,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,260,-70);
        glVertex3f(-115,290,-70);
        glVertex3f(-80,290,-30);
        glVertex3f(-80,260,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-80,290,-30);
        glVertex3f(-80,260,-30);
        glVertex3f(-55,260,-20);
        glVertex3f(-55,290,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,260,-20);
        glVertex3f(-55,290,-20);
        glVertex3f(-10,290,-20);
        glVertex3f(-10,260,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(10,290,-30);
        glVertex3f(10,260,-30);
        glVertex3f(-10,260,-20);
        glVertex3f(-10,290,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,260,-70);
        glVertex3f(45,290,-70);
        glVertex3f(10,290,-30);
        glVertex3f(10,260,-30);
    glEnd();
}

void lantai9(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,335,-95);
        glVertex3f(45,295,-95);
        glVertex3f(45,295,-70);
        glVertex3f(45,335,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(45,335,-95);
        glVertex3f(45,295,-95);
        glVertex3f(70,295,-110);
        glVertex3f(70,335,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(70,295,-110);
        glVertex3f(70,335,-110);
        glVertex3f(95,335,-130);
        glVertex3f(95,295,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(95,335,-130);
        glVertex3f(95,295,-130);
        glVertex3f(95,295,-210);
        glVertex3f(95,335,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,295,-210);
        glVertex3f(95,335,-210);
        glVertex3f(60,335,-270);
        glVertex3f(60,295,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(60,335,-270);
        glVertex3f(60,295,-270);
        glVertex3f(10,295,-280);
        glVertex3f(10,335,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(10,295,-280);
        glVertex3f(10,335,-280);
        glVertex3f(-20,335,-265);
        glVertex3f(-20,295,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,335,-265);
        glVertex3f(-20,295,-265);
        glVertex3f(-60,295,-280);
        glVertex3f(-60,335,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-60,295,-280);
        glVertex3f(-60,335,-280);
        glVertex3f(-95,335,-270);
        glVertex3f(-95,295,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,335,-270);
        glVertex3f(-95,295,-270);
        glVertex3f(-123,295,-260);
        glVertex3f(-123,335,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-123,335,-260);
        glVertex3f(-123,295,-260);
        glVertex3f(-150,295,-230);
        glVertex3f(-150,335,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-150,295,-230);
        glVertex3f(-150,335,-230);
        glVertex3f(-160,335,-190);
        glVertex3f(-160,295,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-160,335,-190);
        glVertex3f(-160,295,-190);
        glVertex3f(-140,295,-145);
        glVertex3f(-140,335,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-140,295,-145);
        glVertex3f(-140,335,-145);
        glVertex3f(-115,335,-105);
        glVertex3f(-115,295,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,335,-105);
        glVertex3f(-115,295,-105);
        glVertex3f(-115,295,-70);
        glVertex3f(-115,335,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-115,295,-70);
        glVertex3f(-115,335,-70);
        glVertex3f(-80,335,-30);
        glVertex3f(-80,295,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-80,335,-30);
        glVertex3f(-80,295,-30);
        glVertex3f(-55,295,-20);
        glVertex3f(-55,335,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,295,-20);
        glVertex3f(-55,335,-20);
        glVertex3f(-10,335,-20);
        glVertex3f(-10,295,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(10,335,-30);
        glVertex3f(10,295,-30);
        glVertex3f(-10,295,-20);
        glVertex3f(-10,335,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(45,295,-70);
        glVertex3f(45,335,-70);
        glVertex3f(10,335,-30);
        glVertex3f(10,295,-30);
    glEnd();
}

// LANTAI

// LINE
void line1(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,25,-95);
        glVertex3f(45,30,-95);
        glVertex3f(45,30,-70);
        glVertex3f(45,25,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,25,-95);
        glVertex3f(45,30,-95);
        glVertex3f(70,30,-110);
        glVertex3f(70,25,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,30,-110);
        glVertex3f(70,25,-110);
        glVertex3f(95,25,-130);
        glVertex3f(95,30,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,25,-130);
        glVertex3f(95,30,-130);
        glVertex3f(115,30,-150);
        glVertex3f(115,25,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,30,-150);
        glVertex3f(115,25,-150);
        glVertex3f(120,25,-180);
        glVertex3f(120,30,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,25,-180);
        glVertex3f(120,25,-200);
        glVertex3f(120,30,-200);
        glVertex3f(120,30,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,30,-220);
        glVertex3f(120,30,-200);
        glVertex3f(120,25,-200);
        glVertex3f(120,25,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,30,-240);
        glVertex3f(120,30,-220);
        glVertex3f(120,25,-220);
        glVertex3f(115,25,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,30,-240);
        glVertex3f(110,30,-260);
        glVertex3f(110,25,-260);
        glVertex3f(115,25,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(100,30,-280);
        glVertex3f(100,25,-280);
        glVertex3f(110,25,-260);
        glVertex3f(110,30,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(100,25,-280);
        glVertex3f(100,30,-280);
        glVertex3f(90,30,-300);
        glVertex3f(90,25,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(90,25,-300);
        glVertex3f(90,30,-300);
        glVertex3f(60,30,-320);
        glVertex3f(60,25,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,30,-320);
        glVertex3f(60,25,-320);
        glVertex3f(30,25,-300);
        glVertex3f(30,30,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(30,25,-300);
        glVertex3f(30,30,-300);
        glVertex3f(10,30,-280);
        glVertex3f(10,25,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,30,-280);
        glVertex3f(10,25,-280);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,30,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,30,-265);
        glVertex3f(-60,30,-280);
        glVertex3f(-60,25,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,30,-280);
        glVertex3f(-60,25,-280);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,30,-320);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,30,-320);
        glVertex3f(-130,30,-310);
        glVertex3f(-130,25,-310);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-130,30,-310);
        glVertex3f(-130,25,-310);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,30,-270);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,30,-270);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,25,-230);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,25,-230);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,30,-190);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,30,-190);
        glVertex3f(-140,30,-145);
        glVertex3f(-140,25,-145);
    glEnd();

    //B8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,30,-145);
        glVertex3f(-140,25,-145);
        glVertex3f(-115,25,-105);
        glVertex3f(-115,30,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,25,-105);
        glVertex3f(-115,30,-105);
        glVertex3f(-115,30,-70);
        glVertex3f(-115,25,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,30,-70);
        glVertex3f(-115,25,-70);
        glVertex3f(-115,25,0);
        glVertex3f(-115,30,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,25,0);
        glVertex3f(-115,30,0);
        glVertex3f(-95,30,40);
        glVertex3f(-95,25,40);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,30,40);
        glVertex3f(-95,25,40);
        glVertex3f(-50,25,60);
        glVertex3f(-50,30,60);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-50,25,60);
        glVertex3f(-50,30,60);
        glVertex3f(-20,30,60);
        glVertex3f(-20,25,60);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,30,-70);
        glVertex3f(45,25,-70);
        glVertex3f(45,25,0);
        glVertex3f(45,30,0);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,25,0);
        glVertex3f(45,30,0);
        glVertex3f(25,30,40);
        glVertex3f(25,25,40);
    glEnd();

    //D4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,30 ,40);
        glVertex3f(25,25,40);
        glVertex3f(-20,25,60);
        glVertex3f(-20,30,60);
    glEnd();
}

void line2(){
//A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,60,-95);
        glVertex3f(45,65,-95);
        glVertex3f(45,65,-70);
        glVertex3f(45,60,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,60,-95);
        glVertex3f(45,65,-95);
        glVertex3f(70,65,-110);
        glVertex3f(70,60,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(70,65,-110);
        glVertex3f(70,60,-110);
        glVertex3f(95,60,-130);
        glVertex3f(95,65,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,60,-130);
        glVertex3f(95,65,-130);
        glVertex3f(115,65,-150);
        glVertex3f(115,60,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(115,65,-150);
        glVertex3f(115,60,-150);
        glVertex3f(120,60,-180);
        glVertex3f(120,65,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,60,-180);
        glVertex3f(120,60,-200);
        glVertex3f(120,65,-200);
        glVertex3f(120,65,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(120,65,-220);
        glVertex3f(120,65,-200);
        glVertex3f(120,60,-200);
        glVertex3f(120,60,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,65,-240);
        glVertex3f(120,65,-220);
        glVertex3f(120,60,-220);
        glVertex3f(115,60,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(115,65,-240);
        glVertex3f(110,65,-260);
        glVertex3f(110,60,-260);
        glVertex3f(115,60,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(100,65,-280);
        glVertex3f(100,60,-280);
        glVertex3f(110,60,-260);
        glVertex3f(110,65,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(100,60,-280);
        glVertex3f(100,65,-280);
        glVertex3f(90,65,-300);
        glVertex3f(90,60,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(90,60,-300);
        glVertex3f(90,65,-300);
        glVertex3f(60,65,-320);
        glVertex3f(60,60,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(60,65,-320);
        glVertex3f(60,60,-320);
        glVertex3f(30,60,-300);
        glVertex3f(30,65,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(30,60,-300);
        glVertex3f(30,65,-300);
        glVertex3f(10,65,-280);
        glVertex3f(10,60,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(10,65,-280);
        glVertex3f(10,60,-280);
        glVertex3f(-20,60,-265);
        glVertex3f(-20,65,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,60,-265);
        glVertex3f(-20,65,-265);
        glVertex3f(-60,65,-280);
        glVertex3f(-60,60,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-60,65,-280);
        glVertex3f(-60,60,-280);
        glVertex3f(-100,60,-290);
        glVertex3f(-100,65,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,60,-290);
        glVertex3f(-100,65,-290);
        glVertex3f(-130,65,-280);
        glVertex3f(-130,60,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-130,60,-280);
        glVertex3f(-130,65,-280);
        glVertex3f(-160,65,-230);
        glVertex3f(-160,60,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-160,65,-230);
        glVertex3f(-160,60,-230);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,65,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,65,-190);
        glVertex3f(-140,65,-145);
        glVertex3f(-140,60,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-140,65,-145);
        glVertex3f(-140,60,-145);
        glVertex3f(-115,60,-105);
        glVertex3f(-115,65,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,60,-105);
        glVertex3f(-115,65,-105);
        glVertex3f(-115,65,-70);
        glVertex3f(-115,60,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-115,65,-70);
        glVertex3f(-115,60,-70);
        glVertex3f(-95,60,0);
        glVertex3f(-95,65,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,60,0);
        glVertex3f(-95,65,0);
        glVertex3f(-55,65,40);
        glVertex3f(-55,60,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,60,40);
        glVertex3f(-55,65,40);
        glVertex3f(-10,65,40);
        glVertex3f(-10,60,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,60,0);
        glVertex3f(25,65,0);
        glVertex3f(-10,65,40);
        glVertex3f(-10,60,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(45,65,-70);
        glVertex3f(45,60,-70);
        glVertex3f(25,60,0);
        glVertex3f(25,65,0);
    glEnd();
}

void line3(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,95,-95);
        glVertex3f(45,100,-95);
        glVertex3f(45,100,-70);
        glVertex3f(45,95,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,95,-95);
        glVertex3f(45,100,-95);
        glVertex3f(70,100,-110);
        glVertex3f(70,95,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(70,100,-110);
        glVertex3f(70,95,-110);
        glVertex3f(95,95,-130);
        glVertex3f(95,100,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,95,-130);
        glVertex3f(95,100,-130);
        glVertex3f(115,100,-150);
        glVertex3f(115,95,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(115,100,-150);
        glVertex3f(115,95,-150);
        glVertex3f(120,95,-180);
        glVertex3f(120,100,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,95,-180);
        glVertex3f(120,95,-200);
        glVertex3f(120,100,-200);
        glVertex3f(120,100,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(120,100,-220);
        glVertex3f(120,100,-200);
        glVertex3f(120,95,-200);
        glVertex3f(120,95,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,100,-240);
        glVertex3f(120,100,-220);
        glVertex3f(120,95,-220);
        glVertex3f(115,95,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(115,100,-240);
        glVertex3f(110,100,-260);
        glVertex3f(110,95,-260);
        glVertex3f(115,95,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(100,100,-280);
        glVertex3f(100,95,-280);
        glVertex3f(110,95,-260);
        glVertex3f(110,100,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(100,95,-280);
        glVertex3f(100,100,-280);
        glVertex3f(90,100,-300);
        glVertex3f(90,95,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(90,95,-300);
        glVertex3f(90,100,-300);
        glVertex3f(60,100,-320);
        glVertex3f(60,95,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(60,100,-320);
        glVertex3f(60,95,-320);
        glVertex3f(30,95,-300);
        glVertex3f(30,100,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(30,95,-300);
        glVertex3f(30,100,-300);
        glVertex3f(10,100,-280);
        glVertex3f(10,95,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(10,100,-280);
        glVertex3f(10,95,-280);
        glVertex3f(-20,95,-265);
        glVertex3f(-20,100,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,95,-265);
        glVertex3f(-20,100,-265);
        glVertex3f(-60,100,-280);
        glVertex3f(-60,95,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-60,100,-280);
        glVertex3f(-60,95,-280);
        glVertex3f(-100,95,-290);
        glVertex3f(-100,100,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,95,-290);
        glVertex3f(-100,100,-290);
        glVertex3f(-130,100,-280);
        glVertex3f(-130,95,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-130,95,-280);
        glVertex3f(-130,100,-280);
        glVertex3f(-160,100,-230);
        glVertex3f(-160,95,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-160,100,-230);
        glVertex3f(-160,95,-230);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,100,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,100,-190);
        glVertex3f(-140,100,-145);
        glVertex3f(-140,95,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-140,100,-145);
        glVertex3f(-140,95,-145);
        glVertex3f(-115,95,-105);
        glVertex3f(-115,100,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,95,-105);
        glVertex3f(-115,100,-105);
        glVertex3f(-115,100,-70);
        glVertex3f(-115,95,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(-115,100,-70);
        glVertex3f(-115,95,-70);
        glVertex3f(-95,95,0);
        glVertex3f(-95,100,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,95,0);
        glVertex3f(-95,100,0);
        glVertex3f(-55,100,40);
        glVertex3f(-55,95,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,95,40);
        glVertex3f(-55,100,40);
        glVertex3f(-10,100,40);
        glVertex3f(-10,95,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,95,0);
        glVertex3f(25,100,0);
        glVertex3f(-10,100,40);
        glVertex3f(-10,95,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);;
        glVertex3f(45,100,-70);
        glVertex3f(45,95,-70);
        glVertex3f(25,95,0);
        glVertex3f(25,100,0);
    glEnd();
}

void line4(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,135,-95);
        glVertex3f(45,130,-95);
        glVertex3f(45,130,-70);
        glVertex3f(45,135,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,135,-95);
        glVertex3f(45,130,-95);
        glVertex3f(70,130,-110);
        glVertex3f(70,135,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,130,-110);
        glVertex3f(70,135,-110);
        glVertex3f(95,135,-130);
        glVertex3f(95,130,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,135,-130);
        glVertex3f(95,130,-130);
        glVertex3f(115,130,-150);
        glVertex3f(115,135,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,130,-150);
        glVertex3f(115,135,-150);
        glVertex3f(120,135,-180);
        glVertex3f(120,130,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,135,-180);
        glVertex3f(120,135,-200);
        glVertex3f(120,130,-200);
        glVertex3f(120,130,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,130,-220);
        glVertex3f(120,130,-200);
        glVertex3f(120,135,-200);
        glVertex3f(120,135,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,130,-240);
        glVertex3f(120,130,-220);
        glVertex3f(120,135,-220);
        glVertex3f(115,135,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,130,-240);
        glVertex3f(110,130,-260);
        glVertex3f(110,135,-260);
        glVertex3f(115,135,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,130,-300);
        glVertex3f(60,135,-300);
        glVertex3f(110,135,-260);
        glVertex3f(110,130,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,135,-300);
        glVertex3f(60,130,-300);
        glVertex3f(10,130,-280);
        glVertex3f(10,135,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,130,-280);
        glVertex3f(10,135,-280);
        glVertex3f(-20,135,-265);
        glVertex3f(-20,130,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,135,-265);
        glVertex3f(-20,130,-265);
        glVertex3f(-60,130,-280);
        glVertex3f(-60,135,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,130,-280);
        glVertex3f(-60,135,-280);
        glVertex3f(-100,135,-290);
        glVertex3f(-100,130,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,135,-290);
        glVertex3f(-100,130,-290);
        glVertex3f(-130,130,-280);
        glVertex3f(-130,135,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-130,135,-280);
        glVertex3f(-130,130,-280);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,135,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,135,-230);
        glVertex3f(-160,135,-190);
        glVertex3f(-160,130,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,135,-190);
        glVertex3f(-160,130,-190);
        glVertex3f(-140,130,-145);
        glVertex3f(-140,135,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,130,-145);
        glVertex3f(-140,135,-145);
        glVertex3f(-115,135,-105);
        glVertex3f(-115,130,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,135,-105);
        glVertex3f(-115,130,-105);
        glVertex3f(-115,130,-70);
        glVertex3f(-115,135,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,130,-70);
        glVertex3f(-115,135,-70);
        glVertex3f(-95,135,0);
        glVertex3f(-95,130,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,135,0);
        glVertex3f(-95,130,0);
        glVertex3f(-55,130,40);
        glVertex3f(-55,135,40);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,135,40);
        glVertex3f(-55,130,40);
        glVertex3f(-10,130,40);
        glVertex3f(-10,135,40);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,135,0);
        glVertex3f(25,130,0);
        glVertex3f(-10,130,40);
        glVertex3f(-10,135,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,130,-70);
        glVertex3f(45,135,-70);
        glVertex3f(25,135,0);
        glVertex3f(25,130,0);
    glEnd();
}

void line5(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,160,-95);
        glVertex3f(45,165,-95);
        glVertex3f(45,165,-70);
        glVertex3f(45,160,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,160,-95);
        glVertex3f(45,165,-95);
        glVertex3f(70,165,-110);
        glVertex3f(70,160,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,165,-110);
        glVertex3f(70,160,-110);
        glVertex3f(95,160,-130);
        glVertex3f(95,165,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,160,-130);
        glVertex3f(95,165,-130);
        glVertex3f(115,165,-150);
        glVertex3f(115,160,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,165,-150);
        glVertex3f(115,160,-150);
        glVertex3f(120,160,-180);
        glVertex3f(120,165,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,160,-180);
        glVertex3f(120,160,-200);
        glVertex3f(120,165,-200);
        glVertex3f(120,165,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,165,-220);
        glVertex3f(120,165,-200);
        glVertex3f(120,160,-200);
        glVertex3f(120,160,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,165,-240);
        glVertex3f(120,165,-220);
        glVertex3f(120,160,-220);
        glVertex3f(115,160,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,165,-240);
        glVertex3f(110,165,-260);
        glVertex3f(110,160,-260);
        glVertex3f(115,160,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,165,-300);
        glVertex3f(60,160,-300);
        glVertex3f(110,160,-260);
        glVertex3f(110,165,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,160,-300);
        glVertex3f(60,165,-300);
        glVertex3f(10,165,-280);
        glVertex3f(10,160,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,165,-280);
        glVertex3f(10,160,-280);
        glVertex3f(-20,160,-265);
        glVertex3f(-20,165,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,160,-265);
        glVertex3f(-20,165,-265);
        glVertex3f(-60,165,-280);
        glVertex3f(-60,160,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,165,-280);
        glVertex3f(-60,160,-280);
        glVertex3f(-100,160,-290);
        glVertex3f(-100,165,-290);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-100,160,-290);
        glVertex3f(-100,165,-290);
        glVertex3f(-130,165,-280);
        glVertex3f(-130,160,-280);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-130,160,-280);
        glVertex3f(-130,165,-280);
        glVertex3f(-160,165,-230);
        glVertex3f(-160,160,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,165,-230);
        glVertex3f(-160,160,-230);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,165,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,165,-190);
        glVertex3f(-140,165,-145);
        glVertex3f(-140,160,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,165,-145);
        glVertex3f(-140,160,-145);
        glVertex3f(-115,160,-105);
        glVertex3f(-115,165,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,160,-105);
        glVertex3f(-115,165,-105);
        glVertex3f(-115,165,-70);
        glVertex3f(-115,160,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,165,-70);
        glVertex3f(-115,160,-70);
        glVertex3f(-80,160,0);
        glVertex3f(-80,165,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,160,0);
        glVertex3f(-80,165,0);
        glVertex3f(-55,165,10);
        glVertex3f(-55,160,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,160,10);
        glVertex3f(-55,165,10);
        glVertex3f(-10,165,10);
        glVertex3f(-10,160,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,160,0);
        glVertex3f(10,165,0);
        glVertex3f(-10,165,10);
        glVertex3f(-10,160,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,165,-70);
        glVertex3f(45,160,-70);
        glVertex3f(10,160,0);
        glVertex3f(10,165,0);
    glEnd();
}

void line6(){
   //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,210,-95);
        glVertex3f(45,215,-95);
        glVertex3f(45,215,-70);
        glVertex3f(45,210,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,210,-95);
        glVertex3f(45,215,-95);
        glVertex3f(70,215,-110);
        glVertex3f(70,210,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,215,-110);
        glVertex3f(70,210,-110);
        glVertex3f(95,210,-130);
        glVertex3f(95,215,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,210,-130);
        glVertex3f(95,215,-130);
        glVertex3f(115,215,-150);
        glVertex3f(115,210,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,215,-150);
        glVertex3f(115,210,-150);
        glVertex3f(120,210,-180);
        glVertex3f(120,215,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,210,-180);
        glVertex3f(120,210,-200);
        glVertex3f(120,215,-200);
        glVertex3f(120,215,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(120,215,-220);
        glVertex3f(120,215,-200);
        glVertex3f(120,210,-200);
        glVertex3f(120,210,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,215,-240);
        glVertex3f(120,215,-220);
        glVertex3f(120,210,-220);
        glVertex3f(115,210,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(115,215,-240);
        glVertex3f(110,215,-260);
        glVertex3f(110,210,-260);
        glVertex3f(115,210,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,215,-300);
        glVertex3f(60,210,-300);
        glVertex3f(110,210,-260);
        glVertex3f(110,215,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,210,-300);
        glVertex3f(60,215,-300);
        glVertex3f(10,215,-280);
        glVertex3f(10,210,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,210,-280);
        glVertex3f(10,215,-280);
        glVertex3f(-20,215,-265);
        glVertex3f(-20,210,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,215,-265);
        glVertex3f(-20,210,-265);
        glVertex3f(-60,210,-280);
        glVertex3f(-60,215,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,215,-280);
        glVertex3f(-60,210,-280);
        glVertex3f(-95,210,-270);
        glVertex3f(-95,215,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,210,-270);
        glVertex3f(-95,215,-270);
        glVertex3f(-123,215,-260);
        glVertex3f(-123,210,-260);
    glEnd();


    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-123,210,-260);
        glVertex3f(-123,215,-260);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,210,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,210,-230);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,215,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,215,-190);
        glVertex3f(-140,215,-145);
        glVertex3f(-140,210,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,215,-145);
        glVertex3f(-140,210,-145);
        glVertex3f(-115,210,-105);
        glVertex3f(-115,215,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,210,-105);
        glVertex3f(-115,215,-105);
        glVertex3f(-115,215,-70);
        glVertex3f(-115,210,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,215,-70);
        glVertex3f(-115,210,-70);
        glVertex3f(-80,210,0);
        glVertex3f(-80,215,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,210,0);
        glVertex3f(-80,215,0);
        glVertex3f(-55,215,10);
        glVertex3f(-55,210,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,210,10);
        glVertex3f(-55,215,10);
        glVertex3f(-10,215,10);
        glVertex3f(-10,210,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,210,0);
        glVertex3f(10,215,0);
        glVertex3f(-10,215,10);
        glVertex3f(-10,210,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,215,-70);
        glVertex3f(45,210,-70);
        glVertex3f(10,210,0);
        glVertex3f(10,215,0);
    glEnd();
}

void line7(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,255,-95);
        glVertex3f(45,260,-95);
        glVertex3f(45,260,-70);
        glVertex3f(45,255,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,255,-95);
        glVertex3f(45,260,-95);
        glVertex3f(70,260,-110);
        glVertex3f(70,255,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,260,-110);
        glVertex3f(70,255,-110);
        glVertex3f(95,255,-130);
        glVertex3f(95,260,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,255,-130);
        glVertex3f(95,260,-130);
        glVertex3f(95,260,-210);
        glVertex3f(95,255,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,260,-210);
        glVertex3f(95,255,-210);
        glVertex3f(60,255,-270);
        glVertex3f(60,260,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,255,-270);
        glVertex3f(60,260,-270);
        glVertex3f(10,260,-280);
        glVertex3f(10,255,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,260,-280);
        glVertex3f(10,255,-280);
        glVertex3f(-20,255,-265);
        glVertex3f(-20,260,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,255,-265);
        glVertex3f(-20,260,-265);
        glVertex3f(-60,260,-280);
        glVertex3f(-60,255,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,260,-280);
        glVertex3f(-60,255,-280);
        glVertex3f(-95,255,-270);
        glVertex3f(-95,260,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,255,-270);
        glVertex3f(-95,260,-270);
        glVertex3f(-123,260,-260);
        glVertex3f(-123,255,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-123,255,-260);
        glVertex3f(-123,260,-260);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,255,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,255,-230);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,260,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,260,-190);
        glVertex3f(-140,260,-145);
        glVertex3f(-140,255,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,260,-145);
        glVertex3f(-140,255,-145);
        glVertex3f(-115,255,-105);
        glVertex3f(-115,260,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,255,-105);
        glVertex3f(-115,260,-105);
        glVertex3f(-115,260,-70);
        glVertex3f(-115,255,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,260,-70);
        glVertex3f(-115,255,-70);
        glVertex3f(-80,255,0);
        glVertex3f(-80,260,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,255,0);
        glVertex3f(-80,260,0);
        glVertex3f(-55,260,10);
        glVertex3f(-55,255,10);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,255,10);
        glVertex3f(-55,260,10);
        glVertex3f(-10,260,10);
        glVertex3f(-10,255,10);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,255,0);
        glVertex3f(10,260,0);
        glVertex3f(-10,260,10);
        glVertex3f(-10,255,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,260,-70);
        glVertex3f(45,255,-70);
        glVertex3f(10,255,0);
        glVertex3f(10,260,0);
    glEnd();
}

void line8(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,290,-95);
        glVertex3f(45,295,-95);
        glVertex3f(45,295,-70);
        glVertex3f(45,290,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,290,-95);
        glVertex3f(45,295,-95);
        glVertex3f(70,295,-110);
        glVertex3f(70,290,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,295,-110);
        glVertex3f(70,290,-110);
        glVertex3f(95,290,-130);
        glVertex3f(95,295,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,290,-130);
        glVertex3f(95,295,-130);
        glVertex3f(95,295,-210);
        glVertex3f(95,290,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,295,-210);
        glVertex3f(95,290,-210);
        glVertex3f(60,290,-270);
        glVertex3f(60,295,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,290,-270);
        glVertex3f(60,295,-270);
        glVertex3f(10,295,-280);
        glVertex3f(10,290,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,295,-280);
        glVertex3f(10,290,-280);
        glVertex3f(-20,290,-265);
        glVertex3f(-20,295,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,290,-265);
        glVertex3f(-20,295,-265);
        glVertex3f(-60,295,-280);
        glVertex3f(-60,290,-280);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,295,-280);
        glVertex3f(-60,290,-280);
        glVertex3f(-95,290,-270);
        glVertex3f(-95,295,-270);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,290,-270);
        glVertex3f(-95,295,-270);
        glVertex3f(-123,295,-260);
        glVertex3f(-123,290,-260);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-123,290,-260);
        glVertex3f(-123,295,-260);
        glVertex3f(-150,295,-230);
        glVertex3f(-150,290,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-150,295,-230);
        glVertex3f(-150,290,-230);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,295,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,295,-190);
        glVertex3f(-140,295,-145);
        glVertex3f(-140,290,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,295,-145);
        glVertex3f(-140,290,-145);
        glVertex3f(-115,290,-105);
        glVertex3f(-115,295,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,290,-105);
        glVertex3f(-115,295,-105);
        glVertex3f(-115,295,-70);
        glVertex3f(-115,290,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,295,-70);
        glVertex3f(-115,290,-70);
        glVertex3f(-80,290,-30);
        glVertex3f(-80,295,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,290,-30);
        glVertex3f(-80,295,-30);
        glVertex3f(-55,295,-20);
        glVertex3f(-55,290,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,295,-20);
        glVertex3f(-55,290,-20);
        glVertex3f(-10,290,-20);
        glVertex3f(-10,295,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,290,-30);
        glVertex3f(10,295,-30);
        glVertex3f(-10,295,-20);
        glVertex3f(-10,290,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,295,-70);
        glVertex3f(45,290,-70);
        glVertex3f(10,290,-30);
        glVertex3f(10,295,-30);
    glEnd();
}

// LINE

// ATAP
void atapBawah1(){

    //tutup lantai bawah
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,-40,-95); //a1
        glVertex3f(70,-40,-110); //a2
        glVertex3f(95,-40,-130); //a3
        glVertex3f(115,-40,-150); //a4
        glVertex3f(120,-40,-180); //a5
        glVertex3f(120,-40,-200); //a6
        glVertex3f(120,-40,-220); //a7
        glVertex3f(115,-40,-240); //a8
        glVertex3f(110,-40,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,-40,-300); //a11
        glVertex3f(60,-40,-320); //a12
        glVertex3f(30,-40,-300); //a13
        glVertex3f(10,-40,-280); //a14
        glVertex3f(-20,-40,-265); //a15
        //titik b
        glVertex3f(-60,-40,-280); //b1
        glVertex3f(-100,-40,-320); //b2
        glVertex3f(-130,-40,-310); //b3
        glVertex3f(-150,-40,-270); //b4
        glVertex3f(-160,-40,-230); //b5
        glVertex3f(-160,-40,-190); //b6
        glVertex3f(-140,-40,-145); //b7
        glVertex3f(-115,-40,-105); //b8
        //titik c
        glVertex3f(-115,-40,-70); //c1
        glVertex3f(-115,-40,0); //c2
        glVertex3f(-95,-40,40); //c3
        glVertex3f(-50,-40,60); //c4
        //titik d
        glVertex3f(-20,-40,60); //d1
        glVertex3f(25,-40,40);//d2
        glVertex3f(45,-40,0); //d3
        glVertex3f(45,-40,-70); //d4
    glEnd();
}

void atapAtas1(){

    //tutup lantai atas
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,25,-95); //a1
        glVertex3f(70,25,-110); //a2
        glVertex3f(95,25,-130); //a3
        glVertex3f(115,25,-150); //a4
        glVertex3f(120,25,-180); //a5
        glVertex3f(120,25,-200); //a6
        glVertex3f(120,25,-220); //a7
        glVertex3f(115,25,-240); //a8
        glVertex3f(110,25,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,25,-300); //a11
        glVertex3f(60,25,-320); //a12
        glVertex3f(30,25,-300); //a13
        glVertex3f(10,25,-280); //a14
        glVertex3f(-20,25,-265); //a15
        //titik b
        glVertex3f(-60,25,-280); //b1
        glVertex3f(-100,25,-320); //b2
        glVertex3f(-130,25,-310); //b3
        glVertex3f(-150,25,-270); //b4
        glVertex3f(-160,25,-230); //b5
        glVertex3f(-160,25,-190); //b6
        glVertex3f(-140,25,-145); //b7
        glVertex3f(-115,25,-105); //b8
        //titik c
        glVertex3f(-115,25,-70); //c1
        glVertex3f(-115,25,0); //c2
        glVertex3f(-95,25,40); //c3
        glVertex3f(-50,25,60); //c4
        //titik d
        glVertex3f(-20,25,60); //d1
        glVertex3f(25,25,40);//d2
        glVertex3f(45,25,0); //d3
        glVertex3f(45,25,-70); //d4
    glEnd();
}

void atapAtas1_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,30,-95); //a1
        glVertex3f(70,30,-110); //a2
        glVertex3f(95,30,-130); //a3
        glVertex3f(115,30,-150); //a4
        glVertex3f(120,30,-180); //a5
        glVertex3f(120,30,-200); //a6
        glVertex3f(120,30,-220); //a7
        glVertex3f(115,30,-240); //a8
        glVertex3f(110,30,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,30,-300); //a11
        glVertex3f(60,30,-320); //a12
        glVertex3f(30,30,-300); //a13
        glVertex3f(10,30,-280); //a14
        glVertex3f(-20,30,-265); //a15
        //titik b
        glVertex3f(-60,30,-280); //b1
        glVertex3f(-100,30,-320); //b2
        glVertex3f(-130,30,-310); //b3
        glVertex3f(-150,30,-270); //b4
        glVertex3f(-160,30,-230); //b5
        glVertex3f(-160,30,-190); //b6
        glVertex3f(-140,30,-145); //b7
        glVertex3f(-115,30,-105); //b8
        //titik c
        glVertex3f(-115,30,-70); //c1
        glVertex3f(-115,30,0); //c2
        glVertex3f(-95,30,40); //c3
        glVertex3f(-50,30,60); //c4
        //titik d
        glVertex3f(-20,30,60); //d1
        glVertex3f(25,30,40);//d2
        glVertex3f(45,30,0); //d3
        glVertex3f(45,30,-70); //d4
    glEnd();
}

void atapAtas2(){
    //tutup lantai 2
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,60,-95); //a1
        glVertex3f(70,60,-110); //a2
        glVertex3f(95,60,-130); //a3
        glVertex3f(115,60,-150); //a4
        glVertex3f(120,60,-180); //a5
        glVertex3f(120,60,-200); //a6
        glVertex3f(120,60,-220); //a7
        glVertex3f(115,60,-240); //a8
        glVertex3f(110,60,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,60,-300); //a11
        glVertex3f(60,60,-320); //a12
        glVertex3f(30,60,-300); //a13
        glVertex3f(10,60,-280); //a14
        glVertex3f(-20,60,-265); //a15
        //titik b
        glVertex3f(-60,60,-280); //b1
        glVertex3f(-100,60,-290); //b2
        glVertex3f(-130,60,-280); //b3
        glVertex3f(-160,60,-230); //b4
        glVertex3f(-160,60,-190); //b5
        glVertex3f(-140,60,-145); //b6
        glVertex3f(-115,60,-105); //b7
        //titik c
        glVertex3f(-115,60,-70); //c1
        glVertex3f(-95,60,0); //c2
        glVertex3f(-55,60,40); //c3
        //titik d
        glVertex3f(-10,60,40); //d1
        glVertex3f(25,60,0); //d2
        glVertex3f(45,60,-70); //d3
    glEnd();
}

void atapAtas2_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,65,-95); //a1
        glVertex3f(70,65,-110); //a2
        glVertex3f(95,65,-130); //a3
        glVertex3f(115,65,-150); //a4
        glVertex3f(120,65,-180); //a5
        glVertex3f(120,65,-200); //a6
        glVertex3f(120,65,-220); //a7
        glVertex3f(115,65,-240); //a8
        glVertex3f(110,65,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,65,-300); //a11
        glVertex3f(60,65,-320); //a12
        glVertex3f(30,65,-300); //a13
        glVertex3f(10,65,-280); //a14
        glVertex3f(-20,65,-265); //a15
        //titik b
        glVertex3f(-60,65,-280); //b1
        glVertex3f(-100,65,-290); //b2
        glVertex3f(-130,65,-280); //b3
        glVertex3f(-160,65,-230); //b4
        glVertex3f(-160,65,-190); //b5
        glVertex3f(-140,65,-145); //b6
        glVertex3f(-115,65,-105); //b7
        //titik c
        glVertex3f(-115,65,-70); //c1
        glVertex3f(-95,65,0); //c2
        glVertex3f(-55,65,40); //c3
        //titik d
        glVertex3f(-10,65,40); //d1
        glVertex3f(25,65,0); //d2
        glVertex3f(45,65,-70); //d3
    glEnd();
}

void atapAtas3(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,95,-95); //a1
        glVertex3f(70,95,-110); //a2
        glVertex3f(95,95,-130); //a3
        glVertex3f(115,95,-150); //a4
        glVertex3f(120,95,-180); //a5
        glVertex3f(120,95,-200); //a6
        glVertex3f(120,95,-220); //a7
        glVertex3f(115,95,-240); //a8
        glVertex3f(110,95,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,95,-300); //a11
        glVertex3f(60,95,-320); //a12
        glVertex3f(30,95,-300); //a13
        glVertex3f(10,95,-280); //a14
        glVertex3f(-20,95,-265); //a15 3
        //titik b
        glVertex3f(-60,95,-280); //b1
        glVertex3f(-100,95,-290); //b2
        glVertex3f(-130,95,-280); //b3
        glVertex3f(-160,95,-230); //b4
        glVertex3f(-160,95,-190); //b5
        glVertex3f(-140,95,-145); //b6
        glVertex3f(-115,95,-105); //b7
        //titik c
        glVertex3f(-115,95,-70); //c1
        glVertex3f(-95,95,0); //c2
        glVertex3f(-55,95,40); //c3
        //titik d
        glVertex3f(-10,95,40); //d1
        glVertex3f(25,95,0); //d2
        glVertex3f(45,95,-70); //d3
    glEnd();
}

void atapAtas3_2(){
        glBegin(GL_POLYGON);
        glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,100,-95); //a1
        glVertex3f(70,100,-110); //a2
        glVertex3f(95,100,-130); //a3
        glVertex3f(115,100,-150); //a4
        glVertex3f(120,100,-180); //a5
        glVertex3f(120,100,-200); //a6
        glVertex3f(120,100,-220); //a7
        glVertex3f(115,100,-240); //a8
        glVertex3f(110,100,-260); //a9
        // glVertex3f(); //a10
        glVertex3f(90,100,-300); //a11
        glVertex3f(60,100,-320); //a12
        glVertex3f(30,100,-300); //a13
        glVertex3f(10,100,-280); //a14
        glVertex3f(-20,65,-265); //a15
        //titik b
        glVertex3f(-60,100,-280); //b1
        glVertex3f(-100,100,-290); //b2
        glVertex3f(-130,100,-280); //b3
        glVertex3f(-160,100,-230); //b4
        glVertex3f(-160,100,-190); //b5
        glVertex3f(-140,100,-145); //b6
        glVertex3f(-115,100,-105); //b7
        //titik c
        glVertex3f(-115,100,-70); //c1
        glVertex3f(-95,100,0); //c2
        glVertex3f(-55,100,40); //c3
        //titik d
        glVertex3f(-10,100,40); //d1
        glVertex3f(25,100,0); //d2
        glVertex3f(45,100,-70); //d3
    glEnd();
}

void atapAtas4(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,130,-95); //a1
        glVertex3f(70,130,-110); //a2
        glVertex3f(95,130,-130); //a3
        glVertex3f(115,130,-150); //a4
        glVertex3f(120,130,-180); //a5
        glVertex3f(120,130,-200); //a6
        glVertex3f(120,130,-220); //a7
        glVertex3f(115,130,-240); //a8
        glVertex3f(110,130,-260); //a9
        glVertex3f(60,130,-300); //a10
        glVertex3f(10,130,-280); //a11
        glVertex3f(-20,130,-265); //a12
        //titik b
        glVertex3f(-60,130,-280); //b1
        glVertex3f(-100,130,-290); //b2
        glVertex3f(-130,130,-280); //b3
        glVertex3f(-160,130,-230); //b4
        glVertex3f(-160,130,-190); //b5
        glVertex3f(-140,130,-145); //b6
        glVertex3f(-115,130,-105); //b7
        //titik c
        glVertex3f(-115,130,-70); //c1
        glVertex3f(-95,130,0); //c2
        glVertex3f(-55,130,40); //c3
        //titik d
        glVertex3f(-10,130,40); //d1
        glVertex3f(25,130,0); //d2
        glVertex3f(45,130,-70); //d3
    glEnd();
}

void atapAtas4_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,135,-95); //a1
        glVertex3f(70,135,-110); //a2
        glVertex3f(95,135,-130); //a3 1
        glVertex3f(115,135,-150); //a4
        glVertex3f(120,135,-180); //a5
        glVertex3f(120,135,-200); //a6
        glVertex3f(120,135,-220); //a7
        glVertex3f(115,135,-240); //a8
        glVertex3f(110,135,-260); //a9
        glVertex3f(60,135,-300); //a10
        glVertex3f(10,135,-280); //a11
        glVertex3f(-20,135,-265); //a12
        //titik b
        glVertex3f(-60,135,-280); //b1
        glVertex3f(-100,135,-290); //b2
        glVertex3f(-130,135,-280); //b3
        glVertex3f(-160,135,-230); //b4
        glVertex3f(-160,135,-190); //b5
        glVertex3f(-140,135,-145); //b6
        glVertex3f(-115,135,-105); //b7
        //titik c
        glVertex3f(-115,135,-70); //c1
        glVertex3f(-95,135,0); //c2
        glVertex3f(-55,135,40); //c3
        //titik d
        glVertex3f(-10,135,40); //d1
        glVertex3f(25,135,0); //d2
        glVertex3f(45,135,-70); //d3
    glEnd();
}

void atapAtas5(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,160,-95); //a1
        glVertex3f(70,160,-110); //a2
        glVertex3f(95,160,-130); //a3
        glVertex3f(115,160,-150); //a4
        glVertex3f(120,160,-180); //a5
        glVertex3f(120,160,-200); //a6
        glVertex3f(120,160,-220); //a7
        glVertex3f(115,160,-240); //a8
        glVertex3f(110,160,-260); //a9
        glVertex3f(60,160,-300); //a10
        glVertex3f(10,160,-280); //a11
        glVertex3f(-20,160,-265); //a12
        //titik b
        glVertex3f(-60,160,-280); //b1
        glVertex3f(-100,160,-290); //b2
        glVertex3f(-130,160,-280); //b3
        glVertex3f(-160,160,-230); //b4
        glVertex3f(-160,160,-190); //b5
        glVertex3f(-140,160,-145); //b6
        glVertex3f(-115,160,-105); //b7
        //titik c
        glVertex3f(-115,160,-70); //c1
        glVertex3f(-80,160,0); //c2
        glVertex3f(-55,160,10); //c3
        //titik d
        glVertex3f(-10,160,10); //d1
        glVertex3f(10,160,0); //d2
        glVertex3f(45,160,-70); //d3
    glEnd();
}

void atapAtas5_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,165,-95); //a1
        glVertex3f(70,165,-110); //a2
        glVertex3f(95,165,-130); //a3
        glVertex3f(115,165,-150); //a4
        glVertex3f(120,165,-180); //a5
        glVertex3f(120,165,-200); //a6
        glVertex3f(120,165,-220); //a7
        glVertex3f(115,165,-240); //a8
        glVertex3f(110,165,-260); //a9
        glVertex3f(60,165,-300); //a10
        glVertex3f(10,165,-280); //a11
        glVertex3f(-20,165,-265); //a12
        //titik b
        glVertex3f(-60,165,-280); //b1
        glVertex3f(-100,165,-290); //b2
        glVertex3f(-130,165,-280); //b3
        glVertex3f(-160,165,-230); //b4
        glVertex3f(-160,165,-190); //b5
        glVertex3f(-140,165,-145); //b6
        glVertex3f(-115,165,-105); //b7
        //titik c
        glVertex3f(-115,165,-70); //c1
        glVertex3f(-80,165,0); //c2
        glVertex3f(-55,165,10); //c3
        //titik d
        glVertex3f(-10,165,10); //d1
        glVertex3f(10,165,0); //d2
        glVertex3f(45,165,-70); //d3
    glEnd();
}

void atapAtas6(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,210,-95); //a1
        glVertex3f(70,210,-110); //a2
        glVertex3f(95,210,-130); //a3
        glVertex3f(115,210,-150); //a4
        glVertex3f(120,210,-180); //a5
        glVertex3f(120,210,-200); //a6
        glVertex3f(120,210,-220); //a7
        glVertex3f(115,210,-240); //a8
        glVertex3f(110,210,-260); //a9
        glVertex3f(60,210,-300); //a10
        glVertex3f(10,210,-280); //a11
        glVertex3f(-20,210,-265); //a12
        //titik b
        glVertex3f(-60,210,-280); //b1
        glVertex3f(-95,210,-270); //b2
        glVertex3f(-123,210,-260); //b3
        glVertex3f(-150,210,-230); //b4
        glVertex3f(-160,210,-190); //b5
        glVertex3f(-140,210,-145); //b6
        glVertex3f(-115,210,-105); //b7
        //titik c
        glVertex3f(-115,210,-70); //c1
        glVertex3f(-80,210,0); //c2
        glVertex3f(-55,210,10); //c3
        //titik d
        glVertex3f(-10,210,10); //d1
        glVertex3f(10,210,0); //d2
        glVertex3f(45,210,-70); //d3
    glEnd();
}

void atapAtas6_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,215,-95); //a1
        glVertex3f(70,215,-110); //a2
        glVertex3f(95,215,-130); //a3
        glVertex3f(115,215,-150); //a4
        glVertex3f(120,215,-180); //a5
        glVertex3f(120,215,-200); //a6
        glVertex3f(120,215,-220); //a7
        glVertex3f(115,215,-240); //a8
        glVertex3f(110,215,-260); //a9
        glVertex3f(60,215,-300); //a10
        glVertex3f(10,215,-280); //a11
        glVertex3f(-20,215,-265); //a12
        //titik b
        glVertex3f(-60,215,-280); //b1
        glVertex3f(-95,215,-270); //b2
        glVertex3f(-123,215,-260); //b3
        glVertex3f(-150,215,-230); //b4
        glVertex3f(-160,215,-190); //b5
        glVertex3f(-140,215,-145); //b6
        glVertex3f(-115,215,-105); //b7
        //titik c
        glVertex3f(-115,215,-70); //c1
        glVertex3f(-80,215,0); //c2
        glVertex3f(-55,215,10); //c3
        //titik d
        glVertex3f(-10,215,10); //d1
        glVertex3f(10,215,0); //d2
        glVertex3f(45,215,-70); //d3
    glEnd();
}

void atapAtas7(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,255,-95); //a1
        glVertex3f(70,255,-110); //a2
        glVertex3f(95,255,-130); //a3
        glVertex3f(95,255,-210); //a4
        glVertex3f(60,255,-270); //a5
        glVertex3f(10,255,-280); //a6
        glVertex3f(-20,255,-265); //a7
        //titik b
        glVertex3f(-60,255,-280); //b1
        glVertex3f(-95,255,-270); //b2
        glVertex3f(-123,255,-260); //b3
        glVertex3f(-150,255,-230); //b4
        glVertex3f(-160,255,-190); //b5
        glVertex3f(-140,255,-145); //b6
        glVertex3f(-115,255,-105); //b7
        //titik c
        glVertex3f(-115,255,-70); //c1
        glVertex3f(-80,255,0); //c2
        glVertex3f(-55,255,10); //c3
        //titik d
        glVertex3f(-10,255,10); //d1
        glVertex3f(10,255,0); //d2
        glVertex3f(45,255,-70); //d3
    glEnd();
}

void atapAtas7_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,260,-95); //a1
        glVertex3f(70,260,-110); //a2
        glVertex3f(95,260,-130); //a3
        glVertex3f(95,260,-210); //a4
        glVertex3f(60,260,-270); //a5
        glVertex3f(10,260,-280); //a6
        glVertex3f(-20,260,-265); //a7
        //titik b
        glVertex3f(-60,260,-280); //b1
        glVertex3f(-95,260,-270); //b2
        glVertex3f(-123,260,-260); //b3
        glVertex3f(-150,260,-230); //b4
        glVertex3f(-160,260,-190); //b5
        glVertex3f(-140,260,-145); //b6
        glVertex3f(-115,260,-105); //b7
        //titik c
        glVertex3f(-115,260,-70); //c1
        glVertex3f(-80,260,0); //c2
        glVertex3f(-55,260,10); //c3
        //titik d
        glVertex3f(-10,260,10); //d1
        glVertex3f(10,260,0); //d2
        glVertex3f(45,260,-70); //d3
    glEnd();
}

void atapAtas8(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,290,-95); //a1
        glVertex3f(70,290,-110); //a2
        glVertex3f(95,290,-130); //a3
        glVertex3f(95,290,-210); //a4
        glVertex3f(60,290,-270); //a5
        glVertex3f(10,290,-280); //a6
        glVertex3f(-20,290,-265); //a7
        //titik b
        glVertex3f(-60,290,-280); //b1
        glVertex3f(-95,290,-270); //b2
        glVertex3f(-123,290,-260); //b3
        glVertex3f(-150,290,-230); //b4
        glVertex3f(-160,290,-190); //b5
        glVertex3f(-140,290,-145); //b6
        glVertex3f(-115,290,-105); //b7
        //titik c
        glVertex3f(-115,290,-70); //c1
        glVertex3f(-80,290,-30); //c2
        glVertex3f(-55,290,-20); //c3
        //titik d
        glVertex3f(-10,290,-20); //d1
        glVertex3f(10,290,-30); //d2
        glVertex3f(45,290,-70); //d3
    glEnd();
}

void atapAtas8_2(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
        //titik a
        glVertex3f(45,295,-95); //a1
        glVertex3f(70,295,-110); //a2
        glVertex3f(95,295,-130); //a3
        glVertex3f(95,295,-210); //a4
        glVertex3f(60,295,-270); //a5
        glVertex3f(10,295,-280); //a6
        glVertex3f(-20,295,-265); //a7
        //titik b
        glVertex3f(-60,295,-280); //b1
        glVertex3f(-95,295,-270); //b2
        glVertex3f(-123,295,-260); //b3
        glVertex3f(-150,295,-230); //b4
        glVertex3f(-160,295,-190); //b5
        glVertex3f(-140,295,-145); //b6
        glVertex3f(-115,295,-105); //b7
        //titik c
        glVertex3f(-115,295,-70); //c1
        glVertex3f(-80,295,-30); //c2
        glVertex3f(-55,295,-20); //c3
        //titik d
        glVertex3f(-10,295,-20); //d1
        glVertex3f(10,295,-30); //d2
        glVertex3f(45,295,-70); //d3
    glEnd();
}

// ATAP

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(xrot, 1,0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();

    // LANTAI 1
    lantai1();
    line1();
    atapBawah1();
    atapAtas1();
    atapAtas1_2();

    // LANTAI 2
    lantai2();
    atapAtas2();
    line2();
    atapAtas2_2();

    // LANTAI 3
    lantai3();
    atapAtas3();
    line3();
    atapAtas3_2();

    // LANTAI 4
    lantai4();
    atapAtas4();
    line4();
    atapAtas4_2();

    //LANTAI 5
    lantai5();
    atapAtas5();
    line5();
    atapAtas5_2();

    //LANTAI 6
    lantai6();
    atapAtas6();
    line6();
    atapAtas6_2();

    //LANTAI 7
    lantai7();
    atapAtas7();
    line7();
    atapAtas7_2();

    // //LANTAI 8
    lantai8();
    atapAtas8();
    line8();
    atapAtas8_2();

    // //LANTAI 9
    lantai9();

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
    gluPerspective(100.0, lebar/tinggi,5.0,1000.0);
    glTranslatef(0.0,-100.0,-550.0);

    glMatrixMode(GL_MODELVIEW);
}
