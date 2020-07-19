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


//start_daniel
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
        glVertex3f(-20,60,-265);
        glVertex3f(-20,30,-265);
        glVertex3f(-60,30,-280);
        glVertex3f(-60,60,-280);
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

void atapAtas1_2(){
    //tutup lantai 1 yang kedua (atasnya line putih)
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
//end_daniel



void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(xrot, 1,0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();

    atapBawah1();
    lantai1();
    atapAtas1();
    line1();
    atapAtas1_2();



    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();

}
