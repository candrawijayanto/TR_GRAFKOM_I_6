#include<windows.h>
#ifdef APPLE
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int pintu =1;
int a;
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

int redisplay = 0;

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle = rotAngle*3.14159265/180;
    angleInc = 2*3.14159265/n;

    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        for(k=0; k<n; k++){
            angle += angleInc;
            glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        }
}
void waktu(int i)
{
    a+=5;
	glutTimerFunc(1000, waktu, 10);//mengatur waktu
	glutPostRedisplay();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(950,650);
    glutInitWindowPosition(250,80);
    glutCreateWindow("");
    init();
    glutDisplayFunc(tampil);
    waktu(10);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0,0,0,0);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}



// OBJEK
void kanopi(){
    glBegin(GL_QUADS);
        glColor3ub(42, 156, 201);
        //a13
        glVertex3f(60,22,-320);
        glVertex3f(60,25,-320);
        glVertex3f(30,25,-300);
        glVertex3f(30,22,-320);
        //a14
        glVertex3f(30,25,-300);
        glVertex3f(30,22,-320);
        glVertex3f(10,22,-320);
        glVertex3f(10,25,-280);
        //a15
        glVertex3f(10,22,-320);
        glVertex3f(10,25,-280);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,22,-320);
        //b1
        glVertex3f(-20,25,-265);
        glVertex3f(-20,22,-320);
        glVertex3f(-60,22,-320);
        glVertex3f(-60,25,-280);
        //b2
        glVertex3f(-60,22,-320);
        glVertex3f(-60,25,-280);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,22,-320);
    glEnd();

    //tiang
    glLineWidth(15);
    glBegin(GL_LINES);
        glVertex3f(20,24,-315);
        glVertex3f(20,-40,-315);
        glVertex3f(-60,24,-315);
        glVertex3f(-60,-40,-315);
    glEnd();
}

void waitingRoom (void){
    //meja resepsionis
    glBegin(GL_QUADS);
        glColor3ub(219, 192, 112);
        //a1
        glVertex3f(-95,-40,5);
        glVertex3f(-95,-10,5);
        glVertex3f(-49,-10,-7);
        glVertex3f(-49,-40,-7);
        //a2
        glColor3ub(255, 225, 135);
        glVertex3f(-95,-10,5);
        glVertex3f(-95,-10,20);
        glVertex3f(-49,-10,20);
        glVertex3f(-49,-10,-7);
        //b1
        glColor3ub(219, 192, 112);
        glVertex3f(25,-40,5);
        glVertex3f(25,-10,5);
        glVertex3f(-20,-10,-7);
        glVertex3f(-20,-40,-7);
        //b2
        glColor3ub(255, 225, 135);
        glVertex3f(25,-10,5);
        glVertex3f(25,-10,20);
        glVertex3f(-20,-10,20);
        glVertex3f(-20,-10,-7);
        //c1
        glColor3ub(219, 192, 112);
        glVertex3f(-49,-40,-7);
        glVertex3f(-49,-10,-7);
        glVertex3f(-20,-10,-7);
        glVertex3f(-20,-40,-7);
        //c2
        glColor3ub(255, 225, 135);
        glVertex3f(-49,-10,-7);
        glVertex3f(-49,-10,20);
        glVertex3f(-20,-10,20);
        glVertex3f(-20,-10,-7);
    glEnd();

    //sofa
    glBegin(GL_QUADS);
    glColor3ub(255, 225, 135);
        //kiri
        glVertex3f(-105,-25,-30);
        glVertex3f(-105,-25,-90);
        glVertex3f(-80,-25,-90);
        glVertex3f(-80,-25,-30);
        //kanan
        glVertex3f(35,-25,-30);
        glVertex3f(35,-25,-90);
        glVertex3f(10,-25,-90);
        glVertex3f(10,-25,-30);
    glEnd();

    //kaki sofa
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3ub(130, 98, 0);
        //kiri1
        glVertex3f(-104,-25,-32);
        glVertex3f(-104,-40,-32);
        //2
        glVertex3f(-104,-25,-88);
        glVertex3f(-104,-40,-88);
        //3
        glVertex3f(-81,-25,-32);
        glVertex3f(-81,-40,-32);
        //4
        glVertex3f(-81,-25,-88);
        glVertex3f(-81,-40,-88);
        //kanan1
        glVertex3f(11,-25,-32);
        glVertex3f(11,-40,-32);
        //2
        glVertex3f(11,-25,-88);
        glVertex3f(11,-40,-88);
        //3
        glVertex3f(34,-25,-32);
        glVertex3f(34,-40,-32);
        //4
        glVertex3f(34,-25,-88);
        glVertex3f(34,-40,-88);
    glEnd();

    //lukisan
    glBegin(GL_QUADS);
        glColor3ub(173, 150, 80);
        //kiri
        glVertex3f(-95,-10,39.5);
        glVertex3f(-95,20,39.5);
        glVertex3f(-49,20,59.5);
        glVertex3f(-49,-10,59.5);
        //kanan
        glVertex3f(25,-10,39.5);
        glVertex3f(25,20,39.5);
        glVertex3f(-20,20,59.5);
        glVertex3f(-20,-10,59.5);
        //gambar kiri
        glColor3ub(129, 209, 230);
        glVertex3f(-90,-5,39.5);
        glVertex3f(-90,15,39.5);
        glVertex3f(-54,15,56.5);
        glVertex3f(-54,-5,56.5);
        //gambar kanan
        glVertex3f(20,-5,39.5);
        glVertex3f(20,15,39.5);
        glVertex3f(-15,15,56.5);
        glVertex3f(-15,-5,56.5);
    glEnd();

    //meja tengah
    glBegin(GL_POLYGON);
        glColor3ub(255, 225, 135);
        glVertex3f(-59,-15,-120);
        glVertex3f(-62,-15,-125);
        glVertex3f(-62,-15,-175);
        glVertex3f(-59,-15,-180);
        glVertex3f(-10,-15,-180);
        glVertex3f(-7,-15,-175);
        glVertex3f(-7,-15,-125);
        glVertex3f(-10,-15,-120);
    glEnd();

    //kaki meja
    glLineWidth(10);
    glBegin(GL_LINES);
        glColor3ub(130, 98, 0);
        glVertex3f(-32,-15,-145);
        glVertex3f(-32,-39,-145);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
        //meja
        glVertex3f(-40,-39,-153);
        glVertex3f(-40,-39,-137);
        glVertex3f(-24,-39,-137);
        glVertex3f(-24,-39,-153);
        //lampu
        glVertex3f(55,-39,-125);
        glVertex3f(55,-39,-135);
        glVertex3f(65,-39,-135);
        glVertex3f(65,-39,-125);
    glEnd();

    //lampu
    glBegin(GL_TRIANGLES);
        glColor3ub(255, 225, 135);
        //1
        glVertex3f(50,0,-120);
        glVertex3f(70,0,-120);
        glVertex3f(60,20,-130);
        //2
        glVertex3f(50,0,-120);
        glVertex3f(50,0,-140);
        glVertex3f(60,20,-130);
        //3
        glVertex3f(50,0,-140);
        glVertex3f(70,0,-140);
        glVertex3f(60,20,-130);
        //4
        glVertex3f(70,0,-120);
        glVertex3f(70,0,-140);
        glVertex3f(60,20,-130);
    glEnd();

    //kaki lampu
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3ub(130, 98, 0);
        glVertex3f(60,15,-130);
        glVertex3f(60,-39,-130);
    glEnd();

    //lift
    glBegin(GL_QUADS);
        glColor3ub(166, 166, 166);
        //belakang
        glVertex3f(115,25,-180);
        glVertex3f(110,25,-250);
        glVertex3f(110,-40,-250);
        glVertex3f(115,-40,-180);
        //samping kanan
        glVertex3f(90,25,-180);
        glVertex3f(115,25,-180);
        glVertex3f(115,-40,-180);
        glVertex3f(90,-40,-180);
        //depan
        glVertex3f(90,25,-180);
        glVertex3f(85,25,-250);
        glVertex3f(85,-40,-250);
        glVertex3f(90,-40,-180);
        //samping kiri
        glVertex3f(85,25,-250);
        glVertex3f(110,25,-250);
        glVertex3f(110,-40,-250);
        glVertex3f(85,-40,-250);
    glEnd();

    //batas lift
    glBegin(GL_LINES);
        glColor3ub(92, 92, 92);
        //blkg
        glVertex3f(84,15,-245);
        glVertex3f(84,-40,-245);
        //muka
        glVertex3f(86,15,-190);
        glVertex3f(86,-40,-190);
        //tenga
        glVertex3f(84,15,-218);
        glVertex3f(84,-40,-218);
        //atas
        glVertex3f(84,15,-245);
        glVertex3f(86,15,-190);
        //tombol
        glVertex3f(86,-5,-185);
        glVertex3f(86,-15,-185);
        glColor3f(0,0,0);
        glVertex3f(84,20,-222);
        glVertex3f(84,20,-214);
    glEnd();
}

void tanah(){

//atas
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
        glVertex3f(-400,-40.1,-390);
        glVertex3f(-400,-40.1,200);
        glVertex3f(400,-40.1,200);
        glVertex3f(400,-40.1,-390);
    glEnd();

//bawah
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
        glVertex3f(-400,-60.1,-390);
        glVertex3f(-400,-60.1,200);
        glVertex3f(400,-60.1,200);
        glVertex3f(400,-60.1,-390);
    glEnd();

//depan
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
        glVertex3f(-400,-60.1,200);
        glVertex3f(-400,-40.1,200);
        glVertex3f(400,-40.1,200);
        glVertex3f(400,-60.1,200);
    glEnd();

//belakang
    glBegin(GL_QUADS);
    glColor3ub(192,192,192);
        glVertex3f(-400,-60.1,-390);
        glVertex3f(-400,-40.1,-390);
        glVertex3f(400,-40.1,-390);
        glVertex3f(400,-60.1,-390);
    glEnd();


//kanan
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(400,-40.1,200);
        glVertex3f(400,-40.1,-390);
        glVertex3f(400,-60.1,-390);
         glVertex3f(400,-60.1,200);
    glEnd();

//kiri
    glBegin(GL_QUADS);
    glColor3ub(255,255,0);
        glVertex3f(-400,-40.1,200);
        glVertex3f(-400,-40.1,-390);
        glVertex3f(-400,-60.1,-390);
        glVertex3f(-400,-60.1,200);
    glEnd();
}

void kolam(){

//atas
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(200,-20.1,-390);
        glVertex3f(200,-20.1,-100);
        glVertex3f(300,-20.1,-100);
        glVertex3f(300,-20.1,-390);
    glEnd();

//bawah
    glBegin(GL_QUADS);
    glColor3ub(0,255,255);
        glVertex3f(200,-39.1,-390);
        glVertex3f(200,-39.1,-100);
        glVertex3f(300,-39.1,-100);
        glVertex3f(300,-39.1,-390);
    glEnd();

//depan
    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
        glVertex3f(200,-20.1,-100);
        glVertex3f(200,-39.1,-100);
        glVertex3f(300,-39.1,-100);
        glVertex3f(300,-20.1,-100);
    glEnd();

//belakang
    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
        glVertex3f(200,-20.1,-390);
        glVertex3f(200,-39.1,-390);
        glVertex3f(300,-39.1,-390);
        glVertex3f(300,-20.1,-390);
    glEnd();


//kanan
    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
        glVertex3f(300,-39.1,-100);
        glVertex3f(300,-39.1,-390);
        glVertex3f(300,-20.1,-390);
         glVertex3f(300,-20.1,-100);
    glEnd();

//kiri
    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
        glVertex3f(200,-39.1,-100);
        glVertex3f(200,-39.1,-390);
        glVertex3f(200,-20.1,-390);
        glVertex3f(200,-20.1,-100);
    glEnd();

//KURSI 1
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
        //depan
        glVertex3f(320,-40,-320);
        glVertex3f(320,-40,-300);
        glVertex3f(320,-20.1,-300);
        glVertex3f(320,-20.1,-320);
        //belakang
        glVertex3f(330,-40,-320);
        glVertex3f(330,-40,-300);
        glVertex3f(330,-20.1,-300);
        glVertex3f(330,-20.1,-320);
        //atas
        glVertex3f(320,-20.1,-320);
        glVertex3f(320,-20.1,-300);
        glVertex3f(330,-20.1,-300);
        glVertex3f(330,-20.1,-320);
        //bawah
        glVertex3f(320,-40,-320);
        glVertex3f(320,-40,-300);
        glVertex3f(330,-40,-300);
        glVertex3f(330,-40,-320);
        //kiri
        glVertex3f(330,-20.1,-300);
        glVertex3f(330,-39.1,-300);
        glVertex3f(320,-39.1,-300);
        glVertex3f(320,-20.1,-300);
        //kanan
        glVertex3f(330,-20.1,-320);
        glVertex3f(330,-39.1,-320);
        glVertex3f(320,-39.1,-320);
        glVertex3f(320,-20.1,-320);

        //KURSI 2
        //depan
        glVertex3f(320,-40,-220);
        glVertex3f(320,-40,-200);
        glVertex3f(320,-20.1,-200);
        glVertex3f(320,-20.1,-220);
        //belakang
        glVertex3f(330,-40,-220);
        glVertex3f(330,-40,-200);
        glVertex3f(330,-20.1,-200);
        glVertex3f(330,-20.1,-220);
        //atas
        glVertex3f(320,-20.1,-220);
        glVertex3f(320,-20.1,-200);
        glVertex3f(330,-20.1,-200);
        glVertex3f(330,-20.1,-220);
        //bawah
        glVertex3f(320,-40,-220);
        glVertex3f(320,-40,-200);
        glVertex3f(330,-40,-200);
        glVertex3f(330,-40,-220);
        //kiri
        glVertex3f(330,-20.1,-200);
        glVertex3f(330,-39.1,-200);
        glVertex3f(320,-39.1,-200);
        glVertex3f(320,-20.1,-200);
        //kanan
        glVertex3f(330,-20.1,-220);
        glVertex3f(330,-39.1,-220);
        glVertex3f(320,-39.1,-220);
        glVertex3f(320,-20.1,-220);
    glEnd();

//PAYUNG
    glBegin(GL_QUADS);
    glColor3ub(184,134,11);
        //bawah
        glVertex3f(320,-40,-260);
        glVertex3f(320,-40,-280);
        glVertex3f(330,-40,-280);
        glVertex3f(330,-40,-260);
        //tiang
        glVertex3f(325,-40.1,-265);
        glVertex3f(325,-40.1,-275);
        glVertex3f(325,10,-275);
        glVertex3f(325,10,-265);
        //atap kiri
        glVertex3f(340,10,-270);
        glVertex3f(340,0,-245);
        glVertex3f(320,0,-245);
        glVertex3f(320,10,-270);
         //atap kanan
        glVertex3f(320,10,-270);
        glVertex3f(320,0,-295);
        glVertex3f(340,0,-295);
        glVertex3f(340,10,-270);



}

void jalanraya(){

//jalan
    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
        glVertex3f(-400,-39.9,90);
        glVertex3f(-400,-39.9,190);
        glVertex3f(400,-39.9,190);
        glVertex3f(400,-39.9,90);
    glEnd();
    //garis jalan
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
        glVertex3f(-300,-39.5,150); glVertex3f(-200,-39.5,150);
        glVertex3f(-100,-39.5,150); glVertex3f(0,-39.,150);
        glVertex3f(100,-39.5,150); glVertex3f(200,-39.5,150);
        glVertex3f(300,-39.5,150); glVertex3f(400,-39.5,150);
    glEnd();


}

void bulat(){
    glPushMatrix();
	glLineWidth(3.0f);
	glRotated(a, 0, 0, -1);
	glBegin(GL_POLYGON);
	if(a%2==0){
        glColor3f(1.0, 0.0, 0.0);
        ngon(100, 0, 0, 15, 180);
	}
	else{
        glColor3f(0.0, 0.0, 1.0);
        ngon(100, 0, 0, 15, 180);
	}
    glEnd();
	glPopMatrix();
    //matahari
	glPushMatrix();
	glRotated(a, 0, 0, -1);
	glLineWidth(8.0f);
	glBegin(GL_LINES);

    if(a%2==0){
        glColor3f(1.0, 1.0, 1.0);
        //ngon(100, 20, 20, 5, 180);
        glVertex2f(15,0);glVertex2f(25,10);
        glVertex2f(11.5,10);glVertex2f(25,10);
        glVertex2f(-15,0);glVertex2f(-25,10);
        glVertex2f(-11.5,10);glVertex2f(-25,10);

        glVertex2f(15,0);glVertex2f(25,-10);
        glVertex2f(11.5,-10);glVertex2f(25,-10);
        glVertex2f(-15,0);glVertex2f(-25,-10);
        glVertex2f(-11.5,-10);glVertex2f(-25,-10);

        glVertex2f(-11,10);glVertex2f(-11,24);
        glVertex2f(-11,24);glVertex2f(0,15);
        glVertex2f(11,24);glVertex2f(0,15);
        glVertex2f(11,10);glVertex2f(11,24);

        glVertex2f(-11,-10);glVertex2f(-11,-24);
        glVertex2f(-11,-24);glVertex2f(0,-15);
        glVertex2f(11,-24);glVertex2f(0,-15);
        glVertex2f(11,-10);glVertex2f(11,-24);
	}
	else{
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(15,0);glVertex2f(25,10);
        glVertex2f(11.5,10);glVertex2f(25,10);
        glVertex2f(-15,0);glVertex2f(-25,10);
        glVertex2f(-11.5,10);glVertex2f(-25,10);

        glVertex2f(15,0);glVertex2f(25,-10);
        glVertex2f(11.5,-10);glVertex2f(25,-10);
        glVertex2f(-15,0);glVertex2f(-25,-10);
        glVertex2f(-11.5,-10);glVertex2f(-25,-10);

        glVertex2f(-11,10);glVertex2f(-11,24);
        glVertex2f(-11,24);glVertex2f(0,15);
        glVertex2f(11,24);glVertex2f(0,15);
        glVertex2f(11,10);glVertex2f(11,24);

        glVertex2f(-11,-10);glVertex2f(-11,-24);
        glVertex2f(-11,-24);glVertex2f(0,-15);
        glVertex2f(11,-24);glVertex2f(0,-15);
        glVertex2f(11,-10);glVertex2f(11,-24);
	}
	glEnd();
	glPopMatrix();
    //Bulat Ke-2

	//Bulat Ke-3
}
// OBJEK

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
    glColor3ub(131,167,196);
        glVertex3f(45,25,-95);
        glVertex3f(45,-40,-95);
        glVertex3f(70,-40,-110);
        glVertex3f(70,25,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(70,-40,-110);
        glVertex3f(70,25,-110);
        glVertex3f(95,25,-130);
        glVertex3f(95,-40,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,25,-130);
        glVertex3f(95,-40,-130);
        glVertex3f(115,-40,-150);
        glVertex3f(115,25,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(115,-40,-150);
        glVertex3f(115,25,-150);
        glVertex3f(120,25,-180);
        glVertex3f(120,-40,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(120,25,-180);
        glVertex3f(120,25,-200);
        glVertex3f(120,-40,-200);
        glVertex3f(120,-40,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(120,-40,-220);
        glVertex3f(120,-40,-200);
        glVertex3f(120,25,-200);
        glVertex3f(120,25,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(115,-40,-240);
        glVertex3f(120,-40,-220);
        glVertex3f(120,25,-220);
        glVertex3f(115,25,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(115,-40,-240);
        glVertex3f(110,-40,-260);
        glVertex3f(110,25,-260);
        glVertex3f(115,25,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(100,-40,-280);
        glVertex3f(100,25,-280);
        glVertex3f(110,25,-260);
        glVertex3f(110,-40,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(100,25,-280);
        glVertex3f(100,-40,-280);
        glVertex3f(90,-40,-300);
        glVertex3f(90,25,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(90,25,-300);
        glVertex3f(90,-40,-300);
        glVertex3f(60,-40,-320);
        glVertex3f(60,25,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(60,-40,-320);
        glVertex3f(60,25,-320);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
        glVertex3f(10,-40,-280);
        glVertex3f(10,25,-280);
    glEnd();

     //A15
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(10,-40,-280);
        glVertex3f(10,25,-280);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,-40,-265);
    glEnd();

    //A16
    if(pintu %2 == 0){
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-20,25,-265);
        glVertex3f(-20,-40,-265);
        glVertex3f(-20,-40,-300);
        glVertex3f(-20,25,-300);
    glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3ub(80,120,156);
            glVertex3f(-20,25,-265);
            glVertex3f(-20,-40,-265);
            glVertex3f(-60,-40,-280);
            glVertex3f(-60,25,-280);
        glEnd();    
    }

    //B2
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-60,-40,-280);
        glVertex3f(-60,25,-280);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,-40,-320);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,-40,-320);
        glVertex3f(-130,-40,-310);
        glVertex3f(-130,25,-310);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-130,-40,-310);
        glVertex3f(-130,25,-310);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,-40,-270);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-150,25,-270);
        glVertex3f(-150,-40,-270);
        glVertex3f(-160,-40,-230);
        glVertex3f(-160,25,-230);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-160,-40,-230);
        glVertex3f(-160,25,-230);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,-40,-190);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,25,-190);
        glVertex3f(-160,-40,-190);
        glVertex3f(-140,-40,-145);
        glVertex3f(-140,25,-145);
    glEnd();

    //B8
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
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
    glColor3ub(80,120,156);
        glVertex3f(-115,-40,-70);
        glVertex3f(-115,25,-70);
        glVertex3f(-115,25,0);
        glVertex3f(-115,-40,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-115,25,0);
        glVertex3f(-115,-40,0);
        glVertex3f(-95,-40,40);
        glVertex3f(-95,25,40);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-95,-40,40);
        glVertex3f(-95,25,40);
        glVertex3f(-50,25,60);
        glVertex3f(-50,-40,60);
    glEnd();

    if(pintu %2 == 0){
    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-50,25,60);
        glVertex3f(-50,-40,60);
        glVertex3f(-50,-40,100);
        glVertex3f(-50,25,100);
    glEnd();
    }
    else{
    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-50,25,60);
        glVertex3f(-50,-40,60);
        glVertex3f(-20,-40,60);
        glVertex3f(-20,25,60);
    glEnd();
    }

    //D2
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(25,-40,40);
        glVertex3f(25,25,40);
        glVertex3f(-20,25,60);
        glVertex3f(-20,-40,60);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,25,0);
        glVertex3f(45,-40,0);
        glVertex3f(25,-40,40);
        glVertex3f(25,25,40);
    glEnd();

        //D4
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(45,-40,-70);
        glVertex3f(45,25,-70);
        glVertex3f(45,25,0);
        glVertex3f(45,-40,0);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(-60,-40,-280);
        glVertex3f(-60,25,-280);
        glVertex3f(-100,25,-320);
        glVertex3f(-100,-40,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(80,120,156);
        glVertex3f(60,-40,-320);
        glVertex3f(60,25,-320);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(30,25,-300);
        glVertex3f(30,-40,-300);
        glVertex3f(10,-40,-280);
        glVertex3f(10,25,-280);
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
    glColor3ub(59,172,236);
        glVertex3f(45,60,-95);
        glVertex3f(45,30,-95);
        glVertex3f(70,30,-110);
        glVertex3f(70,60,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,30,-110);
        glVertex3f(70,60,-110);
        glVertex3f(95,60,-130);
        glVertex3f(95,30,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(95,60,-130);
        glVertex3f(95,30,-130);
        glVertex3f(115,30,-150);
        glVertex3f(115,60,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,30,-150);
        glVertex3f(115,60,-150);
        glVertex3f(120,60,-180);
        glVertex3f(120,30,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(120,60,-180);
        glVertex3f(120,60,-200);
        glVertex3f(120,30,-200);
        glVertex3f(120,30,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(120,30,-220);
        glVertex3f(120,30,-200);
        glVertex3f(120,60,-200);
        glVertex3f(120,60,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(115,30,-240);
        glVertex3f(120,30,-220);
        glVertex3f(120,60,-220);
        glVertex3f(115,60,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,30,-240);
        glVertex3f(110,30,-260);
        glVertex3f(110,60,-260);
        glVertex3f(115,60,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(100,30,-280);
        glVertex3f(100,60,-280);
        glVertex3f(110,60,-260);
        glVertex3f(110,30,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(100,60,-280);
        glVertex3f(100,30,-280);
        glVertex3f(90,30,-300);
        glVertex3f(90,60,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(90,60,-300);
        glVertex3f(90,30,-300);
        glVertex3f(60,30,-320);
        glVertex3f(60,60,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(60,30,-320);
        glVertex3f(60,60,-320);
        glVertex3f(30,60,-300);
        glVertex3f(30,30,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(30,60,-300);
        glVertex3f(30,30,-300);
        glVertex3f(10,30,-280);
        glVertex3f(10,60,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(59,172,236);
        glVertex3f(-130,60,-280);
        glVertex3f(-130,30,-280);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,60,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-160,30,-230);
        glVertex3f(-160,60,-230);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,30,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
        glVertex3f(-160,60,-190);
        glVertex3f(-160,30,-190);
        glVertex3f(-140,30,-145);
        glVertex3f(-140,60,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,30,-70);
        glVertex3f(-115,60,-70);
        glVertex3f(-95,60,0);
        glVertex3f(-95,30,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(59,172,236);
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
    glColor3ub(59,172,236);
        glVertex3f(25,60,0);
        glVertex3f(25,30,0);
        glVertex3f(-10,30,40);
        glVertex3f(-10,60,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,95,-95);
        glVertex3f(45,65,-95);
        glVertex3f(70,65,-110);
        glVertex3f(70,95,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,65,-110);
        glVertex3f(70,95,-110);
        glVertex3f(95,95,-130);
        glVertex3f(95,65,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,95,-130);
        glVertex3f(95,65,-130);
        glVertex3f(115,65,-150);
        glVertex3f(115,95,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,65,-150);
        glVertex3f(115,95,-150);
        glVertex3f(120,95,-180);
        glVertex3f(120,65,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(120,95,-180);
        glVertex3f(120,95,-200);
        glVertex3f(120,65,-200);
        glVertex3f(120,65,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(120,65,-220);
        glVertex3f(120,65,-200);
        glVertex3f(120,95,-200);
        glVertex3f(120,95,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(115,65,-240);
        glVertex3f(120,65,-220);
        glVertex3f(120,95,-220);
        glVertex3f(115,95,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,65,-240);
        glVertex3f(110,65,-260);
        glVertex3f(110,95,-260);
        glVertex3f(115,95,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(100,65,-280);
        glVertex3f(100,95,-280);
        glVertex3f(110,95,-260);
        glVertex3f(110,65,-260);
    glEnd();

  //A11
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(100,95,-280);
        glVertex3f(100,65,-280);
        glVertex3f(90,65,-300);
        glVertex3f(90,95,-300);
    glEnd();

  //A12
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(90,95,-300);
        glVertex3f(90,65,-300);
        glVertex3f(60,65,-320);
        glVertex3f(60,95,-320);
    glEnd();

    //A13
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(60,65,-320);
        glVertex3f(60,95,-320);
        glVertex3f(30,95,-300);
        glVertex3f(30,65,-300);
    glEnd();

    //A14
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(30,95,-300);
        glVertex3f(30,65,-300);
        glVertex3f(10,65,-280);
        glVertex3f(10,95,-280);
    glEnd();

    //A15
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-130,95,-280);
        glVertex3f(-130,65,-280);
        glVertex3f(-160,65,-230);
        glVertex3f(-160,95,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-160,65,-230);
        glVertex3f(-160,95,-230);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,65,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,95,-190);
        glVertex3f(-160,65,-190);
        glVertex3f(-140,65,-145);
        glVertex3f(-140,95,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,65,-70);
        glVertex3f(-115,95,-70);
        glVertex3f(-95,95,0);
        glVertex3f(-95,65,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(25,95,0);
        glVertex3f(25,65,0);
        glVertex3f(-10,65,40);
        glVertex3f(-10,95,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,100,-95);
        glVertex3f(45,130,-95);
        glVertex3f(70,130,-110);
        glVertex3f(70,100,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,130,-110);
        glVertex3f(70,100,-110);
        glVertex3f(95,100,-130);
        glVertex3f(95,130,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,100,-130);
        glVertex3f(95,130,-130);
        glVertex3f(115,130,-150);
        glVertex3f(115,100,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,130,-150);
        glVertex3f(115,100,-150);
        glVertex3f(120,100,-180);
        glVertex3f(120,130,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(120,100,-180);
        glVertex3f(120,100,-200);
        glVertex3f(120,130,-200);
        glVertex3f(120,130,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(120,130,-220);
        glVertex3f(120,130,-200);
        glVertex3f(120,100,-200);
        glVertex3f(120,100,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(115,130,-240);
        glVertex3f(120,130,-220);
        glVertex3f(120,100,-220);
        glVertex3f(115,100,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,130,-240);
        glVertex3f(110,130,-260);
        glVertex3f(110,100,-260);
        glVertex3f(115,100,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,130,-300);
        glVertex3f(60,100,-300);
        glVertex3f(110,100,-260);
        glVertex3f(110,130,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,100,-300);
        glVertex3f(60,130,-300);
        glVertex3f(10,130,-280);
        glVertex3f(10,100,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-130,100,-280);
        glVertex3f(-130,130,-280);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,100,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-160,130,-230);
        glVertex3f(-160,100,-230);
        glVertex3f(-160,100,-190);
        glVertex3f(-160,130,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,100,-190);
        glVertex3f(-160,130,-190);
        glVertex3f(-140,130,-145);
        glVertex3f(-140,100,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,130,-70);
        glVertex3f(-115,100,-70);
        glVertex3f(-95,100,0);
        glVertex3f(-95,130,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(25,100,0);
        glVertex3f(25,130,0);
        glVertex3f(-10,130,40);
        glVertex3f(-10,100,40);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,160,-95);
        glVertex3f(45,135,-95);
        glVertex3f(70,135,-110);
        glVertex3f(70,160,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,135,-110);
        glVertex3f(70,160,-110);
        glVertex3f(95,160,-130);
        glVertex3f(95,135,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,160,-130);
        glVertex3f(95,135,-130);
        glVertex3f(115,135,-150);
        glVertex3f(115,160,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,135,-150);
        glVertex3f(115,160,-150);
        glVertex3f(120,160,-180);
        glVertex3f(120,135,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(120,160,-180);
        glVertex3f(120,160,-200);
        glVertex3f(120,135,-200);
        glVertex3f(120,135,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(120,135,-220);
        glVertex3f(120,135,-200);
        glVertex3f(120,160,-200);
        glVertex3f(120,160,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(115,135,-240);
        glVertex3f(120,135,-220);
        glVertex3f(120,160,-220);
        glVertex3f(115,160,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,135,-240);
        glVertex3f(110,135,-260);
        glVertex3f(110,160,-260);
        glVertex3f(115,160,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,135,-300);
        glVertex3f(60,160,-300);
        glVertex3f(110,160,-260);
        glVertex3f(110,135,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,160,-300);
        glVertex3f(60,135,-300);
        glVertex3f(10,135,-280);
        glVertex3f(10,160,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-130,160,-280);
        glVertex3f(-130,135,-280);
        glVertex3f(-160,135,-230);
        glVertex3f(-160,160,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-160,135,-230);
        glVertex3f(-160,160,-230);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,135,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,160,-190);
        glVertex3f(-160,135,-190);
        glVertex3f(-140,135,-145);
        glVertex3f(-140,160,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,135,-70);
        glVertex3f(-115,160,-70);
        glVertex3f(-80,160,0);
        glVertex3f(-80,135,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(10,160,0);
        glVertex3f(10,135,0);
        glVertex3f(-10,135,10);
        glVertex3f(-10,160,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,210,-95);
        glVertex3f(45,165,-95);
        glVertex3f(70,165,-110);
        glVertex3f(70,210,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,165,-110);
        glVertex3f(70,210,-110);
        glVertex3f(95,210,-130);
        glVertex3f(95,165,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,210,-130);
        glVertex3f(95,165,-130);
        glVertex3f(115,165,-150);
        glVertex3f(115,210,-150);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,165,-150);
        glVertex3f(115,210,-150);
        glVertex3f(120,210,-180);
        glVertex3f(120,165,-180);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(120,210,-180);
        glVertex3f(120,210,-200);
        glVertex3f(120,165,-200);
        glVertex3f(120,165,-180);
    glEnd();

     //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(120,165,-220);
        glVertex3f(120,165,-200);
        glVertex3f(120,210,-200);
        glVertex3f(120,210,-220);
    glEnd();

    //A8
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(115,165,-240);
        glVertex3f(120,165,-220);
        glVertex3f(120,210,-220);
        glVertex3f(115,210,-240);
    glEnd();

    //A9
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(115,165,-240);
        glVertex3f(110,165,-260);
        glVertex3f(110,210,-260);
        glVertex3f(115,210,-240);
    glEnd();

    //A10
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,165,-300);
        glVertex3f(60,210,-300);
        glVertex3f(110,210,-260);
        glVertex3f(110,165,-260);
    glEnd();

    //A11
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,210,-300);
        glVertex3f(60,165,-300);
        glVertex3f(10,165,-280);
        glVertex3f(10,210,-280);
    glEnd();

    //A12
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-123,210,-260);
        glVertex3f(-123,165,-260);
        glVertex3f(-150,165,-230);
        glVertex3f(-150,210,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-150,165,-230);
        glVertex3f(-150,210,-230);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,165,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,210,-190);
        glVertex3f(-160,165,-190);
        glVertex3f(-140,165,-145);
        glVertex3f(-140,210,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,165,-70);
        glVertex3f(-115,210,-70);
        glVertex3f(-80,210,0);
        glVertex3f(-80,165,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(10,210,0);
        glVertex3f(10,165,0);
        glVertex3f(-10,165,10);
        glVertex3f(-10,210,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,255,-95);
        glVertex3f(45,215,-95);
        glVertex3f(70,215,-110);
        glVertex3f(70,255,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,215,-110);
        glVertex3f(70,255,-110);
        glVertex3f(95,255,-130);
        glVertex3f(95,215,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,255,-130);
        glVertex3f(95,215,-130);
        glVertex3f(95,215,-210);
        glVertex3f(95,255,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(95,215,-210);
        glVertex3f(95,255,-210);
        glVertex3f(60,255,-270);
        glVertex3f(60,215,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,255,-270);
        glVertex3f(60,215,-270);
        glVertex3f(10,215,-280);
        glVertex3f(10,255,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-123,255,-260);
        glVertex3f(-123,215,-260);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,255,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-150,215,-230);
        glVertex3f(-150,255,-230);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,215,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,255,-190);
        glVertex3f(-160,215,-190);
        glVertex3f(-140,215,-145);
        glVertex3f(-140,255,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,215,-70);
        glVertex3f(-115,255,-70);
        glVertex3f(-80,255,0);
        glVertex3f(-80,215,0);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(10,255,0);
        glVertex3f(10,215,0);
        glVertex3f(-10,215,10);
        glVertex3f(-10,255,10);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,290,-95);
        glVertex3f(45,260,-95);
        glVertex3f(70,260,-110);
        glVertex3f(70,290,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,260,-110);
        glVertex3f(70,290,-110);
        glVertex3f(95,290,-130);
        glVertex3f(95,260,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,290,-130);
        glVertex3f(95,260,-130);
        glVertex3f(95,260,-210);
        glVertex3f(95,290,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(95,260,-210);
        glVertex3f(95,290,-210);
        glVertex3f(60,290,-270);
        glVertex3f(60,260,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,290,-270);
        glVertex3f(60,260,-270);
        glVertex3f(10,260,-280);
        glVertex3f(10,290,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(-123,290,-260);
        glVertex3f(-123,260,-260);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,290,-230);
    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-150,260,-230);
        glVertex3f(-150,290,-230);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,260,-190);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-160,290,-190);
        glVertex3f(-160,260,-190);
        glVertex3f(-140,260,-145);
        glVertex3f(-140,290,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,260,-70);
        glVertex3f(-115,290,-70);
        glVertex3f(-80,290,-30);
        glVertex3f(-80,260,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(10,290,-30);
        glVertex3f(10,260,-30);
        glVertex3f(-10,260,-20);
        glVertex3f(-10,290,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(131,167,196);
        glVertex3f(45,335,-95);
        glVertex3f(45,295,-95);
        glVertex3f(70,295,-110);
        glVertex3f(70,335,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,295,-110);
        glVertex3f(70,335,-110);
        glVertex3f(95,335,-130);
        glVertex3f(95,295,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(95,335,-130);
        glVertex3f(95,295,-130);
        glVertex3f(95,295,-210);
        glVertex3f(95,335,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(95,295,-210);
        glVertex3f(95,335,-210);
        glVertex3f(60,335,-270);
        glVertex3f(60,295,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(60,335,-270);
        glVertex3f(60,295,-270);
        glVertex3f(10,295,-280);
        glVertex3f(10,335,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,295,-280);
        glVertex3f(-60,335,-280);
        glVertex3f(-85,335,-245);
        glVertex3f(-85,295,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,335,-245);
        glVertex3f(-85,295,-245);
        glVertex3f(-110,295,-240);
        glVertex3f(-110,335,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,295,-240);
        glVertex3f(-110,335,-240);
        glVertex3f(-135,335,-210);
        glVertex3f(-135,295,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-135,335,-210);
        glVertex3f(-135,295,-210);
        glVertex3f(-135,295,-178);
        glVertex3f(-135,335,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-135,335,-178);
        glVertex3f(-135,295,-178);
        glVertex3f(-140,295,-145);
        glVertex3f(-140,335,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
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
    glColor3ub(66,189,255);
        glVertex3f(-115,295,-70);
        glVertex3f(-115,335,-70);
        glVertex3f(-80,335,-30);
        glVertex3f(-80,295,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
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
    glColor3ub(131,167,196);
        glVertex3f(10,335,-30);
        glVertex3f(10,295,-30);
        glVertex3f(-10,295,-20);
        glVertex3f(-10,335,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,295,-70);
        glVertex3f(45,335,-70);
        glVertex3f(10,335,-30);
        glVertex3f(10,295,-30);
    glEnd();
}

void lantai10(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,380,-95);
        glVertex3f(45,340,-95);
        glVertex3f(45,340,-70);
        glVertex3f(45,380,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,380,-95);
        glVertex3f(45,340,-95);
        glVertex3f(70,340,-110);
        glVertex3f(70,380,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,340,-110);
        glVertex3f(70,380,-110);
        glVertex3f(75,380,-130);
        glVertex3f(75,340,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(75,380,-130);
        glVertex3f(75,340,-130);
        glVertex3f(75,340,-190);
        glVertex3f(75,380,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(75,340,-190); //TENGAH
        glVertex3f(75,380,-190);
        glVertex3f(40,380,-250);
        glVertex3f(40,340,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(40,380,-250);
        glVertex3f(40,340,-250);
        glVertex3f(0,340,-270);
        glVertex3f(0,380,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,340,-270);
        glVertex3f(0,380,-270);
        glVertex3f(-20,380,-265);
        glVertex3f(-20,340,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,380,-265);
        glVertex3f(-20,340,-265);
        glVertex3f(-60,340,-280);
        glVertex3f(-60,380,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,340,-280);
        glVertex3f(-60,380,-280);
        glVertex3f(-85,380,-245);
        glVertex3f(-85,340,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,380,-245);
        glVertex3f(-85,340,-245);
        glVertex3f(-110,340,-240);
        glVertex3f(-110,380,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,340,-240);
        glVertex3f(-110,380,-240);
        glVertex3f(-135,380,-210);
        glVertex3f(-135,340,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-135,380,-210);
        glVertex3f(-135,340,-210);
        glVertex3f(-135,340,-178);
        glVertex3f(-135,380,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-135,380,-178);
        glVertex3f(-135,340,-178);
        glVertex3f(-140,340,-145);
        glVertex3f(-140,380,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-140,340,-145);
        glVertex3f(-140,380,-145);
        glVertex3f(-115,380,-105);
        glVertex3f(-115,340,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,380,-105);
        glVertex3f(-115,340,-105);
        glVertex3f(-115,340,-70);
        glVertex3f(-115,380,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,340,-70);
        glVertex3f(-115,380,-70);
        glVertex3f(-80,380,-30);
        glVertex3f(-80,340,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,380,-30);
        glVertex3f(-80,340,-30);
        glVertex3f(-55,340,-20);
        glVertex3f(-55,380,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,340,-20);
        glVertex3f(-55,380,-20);
        glVertex3f(-10,380,-20);
        glVertex3f(-10,340,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(10,380,-30);
        glVertex3f(10,340,-30);
        glVertex3f(-10,340,-20);
        glVertex3f(-10,380,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,340,-70);
        glVertex3f(45,380,-70);
        glVertex3f(10,380,-30);
        glVertex3f(10,340,-30);
    glEnd();
}

void lantai11(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,420,-95);
        glVertex3f(45,385,-95);
        glVertex3f(45,385,-70);
        glVertex3f(45,420,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,420,-95);
        glVertex3f(45,385,-95);
        glVertex3f(70,385,-110);
        glVertex3f(70,420,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,385,-110);
        glVertex3f(70,420,-110);
        glVertex3f(75,420,-130);
        glVertex3f(75,385,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(75,420,-130);
        glVertex3f(75,385,-130);
        glVertex3f(75,385,-190);
        glVertex3f(75,420,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(75,385,-190); //TENGAH
        glVertex3f(75,420,-190);
        glVertex3f(40,420,-250);
        glVertex3f(40,385,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(40,420,-250);
        glVertex3f(40,385,-250);
        glVertex3f(0,385,-270);
        glVertex3f(0,420,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,385,-270);
        glVertex3f(0,420,-270);
        glVertex3f(-20,420,-265);
        glVertex3f(-20,385,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,420,-265);
        glVertex3f(-20,385,-265);
        glVertex3f(-60,385,-280);
        glVertex3f(-60,420,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,385,-280);
        glVertex3f(-60,420,-280);
        glVertex3f(-85,420,-245);
        glVertex3f(-85,385,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,420,-245);
        glVertex3f(-85,385,-245);
        glVertex3f(-110,385,-240);
        glVertex3f(-110,420,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,385,-240);
        glVertex3f(-110,420,-240);
        glVertex3f(-135,420,-210);
        glVertex3f(-135,385,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-135,420,-210);
        glVertex3f(-135,385,-210);
        glVertex3f(-135,385,-178);
        glVertex3f(-135,420,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-135,420,-178);
        glVertex3f(-135,385,-178);
        glVertex3f(-140,385,-145);
        glVertex3f(-140,420,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-140,385,-145);
        glVertex3f(-140,420,-145);
        glVertex3f(-115,420,-105);
        glVertex3f(-115,385,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,420,-105);
        glVertex3f(-115,385,-105);
        glVertex3f(-115,385,-70);
        glVertex3f(-115,420,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,385,-70);
        glVertex3f(-115,420,-70);
        glVertex3f(-80,420,-70);
        glVertex3f(-80,385,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,420,-70);
        glVertex3f(-80,385,-70);
        glVertex3f(-55,385,-50);
        glVertex3f(-55,420,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,385,-50);
        glVertex3f(-55,420,-50);
        glVertex3f(-10,420,-50);
        glVertex3f(-10,385,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-10,420,-50);
        glVertex3f(-10,385,-50);
        glVertex3f(10,385,-65);
        glVertex3f(10,420,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,385,-70);
        glVertex3f(45,420,-70);
        glVertex3f(10,420,-65);
        glVertex3f(10,385,-65);
    glEnd();
}

void lantai12(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,450,-95);
        glVertex3f(45,425,-95);
        glVertex3f(45,425,-70);
        glVertex3f(45,450,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,450,-95);
        glVertex3f(45,425,-95);
        glVertex3f(70,425,-110);
        glVertex3f(70,450,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,425,-110);
        glVertex3f(70,450,-110);
        glVertex3f(75,450,-130);
        glVertex3f(75,425,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(75,450,-130);
        glVertex3f(75,425,-130);
        glVertex3f(75,425,-190);
        glVertex3f(75,450,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(75,425,-190); //TENGAH
        glVertex3f(75,450,-190);
        glVertex3f(40,450,-250);
        glVertex3f(40,425,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(40,450,-250);
        glVertex3f(40,425,-250);
        glVertex3f(0,425,-270);
        glVertex3f(0,450,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,425,-270);
        glVertex3f(0,450,-270);
        glVertex3f(-20,450,-265);
        glVertex3f(-20,425,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,450,-265);
        glVertex3f(-20,425,-265);
        glVertex3f(-60,425,-280);
        glVertex3f(-60,450,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,425,-280);
        glVertex3f(-60,450,-280);
        glVertex3f(-70,450,-225);
        glVertex3f(-70,425,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,450,-225);
        glVertex3f(-70,425,-225);
        glVertex3f(-95,425,-220);
        glVertex3f(-95,450,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-95,425,-220);
        glVertex3f(-95,450,-220); //center
        glVertex3f(-117,450,-200);
        glVertex3f(-117,425,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-117,450,-200);
        glVertex3f(-117,425,-200);
        glVertex3f(-110,425,-170);
        glVertex3f(-110,450,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,425,-170);
        glVertex3f(-110,450,-170);
        glVertex3f(-140,450,-145);
        glVertex3f(-140,425,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-140,450,-145);
        glVertex3f(-140,425,-145);
        glVertex3f(-115,425,-105);
        glVertex3f(-115,450,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,450,-105);
        glVertex3f(-115,425,-105);
        glVertex3f(-115,425,-70);
        glVertex3f(-115,450,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,425,-70);
        glVertex3f(-115,450,-70);
        glVertex3f(-80,450,-70);
        glVertex3f(-80,425,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,450,-70);
        glVertex3f(-80,425,-70);
        glVertex3f(-55,425,-50);
        glVertex3f(-55,450,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,425,-50);
        glVertex3f(-55,450,-50);
        glVertex3f(-10,450,-50);
        glVertex3f(-10,425,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-10,450,-50);
        glVertex3f(-10,425,-50);
        glVertex3f(10,425,-65);
        glVertex3f(10,450,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,425,-70);
        glVertex3f(45,450,-70);
        glVertex3f(10,450,-65);
        glVertex3f(10,425,-65);
    glEnd();
}

void lantai13(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,480,-95);
        glVertex3f(45,455,-95);
        glVertex3f(45,455,-70);
        glVertex3f(45,480,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,480,-95);
        glVertex3f(45,455,-95);
        glVertex3f(70,455,-110);
        glVertex3f(70,480,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,455,-110);
        glVertex3f(70,480,-110);
        glVertex3f(55,480,-130);
        glVertex3f(55,455,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(55,480,-130);
        glVertex3f(55,455,-130);
        glVertex3f(55,455,-185);
        glVertex3f(55,480,-185);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(55,455,-185);
        glVertex3f(55,480,-185);
        glVertex3f(25,480,-240);
        glVertex3f(25,455,-240);
    glEnd();

    //A6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(25,480,-240);
        glVertex3f(25,455,-240);
        glVertex3f(0,455,-250);
        glVertex3f(0,480,-250);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,455,-250);
        glVertex3f(0,480,-250);
        glVertex3f(-20,480,-265);
        glVertex3f(-20,455,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,480,-265);
        glVertex3f(-20,455,-265);
        glVertex3f(-60,455,-280);
        glVertex3f(-60,480,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,455,-280);
        glVertex3f(-60,480,-280);
        glVertex3f(-70,480,-225);
        glVertex3f(-70,455,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,480,-225);
        glVertex3f(-70,455,-225);
        glVertex3f(-95,455,-220);
        glVertex3f(-95,480,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-95,455,-220);
        glVertex3f(-95,480,-220);
        glVertex3f(-117,480,-200);
        glVertex3f(-117,455,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-117,480,-200);
        glVertex3f(-117,455,-200); //center
        glVertex3f(-110,455,-170);
        glVertex3f(-110,480,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,455,-170);
        glVertex3f(-110,480,-170);
        glVertex3f(-140,480,-145);
        glVertex3f(-140,455,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-140,480,-145);
        glVertex3f(-140,455,-145);
        glVertex3f(-115,455,-105);
        glVertex3f(-115,480,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,480,-105);
        glVertex3f(-115,455,-105);
        glVertex3f(-115,455,-70);
        glVertex3f(-115,480,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,455,-70);
        glVertex3f(-115,480,-70);
        glVertex3f(-80,480,-70);
        glVertex3f(-80,455,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,480,-70);
        glVertex3f(-80,455,-70);
        glVertex3f(-55,455,-50);
        glVertex3f(-55,480,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,455,-50);
        glVertex3f(-55,480,-50);
        glVertex3f(-10,480,-50);
        glVertex3f(-10,455,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-10,480,-50);
        glVertex3f(-10,455,-50);
        glVertex3f(10,455,-65);
        glVertex3f(10,480,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,455,-70);
        glVertex3f(45,480,-70);
        glVertex3f(10,480,-65);
        glVertex3f(10,455,-65);
    glEnd();
}

void lantai14(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(45,500,-95);
        glVertex3f(45,485,-95);
        glVertex3f(45,485,-70);
        glVertex3f(45,500,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,500,-95);
        glVertex3f(45,485,-95);
        glVertex3f(70,485,-110);
        glVertex3f(70,500,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(70,485,-110);
        glVertex3f(70,500,-110);
        glVertex3f(55,500,-130);
        glVertex3f(55,485,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(55,500,-130);
        glVertex3f(55,485,-130);
        glVertex3f(55,485,-185);
        glVertex3f(55,500,-185);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(55,485,-185);
        glVertex3f(55,500,-185);
        glVertex3f(25,500,-240);
        glVertex3f(25,485,-240);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(25,500,-240);
        glVertex3f(25,485,-240);
        glVertex3f(0,485,-250);
        glVertex3f(0,500,-250);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,485,-250);
        glVertex3f(0,500,-250);
        glVertex3f(-20,500,-265);
        glVertex3f(-20,485,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-20,500,-265);
        glVertex3f(-20,485,-265);
        glVertex3f(-60,485,-280);
        glVertex3f(-60,500,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,485,-280);
        glVertex3f(-60,500,-280);
        glVertex3f(-70,500,-225);
        glVertex3f(-70,485,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,500,-225);
        glVertex3f(-70,485,-225);
        glVertex3f(-95,485,-220);
        glVertex3f(-95,500,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-95,485,-220);
        glVertex3f(-95,500,-220);
        glVertex3f(-117,500,-200);
        glVertex3f(-117,485,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-117,500,-200);
        glVertex3f(-117,485,-200); //center
        glVertex3f(-110,485,-170);
        glVertex3f(-110,500,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-110,485,-170);
        glVertex3f(-110,500,-170);
        glVertex3f(-140,500,-145);
        glVertex3f(-140,485,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-140,500,-145);
        glVertex3f(-140,485,-145);
        glVertex3f(-115,485,-105);
        glVertex3f(-115,500,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-115,500,-105);
        glVertex3f(-115,485,-105);
        glVertex3f(-115,485,-70);
        glVertex3f(-115,500,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,485,-70);
        glVertex3f(-115,500,-70);
        glVertex3f(-80,500,-70);
        glVertex3f(-80,485,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,500,-70);
        glVertex3f(-80,485,-70);
        glVertex3f(-80,485,-90);
        glVertex3f(-80,500,-90);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,500,-90);
        glVertex3f(-80,485,-90);
        glVertex3f(-55,485,-70);
        glVertex3f(-55,500,-70);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-55,485,-70);
        glVertex3f(-55,500,-70);
        glVertex3f(-10,500,-70);
        glVertex3f(-10,485,-70);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-10,500,-70);
        glVertex3f(-10,485,-70);
        glVertex3f(10,485,-90);
        glVertex3f(10,500,-90);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,485,-90);
        glVertex3f(10,500,-90);
        glVertex3f(10,500,-65);
        glVertex3f(10,485,-65);
    glEnd();

    //D4
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,485,-70);
        glVertex3f(45,500,-70);
        glVertex3f(10,500,-65);
        glVertex3f(10,485,-65);
    glEnd();
}

void lantai15(){

    //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-80,520,-90);
        glVertex3f(-80,505,-90);
        glVertex3f(10,505,-90);
        glVertex3f(10,520,-90);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(10,505,-90);
        glVertex3f(10,520,-90);
        glVertex3f(10,520,-65);
        glVertex3f(10,505,-65);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,505,-70);
        glVertex3f(45,520,-70);
        glVertex3f(10,520,-65);
        glVertex3f(10,505,-65);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(45,520,-200);
        glVertex3f(45,505,-200);
        glVertex3f(45,505,-70);
        glVertex3f(45,520,-70);
    glEnd();


    //B1
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(45,520,-200);
        glVertex3f(45,505,-200);
        glVertex3f(-117,505,-200);
        glVertex3f(-117,520,-200);
    glEnd();

    //B2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-117,520,-200);
        glVertex3f(-117,505,-200);
        glVertex3f(-115,505,-70);
        glVertex3f(-115,520,-70);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-115,505,-70);
        glVertex3f(-115,520,-70);
        glVertex3f(-80,520,-70);
        glVertex3f(-80,505,-70);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,520,-70);
        glVertex3f(-80,505,-70);
        glVertex3f(-80,505,-90);
        glVertex3f(-80,520,-90);
    glEnd();
}

void lantai16(){
    //A1
    glBegin(GL_QUADS);
   glColor3ub(66,189,255);
        glVertex3f(-80,525,-90);
        glVertex3f(-80,550,-90);
        glVertex3f(10,550,-90);
        glVertex3f(10,525,-90);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(10,525,-200);
        glVertex3f(10,550,-200);
        glVertex3f(10,550,-90);
        glVertex3f(10,525,-90);
    glEnd();


    //A3
    glBegin(GL_QUADS);
   glColor3ub(66,189,255);
        glVertex3f(10,525,-200);
        glVertex3f(10,550,-200);
        glVertex3f(-80,550,-200);
        glVertex3f(-80,525,-200);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-80,550,-200);
        glVertex3f(-80,525,-200);
        glVertex3f(-80,525,-90);
        glVertex3f(-80,550,-90);
    glEnd();
}

void lantai17(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-70,575,-100);
        glVertex3f(-70,550,-100);
        glVertex3f(0,550,-100);
        glVertex3f(0,575,-100);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(0,575,-190);
        glVertex3f(0,550,-190);
        glVertex3f(0,550,-100);
        glVertex3f(0,575,-100);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(0,575,-190);
        glVertex3f(0,550,-190);
        glVertex3f(-70,550,-190);
        glVertex3f(-70,575,-190);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-70,575,-190);
        glVertex3f(-70,550,-190);
        glVertex3f(-70,550,-100);
        glVertex3f(-70,575,-100);
    glEnd();
}

void lantai18(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,575,-110);
        glVertex3f(-60,600,-110);
        glVertex3f(-10,600,-110);
        glVertex3f(-10,575,-110);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-10,600,-110);
        glVertex3f(-10,575,-110);
        glVertex3f(-10,575,-180);
        glVertex3f(-10,600,-180);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-60,575,-180);
        glVertex3f(-60,600,-180);
        glVertex3f(-10,600,-180);
        glVertex3f(-10,575,-180);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-60,600,-110);
        glVertex3f(-60,575,-110);
        glVertex3f(-60,575,-180);
        glVertex3f(-60,600,-180);
    glEnd();
}

void lantai19(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-50,625,-120);
        glVertex3f(-50,600,-120);
        glVertex3f(-20,600,-120);
        glVertex3f(-20,625,-120);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-20,600,-120);
        glVertex3f(-20,625,-120);
        glVertex3f(-20,625,-170);
        glVertex3f(-20,600,-170);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(66,189,255);
        glVertex3f(-50,625,-170);
        glVertex3f(-50,600,-170);
        glVertex3f(-20,600,-170);
        glVertex3f(-20,625,-170);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(131,167,196);
        glVertex3f(-50,600,-120);
        glVertex3f(-50,625,-120);
        glVertex3f(-50,625,-170);
        glVertex3f(-50,600,-170);
    glEnd();
}

void lantai20(){
 //A1
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-40,720,-150);
        glVertex3f(-40,628,-150);
        glVertex3f(-30,628,-150);
        glVertex3f(-30,720,-150);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-30,720,-150);
        glVertex3f(-30,628,-150);
        glVertex3f(-30,628,-145);
        glVertex3f(-30,720,-145);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(0,0,255);
        glVertex3f(-40,720,-145);
        glVertex3f(-40,628,-145);
        glVertex3f(-30,628,-145);
        glVertex3f(-30,720,-145);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
        glVertex3f(-40,720,-150);
        glVertex3f(-40,628,-150);
        glVertex3f(-40,628,-145);
        glVertex3f(-40,720,-145);
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

void line9(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,335,-95);
        glVertex3f(45,340,-95);
        glVertex3f(45,340,-70);
        glVertex3f(45,335,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,335,-95);
        glVertex3f(45,340,-95);
        glVertex3f(70,340,-110);
        glVertex3f(70,335,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,340,-110);
        glVertex3f(70,335,-110);
        glVertex3f(95,335,-130);
        glVertex3f(95,340,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,335,-130);
        glVertex3f(95,340,-130);
        glVertex3f(95,340,-210);
        glVertex3f(95,335,-210);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(95,340,-210);
        glVertex3f(95,335,-210);
        glVertex3f(60,335,-270);
        glVertex3f(60,340,-270);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(60,335,-270);
        glVertex3f(60,340,-270);
        glVertex3f(10,340,-280);
        glVertex3f(10,335,-280);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,340,-280);
        glVertex3f(10,335,-280);
        glVertex3f(-20,335,-265);
        glVertex3f(-20,340,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,335,-265);
        glVertex3f(-20,340,-265);
        glVertex3f(-60,340,-280);
        glVertex3f(-60,335,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,340,-280);
        glVertex3f(-60,335,-280);
        glVertex3f(-85,335,-245);
        glVertex3f(-85,340,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,335,-245);
        glVertex3f(-85,340,-245);
        glVertex3f(-110,340,-240);
        glVertex3f(-110,335,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,340,-240);
        glVertex3f(-110,335,-240);
        glVertex3f(-135,335,-210);
        glVertex3f(-135,340,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,335,-210);
        glVertex3f(-135,340,-210);
        glVertex3f(-135,340,-178);
        glVertex3f(-135,335,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,335,-178);
        glVertex3f(-135,340,-178);
        glVertex3f(-140,340,-145);
        glVertex3f(-140,335,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,340,-145);
        glVertex3f(-140,335,-145);
        glVertex3f(-115,335,-105);
        glVertex3f(-115,340,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,335,-105);
        glVertex3f(-115,340,-105);
        glVertex3f(-115,340,-70);
        glVertex3f(-115,335,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,340,-70);
        glVertex3f(-115,335,-70);
        glVertex3f(-80,335,-30);
        glVertex3f(-80,340,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,335,-30);
        glVertex3f(-80,340,-30);
        glVertex3f(-55,340,-20);
        glVertex3f(-55,335,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,340,-20);
        glVertex3f(-55,335,-20);
        glVertex3f(-10,335,-20);
        glVertex3f(-10,340,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,335,-30);
        glVertex3f(10,340,-30);
        glVertex3f(-10,340,-20);
        glVertex3f(-10,335,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,340,-70);
        glVertex3f(45,335,-70);
        glVertex3f(10,335,-30);
        glVertex3f(10,340,-30);
    glEnd();
}

void line10(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,380,-95);
        glVertex3f(45,385,-95);
        glVertex3f(45,385,-70);
        glVertex3f(45,380,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,380,-95);
        glVertex3f(45,385,-95);
        glVertex3f(70,385,-110);
        glVertex3f(70,380,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,385,-110);
        glVertex3f(70,380,-110);
        glVertex3f(75,380,-130);
        glVertex3f(75,385,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,380,-130);
        glVertex3f(75,385,-130);
        glVertex3f(75,385,-190);
        glVertex3f(75,380,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,385,-190); //TENGAH
        glVertex3f(75,380,-190);
        glVertex3f(40,380,-250);
        glVertex3f(40,385,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(40,380,-250);
        glVertex3f(40,385,-250);
        glVertex3f(0,385,-270);
        glVertex3f(0,380,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,385,-270);
        glVertex3f(0,380,-270);
        glVertex3f(-20,380,-265);
        glVertex3f(-20,385,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,380,-265);
        glVertex3f(-20,385,-265);
        glVertex3f(-60,385,-280);
        glVertex3f(-60,380,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,385,-280);
        glVertex3f(-60,380,-280);
        glVertex3f(-85,380,-245);
        glVertex3f(-85,385,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,380,-245);
        glVertex3f(-85,385,-245);
        glVertex3f(-110,385,-240);
        glVertex3f(-110,380,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,385,-240);
        glVertex3f(-110,380,-240);
        glVertex3f(-135,380,-210);
        glVertex3f(-135,385,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,380,-210);
        glVertex3f(-135,385,-210);
        glVertex3f(-135,385,-178);
        glVertex3f(-135,380,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,380,-178);
        glVertex3f(-135,385,-178);
        glVertex3f(-140,385,-145);
        glVertex3f(-140,380,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,385,-145);
        glVertex3f(-140,380,-145);
        glVertex3f(-115,380,-105);
        glVertex3f(-115,385,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,380,-105);
        glVertex3f(-115,385,-105);
        glVertex3f(-115,385,-70);
        glVertex3f(-115,380,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,385,-70);
        glVertex3f(-115,380,-70);
        glVertex3f(-80,380,-30);
        glVertex3f(-80,385,-30);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,380,-30);
        glVertex3f(-80,385,-30);
        glVertex3f(-55,385,-20);
        glVertex3f(-55,380,-20);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,385,-20);
        glVertex3f(-55,380,-20);
        glVertex3f(-10,380,-20);
        glVertex3f(-10,385,-20);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,380,-30);
        glVertex3f(10,385,-30);
        glVertex3f(-10,385,-20);
        glVertex3f(-10,380,-20);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,385,-70);
        glVertex3f(45,380,-70);
        glVertex3f(10,380,-30);
        glVertex3f(10,385,-30);
    glEnd();
}

void line11(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,420,-95);
        glVertex3f(45,425,-95);
        glVertex3f(45,425,-70);
        glVertex3f(45,420,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,420,-95);
        glVertex3f(45,425,-95);
        glVertex3f(70,425,-110);
        glVertex3f(70,420,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,425,-110);
        glVertex3f(70,420,-110);
        glVertex3f(75,420,-130);
        glVertex3f(75,425,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,420,-130);
        glVertex3f(75,425,-130);
        glVertex3f(75,425,-190);
        glVertex3f(75,420,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,425,-190); //TENGAH
        glVertex3f(75,420,-190);
        glVertex3f(40,420,-250);
        glVertex3f(40,425,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(40,420,-250);
        glVertex3f(40,425,-250);
        glVertex3f(0,425,-270);
        glVertex3f(0,420,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,425,-270);
        glVertex3f(0,420,-270);
        glVertex3f(-20,420,-265);
        glVertex3f(-20,425,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,420,-265);
        glVertex3f(-20,425,-265);
        glVertex3f(-60,425,-280);
        glVertex3f(-60,420,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,425,-280);
        glVertex3f(-60,420,-280);
        glVertex3f(-85,420,-245);
        glVertex3f(-85,425,-245);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-85,420,-245);
        glVertex3f(-85,425,-245);
        glVertex3f(-110,425,-240);
        glVertex3f(-110,420,-240);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,425,-240);
        glVertex3f(-110,420,-240);
        glVertex3f(-135,420,-210);
        glVertex3f(-135,425,-210);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,420,-210);
        glVertex3f(-135,425,-210);
        glVertex3f(-135,425,-178);
        glVertex3f(-135,420,-178);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-135,420,-178);
        glVertex3f(-135,425,-178);
        glVertex3f(-140,425,-145);
        glVertex3f(-140,420,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,425,-145);
        glVertex3f(-140,420,-145);
        glVertex3f(-115,420,-105);
        glVertex3f(-115,425,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,420,-105);
        glVertex3f(-115,425,-105);
        glVertex3f(-115,425,-70);
        glVertex3f(-115,420,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,425,-70);
        glVertex3f(-115,420,-70);
        glVertex3f(-80,420,-70);
        glVertex3f(-80,425,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,420,-70);
        glVertex3f(-80,425,-70);
        glVertex3f(-55,425,-50);
        glVertex3f(-55,420,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,425,-50);
        glVertex3f(-55,420,-50);
        glVertex3f(-10,420,-50);
        glVertex3f(-10,425,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-10,420,-50);
        glVertex3f(-10,425,-50);
        glVertex3f(10,425,-65);
        glVertex3f(10,420,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,425,-70);
        glVertex3f(45,420,-70);
        glVertex3f(10,420,-65);
        glVertex3f(10,425,-65);
    glEnd();
}

void line12(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,450,-95);
        glVertex3f(45,455,-95);
        glVertex3f(45,455,-70);
        glVertex3f(45,450,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,450,-95);
        glVertex3f(45,455,-95);
        glVertex3f(70,455,-110);
        glVertex3f(70,450,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,455,-110);
        glVertex3f(70,450,-110);
        glVertex3f(75,450,-130);
        glVertex3f(75,455,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,450,-130);
        glVertex3f(75,455,-130);
        glVertex3f(75,455,-190);
        glVertex3f(75,450,-190);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(75,455,-190); //TENGAH
        glVertex3f(75,450,-190);
        glVertex3f(40,450,-250);
        glVertex3f(40,455,-250);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(40,450,-250);
        glVertex3f(40,455,-250);
        glVertex3f(0,455,-270);
        glVertex3f(0,450,-270);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,455,-270);
        glVertex3f(0,450,-270);
        glVertex3f(-20,450,-265);
        glVertex3f(-20,455,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,450,-265);
        glVertex3f(-20,455,-265);
        glVertex3f(-60,455,-280);
        glVertex3f(-60,450,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,455,-280);
        glVertex3f(-60,450,-280);
        glVertex3f(-70,450,-225);
        glVertex3f(-70,455,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,450,-225);
        glVertex3f(-70,455,-225);
        glVertex3f(-95,455,-220);
        glVertex3f(-95,450,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,455,-220);
        glVertex3f(-95,450,-220); //center
        glVertex3f(-117,450,-200);
        glVertex3f(-117,455,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-117,450,-200);
        glVertex3f(-117,455,-200);
        glVertex3f(-110,455,-170);
        glVertex3f(-110,450,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,455,-170);
        glVertex3f(-110,450,-170);
        glVertex3f(-140,450,-145);
        glVertex3f(-140,455,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,450,-145);
        glVertex3f(-140,455,-145);
        glVertex3f(-115,455,-105);
        glVertex3f(-115,450,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,450,-105);
        glVertex3f(-115,455,-105);
        glVertex3f(-115,455,-70);
        glVertex3f(-115,450,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,455,-70);
        glVertex3f(-115,450,-70);
        glVertex3f(-80,450,-70);
        glVertex3f(-80,455,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,450,-70);
        glVertex3f(-80,455,-70);
        glVertex3f(-55,455,-50);
        glVertex3f(-55,450,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,455,-50);
        glVertex3f(-55,450,-50);
        glVertex3f(-10,450,-50);
        glVertex3f(-10,455,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-10,450,-50);
        glVertex3f(-10,455,-50);
        glVertex3f(10,455,-65);
        glVertex3f(10,450,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,455,-70);
        glVertex3f(45,450,-70);
        glVertex3f(10,450,-65);
        glVertex3f(10,455,-65);
    glEnd();
}

void line13(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,480,-95);
        glVertex3f(45,485,-95);
        glVertex3f(45,485,-70);
        glVertex3f(45,480,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,480,-95);
        glVertex3f(45,485,-95);
        glVertex3f(70,485,-110);
        glVertex3f(70,480,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,485,-110);
        glVertex3f(70,480,-110);
        glVertex3f(55,480,-130);
        glVertex3f(55,485,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(55,480,-130);
        glVertex3f(55,485,-130);
        glVertex3f(55,485,-185);
        glVertex3f(55,480,-185);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(55,485,-185);
        glVertex3f(55,480,-185);
        glVertex3f(25,480,-240);
        glVertex3f(25,485,-240);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,480,-240);
        glVertex3f(25,485,-240);
        glVertex3f(0,485,-250);
        glVertex3f(0,480,-250);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,485,-250);
        glVertex3f(0,480,-250);
        glVertex3f(-20,480,-265);
        glVertex3f(-20,485,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,480,-265);
        glVertex3f(-20,485,-265);
        glVertex3f(-60,485,-280);
        glVertex3f(-60,480,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,485,-280);
        glVertex3f(-60,480,-280);
        glVertex3f(-70,480,-225);
        glVertex3f(-70,485,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,480,-225);
        glVertex3f(-70,485,-225);
        glVertex3f(-95,485,-220);
        glVertex3f(-95,480,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,485,-220);
        glVertex3f(-95,480,-220);
        glVertex3f(-117,480,-200);
        glVertex3f(-117,485,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-117,480,-200);
        glVertex3f(-117,485,-200); //center
        glVertex3f(-110,485,-170);
        glVertex3f(-110,480,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,485,-170);
        glVertex3f(-110,480,-170);
        glVertex3f(-140,480,-145);
        glVertex3f(-140,485,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,480,-145);
        glVertex3f(-140,485,-145);
        glVertex3f(-115,485,-105);
        glVertex3f(-115,480,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,480,-105);
        glVertex3f(-115,485,-105);
        glVertex3f(-115,485,-70);
        glVertex3f(-115,480,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,485,-70);
        glVertex3f(-115,480,-70);
        glVertex3f(-80,480,-70);
        glVertex3f(-80,485,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,480,-70);
        glVertex3f(-80,485,-70);
        glVertex3f(-55,485,-50);
        glVertex3f(-55,480,-50);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,485,-50);
        glVertex3f(-55,480,-50);
        glVertex3f(-10,480,-50);
        glVertex3f(-10,485,-50);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-10,480,-50);
        glVertex3f(-10,485,-50);
        glVertex3f(10,485,-65);
        glVertex3f(10,480,-65);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,485,-70);
        glVertex3f(45,480,-70);
        glVertex3f(10,480,-65);
        glVertex3f(10,485,-65);
    glEnd();
}

void line14(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,500,-95);
        glVertex3f(45,505,-95);
        glVertex3f(45,505,-70);
        glVertex3f(45,500,-70);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,500,-95);
        glVertex3f(45,505,-95);
        glVertex3f(70,505,-110);
        glVertex3f(70,500,-110);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(70,505,-110);
        glVertex3f(70,500,-110);
        glVertex3f(55,500,-130);
        glVertex3f(55,505,-130);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(55,500,-130);
        glVertex3f(55,505,-130);
        glVertex3f(55,505,-185);
        glVertex3f(55,500,-185);
    glEnd();

    //A5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(55,505,-185);
        glVertex3f(55,500,-185);
        glVertex3f(25,500,-240);
        glVertex3f(25,505,-240);
    glEnd();

    //A6 beta
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(25,500,-240);
        glVertex3f(25,505,-240);
        glVertex3f(0,505,-250);
        glVertex3f(0,500,-250);
    glEnd();

        //A7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,505,-250);
        glVertex3f(0,500,-250);
        glVertex3f(-20,500,-265);
        glVertex3f(-20,505,-265);
    glEnd();

    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,500,-265);
        glVertex3f(-20,505,-265);
        glVertex3f(-60,505,-280);
        glVertex3f(-60,500,-280);
    glEnd();

    // B2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,505,-280);
        glVertex3f(-60,500,-280);
        glVertex3f(-70,500,-225);
        glVertex3f(-70,505,-225);
    glEnd();

    //B3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,500,-225);
        glVertex3f(-70,505,-225);
        glVertex3f(-95,505,-220);
        glVertex3f(-95,500,-220);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-95,505,-220);
        glVertex3f(-95,500,-220);
        glVertex3f(-117,500,-200);
        glVertex3f(-117,505,-200);

    glEnd();

    //B5
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-117,500,-200);
        glVertex3f(-117,505,-200); //center
        glVertex3f(-110,505,-170);
        glVertex3f(-110,500,-170);
    glEnd();

    //B6
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-110,505,-170);
        glVertex3f(-110,500,-170);
        glVertex3f(-140,500,-145);
        glVertex3f(-140,505,-145);
    glEnd();

    //B7
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-140,500,-145);
        glVertex3f(-140,505,-145);
        glVertex3f(-115,505,-105);
        glVertex3f(-115,500,-105);
    glEnd();

    //C1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,500,-105);
        glVertex3f(-115,505,-105);
        glVertex3f(-115,505,-70);
        glVertex3f(-115,500,-70);
    glEnd();

    //C2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-115,505,-70);
        glVertex3f(-115,500,-70);
        glVertex3f(-80,500,-70);
        glVertex3f(-80,505,-70);
    glEnd();

    //C3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,500,-70);
        glVertex3f(-80,505,-70);
        glVertex3f(-80,505,-90);
        glVertex3f(-80,500,-90);
    glEnd();

    //C4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,500,-90);
        glVertex3f(-80,505,-90);
        glVertex3f(-55,505,-70);
        glVertex3f(-55,500,-70);
    glEnd();

    //D1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-55,505,-70);
        glVertex3f(-55,500,-70);
        glVertex3f(-10,500,-70);
        glVertex3f(-10,505,-70);
    glEnd();

    //D2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-10,500,-70);
        glVertex3f(-10,505,-70);
        glVertex3f(10,505,-90);
        glVertex3f(10,500,-90);
    glEnd();

    //D3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,505,-90);
        glVertex3f(10,500,-90);
        glVertex3f(10,500,-65);
        glVertex3f(10,505,-65);
    glEnd();

    //D4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,505,-70);
        glVertex3f(45,500,-70);
        glVertex3f(10,500,-65);
        glVertex3f(10,505,-65);
    glEnd();
}

void line15(){
//A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,520,-90);
        glVertex3f(-80,525,-90);
        glVertex3f(10,525,-90);
        glVertex3f(10,520,-90);
    glEnd();

    //A2
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(10,525,-90);
        glVertex3f(10,520,-90);
        glVertex3f(10,520,-65);
        glVertex3f(10,525,-65);
    glEnd();

    //A3
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(45,525,-70);
        glVertex3f(45,520,-70);
        glVertex3f(10,520,-65);
        glVertex3f(10,525,-65);
    glEnd();

    //A4
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(45,520,-200);
        glVertex3f(45,525,-200);
        glVertex3f(45,525,-70);
        glVertex3f(45,520,-70);
    glEnd();


    //B1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(45,520,-200);
        glVertex3f(45,525,-200);
        glVertex3f(-117,525,-200);
        glVertex3f(-117,520,-200);
    glEnd();

    //B2
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(-117,520,-200);
        glVertex3f(-117,525,-200);
        glVertex3f(-115,525,-70);
        glVertex3f(-115,520,-70);
    glEnd();

    //B3
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(-115,525,-70);
        glVertex3f(-115,520,-70);
        glVertex3f(-80,520,-70);
        glVertex3f(-80,525,-70);
    glEnd();

    //B4
    glBegin(GL_QUADS);
   glColor3ub(255,255,255);
        glVertex3f(-80,520,-70);
        glVertex3f(-80,525,-70);
        glVertex3f(-80,525,-90);
        glVertex3f(-80,520,-90);
    glEnd();
}

void line16(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,553,-90);
        glVertex3f(-80,550,-90);
        glVertex3f(10,550,-90);
        glVertex3f(10,553,-90);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,553,-200);
        glVertex3f(10,550,-200);
        glVertex3f(10,550,-90);
        glVertex3f(10,553,-90);
    glEnd();


    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(10,553,-200);
        glVertex3f(10,550,-200);
        glVertex3f(-80,550,-200);
        glVertex3f(-80,553,-200);
    glEnd();

    //B4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-80,550,-200);
        glVertex3f(-80,553,-200);
        glVertex3f(-80,553,-90);
        glVertex3f(-80,550,-90);
    glEnd();
}

void line17(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,575,-100);
        glVertex3f(-70,578,-100);
        glVertex3f(0,578,-100);
        glVertex3f(0,575,-100);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,575,-190);
        glVertex3f(0,578,-190);
        glVertex3f(0,578,-100);
        glVertex3f(0,575,-100);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(0,575,-190);
        glVertex3f(0,578,-190);
        glVertex3f(-70,578,-190);
        glVertex3f(-70,575,-190);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-70,575,-190);
        glVertex3f(-70,578,-190);
        glVertex3f(-70,578,-100);
        glVertex3f(-70,575,-100);
    glEnd();
}

void line18(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,603,-110);
        glVertex3f(-60,600,-110);
        glVertex3f(-10,600,-110);
        glVertex3f(-10,603,-110);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-10,600,-110);
        glVertex3f(-10,603,-110);
        glVertex3f(-10,603,-180);
        glVertex3f(-10,600,-180);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,603,-180);
        glVertex3f(-60,600,-180);
        glVertex3f(-10,600,-180);
        glVertex3f(-10,603,-180);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-60,600,-110);
        glVertex3f(-60,603,-110);
        glVertex3f(-60,603,-180);
        glVertex3f(-60,600,-180);
    glEnd();
}

void line19(){
    //A1
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-50,625,-120);
        glVertex3f(-50,628,-120);
        glVertex3f(-20,628,-120);
        glVertex3f(-20,625,-120);
    glEnd();

    //A2
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-20,628,-120);
        glVertex3f(-20,625,-120);
        glVertex3f(-20,625,-170);
        glVertex3f(-20,628,-170);
    glEnd();

    //A3
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-50,625,-170);
        glVertex3f(-50,628,-170);
        glVertex3f(-20,628,-170);
        glVertex3f(-20,625,-170);
    glEnd();

    //A4
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
        glVertex3f(-50,628,-120);
        glVertex3f(-50,625,-120);
        glVertex3f(-50,625,-170);
        glVertex3f(-50,628,-170);
    glEnd();
}
// LINE

// ATAP
void atapBawah1(){

    //tutup lantai bawah
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
        glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
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
    glColor3ub(211,206,213);
        //titik a
        glVertex3f(45,295,-95); //a1
        glVertex3f(70,295,-110); //a2
        glVertex3f(95,295,-130); //a3
        glVertex3f(95,295,-210); //a4
        glVertex3f(60,295,-270); //a5
        glVertex3f(10,295,-280); //a6
        glVertex3f(-20,295,-265); //a7
        //titik b
        glVertex3f(-60,335,-280); //b1
        glVertex3f(-85,335,-245); //b2
        glVertex3f(-110,335,-240); //b3
        glVertex3f(-135,335,-210); //b4
        glVertex3f(-135,335,-178); //b5
        glVertex3f(-140,335,-145); //b6
        glVertex3f(-115,295,-105); //b7
        //titik c
        glVertex3f(-115,295,-70); //c1
        glVertex3f(-80,295,-30); //c2
        glVertex3f(-55,295,-20); //c3
        //titik d
        glVertex3f(-10,295,-20); //d1
        glVertex3f(10,295
                   ,-30); //d2
        glVertex3f(45,295,-70); //d3
    glEnd();
}

void atapAtas9(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        //titik a
        glVertex3f(45,335,-95); //a1
        glVertex3f(70,335,-110); //a2
        glVertex3f(95,335,-130); //a3
        glVertex3f(95,335,-210); //a4
        glVertex3f(60,335,-270); //a5
        glVertex3f(10,335,-280); //a6
        glVertex3f(-20,335,-265); //a7
        //titik b
        glVertex3f(-60,335,-280); //b1
        glVertex3f(-60,325,-280); //b2
        glVertex3f(-85,335,-245); //b3
        glVertex3f(-110,335,-240); //b4
        glVertex3f(-135,335,-210); //b5
        glVertex3f(-135,335,-178); //b5
        glVertex3f(-140,335,-145); //b6
        glVertex3f(-115,335,-105); //b7
        //titik c
        glVertex3f(-115,335,-70); //c1
        glVertex3f(-80,335,-30); //c2
        glVertex3f(-55,335,-20); //c3
        //titik d
        glVertex3f(-10,335,-20); //d1
        glVertex3f(10,335,-30); //d2
        glVertex3f(45,335,-70); //d3
    glEnd();
}

void atapAtas9_2(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        //titik a
        glVertex3f(45,340,-95); //a1
        glVertex3f(70,340,-110); //a2
        glVertex3f(95,340,-130); //a3
        glVertex3f(95,340,-210); //a4
        glVertex3f(60,340,-270); //a5
        glVertex3f(10,340,-280); //a6
        glVertex3f(-20,340,-265); //a7
        //titik b
        glVertex3f(-60,340,-280); //b1
        glVertex3f(-60,325,-280); //b2
        glVertex3f(-85,340,-245); //b3
        glVertex3f(-110,340,-240); //b4
        glVertex3f(-135,340,-210); //b5
        glVertex3f(-135,340,-178); //b5
        glVertex3f(-140,340,-145); //b6
        glVertex3f(-115,340,-105); //b7
        //titik c
        glVertex3f(-115,340,-70); //c1
        glVertex3f(-80,340,-30); //c2
        glVertex3f(-55,340,-20); //c3
        //titik d
        glVertex3f(-10,340,-20); //d1
        glVertex3f(10,340,-30); //d2
        glVertex3f(45,340,-70); //d3
    glEnd();
}

void atapAtas10(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        /** \brief S
         *
         * \param 45
         * \param 380
         * \param -95
         *
         */
        glVertex3f(45,380,-95); //a1
        glVertex3f(70,380,-110); //a2
        glVertex3f(75,380,-130); //a3
        glVertex3f(75,380,-190); //a4
        glVertex3f(40,380,-250); //a5
        glVertex3f(0,380,-270); //a6
        glVertex3f(-20,380,-265); //a7
        //titik b
        glVertex3f(-60,380,-280); //b1
        glVertex3f(-60,380,-280); //b2
        glVertex3f(-85,380,-245); //b3
        glVertex3f(-110,380,-240); //b4
        glVertex3f(-135,380,-210); //b5
        glVertex3f(-135,380,-178); //b5
        glVertex3f(-140,380,-145); //b6
        glVertex3f(-115,380,-105); //b7
        //titik c
        glVertex3f(-115,380,-70); //c1
        glVertex3f(-80,380,-30); //c2
        glVertex3f(-55,380,-20); //c3
        //titik d
        glVertex3f(-10,380,-20); //d1
        glVertex3f(10,380,-30); //d2
        glVertex3f(45,380,-70); //d3
    glEnd();
}

void atapAtas10_2(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,385,-95); //a1
        glVertex3f(70,385,-110); //a2
        glVertex3f(75,385,-130); //a3
        glVertex3f(75,385,-190); //a4
        glVertex3f(40,385,-250); //a5
        glVertex3f(0,385,-270); //a6
        glVertex3f(-20,385,-265); //a7
        //titik b
        glVertex3f(-60,385,-280); //b1
        glVertex3f(-60,385,-280); //b2
        glVertex3f(-85,385,-245); //b3
        glVertex3f(-110,385,-240); //b4
        glVertex3f(-135,385,-210); //b5
        glVertex3f(-135,385,-178); //b5
        glVertex3f(-140,385,-145); //b6
        glVertex3f(-115,385,-105); //b7
        //titik c
        glVertex3f(-115,385,-70); //c1
        glVertex3f(-80,385,-30); //c2
        glVertex3f(-55,385,-20); //c3
        //titik d
        glVertex3f(-10,385,-20); //d1
        glVertex3f(10,385,-30); //d2
        glVertex3f(45,385,-70); //d3
    glEnd();
}

void atapAtas11(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,420,-95); //a1
        glVertex3f(70,420,-110); //a2
        glVertex3f(75,420,-130); //a3
        glVertex3f(75,420,-190); //a4
        glVertex3f(40,420,-250); //a5
        glVertex3f(0,420,-270); //a6
        glVertex3f(-20,420,-265); //a7
        //titik b
        glVertex3f(-60,420,-280); //b1
        glVertex3f(-60,420,-280); //b2
        glVertex3f(-85,420,-245); //b3
        glVertex3f(-110,420,-240); //b4
        glVertex3f(-135,420,-210); //b5
        glVertex3f(-135,420,-178); //b5
        glVertex3f(-140,420,-145); //b6
        glVertex3f(-115,420,-105); //b7
        //titik c
        glVertex3f(-115,420,-70); //c1
        glVertex3f(-80,420,-70); //c2
        glVertex3f(-55,420,-50); //c3
        //titik d
        glVertex3f(-10,420,-50); //d1
        glVertex3f(10,420,-65); //d2
        glVertex3f(45,420,-70); //d3
    glEnd();
}

void atapAtas11_2(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,425,-95); //a1
        glVertex3f(70,425,-110); //a2
        glVertex3f(75,425,-130); //a3
        glVertex3f(75,425,-190); //a4
        glVertex3f(40,425,-250); //a5
        glVertex3f(0,425,-270); //a6
        glVertex3f(-20,425,-265); //a7
        //titik b
        glVertex3f(-60,425,-280); //b1
        glVertex3f(-60,425,-280); //b2
        glVertex3f(-85,425,-245); //b3
        glVertex3f(-110,425,-240); //b4
        glVertex3f(-135,425,-210); //b5
        glVertex3f(-135,425,-178); //b5
        glVertex3f(-140,425,-145); //b6
        glVertex3f(-115,425,-105); //b7
        //titik c
        glVertex3f(-115,425,-70); //c1
        glVertex3f(-80,425,-70); //c2
        glVertex3f(-55,425,-50); //c3
        //titik d
        glVertex3f(-10,425,-50); //d1
        glVertex3f(10,425,-65); //d2
        glVertex3f(45,425,-70); //d3
    glEnd();
}

void atapAtas12(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,450,-95); //a1
        glVertex3f(70,450,-110); //a2
        glVertex3f(75,450,-130); //a3
        glVertex3f(75,450,-190); //a4
        glVertex3f(40,450,-250); //a5
        glVertex3f(0,450,-270); //a6
        glVertex3f(-20,450,-265); //a7
        //titik b
        glVertex3f(-60,450,-280); //b1
        glVertex3f(-70,450,-225); //b2
        glVertex3f(-95,450,-220); //b3
        glVertex3f(-117,450,-200); //b4
        glVertex3f(-110,450,-178); //b5
        // glVertex3f(-135,450,-178); //b5
        glVertex3f(-140,450,-145); //b6
        glVertex3f(-115,450,-105); //b7
        //titik c
        glVertex3f(-115,450,-70); //c1
        glVertex3f(-80,450,-70); //c2
        glVertex3f(-55,450,-50); //c3
        //titik d
        glVertex3f(-10,450,-50); //d1
        glVertex3f(10,450,-65); //d2
        glVertex3f(45,450,-70); //d3
    glEnd();
}

void atapAtas12_2(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,455,-95); //a1
        glVertex3f(70,455,-110); //a2
        glVertex3f(75,455,-130); //a3
        glVertex3f(75,455,-190); //a4
        glVertex3f(40,455,-250); //a5
        glVertex3f(0,455,-270); //a6
        glVertex3f(-20,455,-265); //a7
        //titik b
        glVertex3f(-60,455,-280); //b1
        glVertex3f(-70,455,-225); //b2
        glVertex3f(-95,455,-220); //b3
        glVertex3f(-117,455,-200); //b4
        glVertex3f(-110,455,-178); //b5
        // glVertex3f(-135,455,-178); //b5
        glVertex3f(-140,455,-145); //b6
        glVertex3f(-115,455,-105); //b7
        //titik c
        glVertex3f(-115,455,-70); //c1
        glVertex3f(-80,455,-70); //c2
        glVertex3f(-55,455,-50); //c3
        //titik d
        glVertex3f(-10,455,-50); //d1
        glVertex3f(10,455,-65); //d2
        glVertex3f(45,455,-70); //d3
    glEnd();
}

void atapAtas13(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,480,-95); //a1
        glVertex3f(70,480,-110); //a2
        glVertex3f(55,480,-130); //a3
        glVertex3f(55,480,-185); //a4
        glVertex3f(25,480,-240); //a5
        glVertex3f(0,480,-250); //a6
        glVertex3f(-20,480,-265); //a7
        //titik b
        glVertex3f(-60,480,-280); //b1
        glVertex3f(-70,480,-225); //b2
        glVertex3f(-95,480,-220); //b3
        glVertex3f(-117,480,-200); //b4
        glVertex3f(-110,480,-178); //b5
        glVertex3f(-140,480,-145); //b6
        glVertex3f(-115,480,-105); //b7
        //titik c
        glVertex3f(-115,480,-70); //c1
        glVertex3f(-80,480,-70); //c2
        glVertex3f(-55,480,-50); //c3
        //titik d
        glVertex3f(-10,480,-50); //d1
        glVertex3f(10,480,-65); //d2
        glVertex3f(45,480,-70); //d3
    glEnd();
}

void atapAtas13_2(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,485,-95); //a1
        glVertex3f(70,485,-110); //a2
        glVertex3f(55,485,-130); //a3
        glVertex3f(55,485,-185); //a4
        glVertex3f(25,485,-240); //a5
        glVertex3f(0,485,-250); //a6
        glVertex3f(-20,485,-265); //a7
        //titik b
        glVertex3f(-60,485,-280); //b1
        glVertex3f(-70,485,-225); //b2
        glVertex3f(-95,485,-220); //b3
        glVertex3f(-117,485,-200); //b4
        glVertex3f(-110,485,-178); //b5
        glVertex3f(-140,485,-145); //b6
        glVertex3f(-115,485,-105); //b7
        //titik c
        glVertex3f(-115,485,-70); //c1
        glVertex3f(-80,485,-70); //c2
        glVertex3f(-55,485,-50); //c3
        //titik d
        glVertex3f(-10,485,-50); //d1
        glVertex3f(10,485,-65); //d2
        glVertex3f(45,485,-70); //d3
    glEnd();
}

void atapAtas14(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,500,-95); //a1
        glVertex3f(70,500,-110); //a2
        glVertex3f(55,500,-130); //a3
        glVertex3f(55,500,-185); //a4
        glVertex3f(25,500,-240); //a5
        glVertex3f(0,500,-250); //a6
        glVertex3f(-20,500,-265); //a7
        //titik b
        glVertex3f(-60,500,-280); //b1
        glVertex3f(-70,500,-225); //b2
        glVertex3f(-95,500,-220); //b3
        glVertex3f(-117,500,-200); //b4
        glVertex3f(-110,500,-178); //b5
        glVertex3f(-140,500,-145); //b6
        glVertex3f(-115,500,-105); //b7
        //titik c
        glVertex3f(-115,500,-70); //c1
        glVertex3f(-80,500,-70); //c2
        glVertex3f(-80,500,-90);//c3
        glVertex3f(-55,500,-70); //c4
        //titik d
        glVertex3f(-10,500,-70); //d1
        glVertex3f(10,500,-90); //d2
        glVertex3f(10,500,-65); //d3
        glVertex3f(45,500,-70); //d4
    glEnd();
}

void atapAtas14_2(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        //titik a
        glVertex3f(45,505,-95); //a1
        glVertex3f(70,505,-110); //a2
        glVertex3f(55,505,-130); //a3
        glVertex3f(55,505,-185); //a4
        glVertex3f(25,505,-240); //a5
        glVertex3f(0,505,-250); //a6
        glVertex3f(-20,505,-265); //a7
        //titik b
        glVertex3f(-60,505,-280); //b1
        glVertex3f(-70,505,-225); //b2
        glVertex3f(-95,505,-220); //b3
        glVertex3f(-117,505,-200); //b4
        glVertex3f(-110,505,-178); //b5
        glVertex3f(-140,505,-145); //b6
        glVertex3f(-115,505,-105); //b7
        //titik c
        glVertex3f(-115,505,-70); //c1
        glVertex3f(-80,505,-70); //c2
        glVertex3f(-80,505,-70); //c3
        glVertex3f(-55,505,-70); //c4
        //titik d
        glVertex3f(-10,505,-70); //d1
        glVertex3f(10,505,-90); //d2
        glVertex3f(10,505,-65); //d3
        glVertex3f(45,505,-70); //d4
    glEnd();
}

void atapAtas15(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(10,520,-90); //A1
        glVertex3f(10,520,-65); //A2
        glVertex3f(45,520,-70); //A3
        glVertex3f(45,520,-200); //A4
        glVertex3f(-117,520,-200); //B1
        glVertex3f(-115,520,-90); //A1 MOD
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-115,520,-70); //B2
        glVertex3f(-80,520,-70); //B3
        glVertex3f(-80,520,-90); //B4
        glVertex3f(-115,520,-90); //B4 MOD
    glEnd();
}

void atapBawah15(){
    glBegin(GL_POLYGON);
    glColor3ub(255,145,86);
        glVertex3f(10,505,-90); //A1
        glVertex3f(10,505,-65); //A2
        glVertex3f(45,505,-70); //A3
        glVertex3f(45,505,-200); //A4
        glVertex3f(-117,505,-200); //B1
        glVertex3f(-115,505,-90); //A1 MOD
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-115,505,-70); //B2
        glVertex3f(-80,505,-70); //B3
        glVertex3f(-80,505,-90); //B4
        glVertex3f(-115,505,-90); //B4 MOD
    glEnd();
}

void atapAtas15_2(){
glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(10,525,-90); //A1
        glVertex3f(10,525,-65); //A2
        glVertex3f(45,525,-70); //A3
        glVertex3f(45,525,-200); //A4
        glVertex3f(-117,525,-200); //B1
        glVertex3f(-115,525,-90); //A1 MOD
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-115,525,-70); //B2
        glVertex3f(-80,525,-70); //B3
        glVertex3f(-80,525,-90); //B4
        glVertex3f(-115,525,-90); //B4 MOD
    glEnd();
}

void atapAtas16(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(10,550,-90); //A1
        glVertex3f(10,550,-200); //A2
        glVertex3f(-80,550,-200); //A3
        glVertex3f(-80,550,-90); //A4
    glEnd();
}

void atapAtas16_2(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(10,553,-90); //A1
        glVertex3f(10,553,-200); //A2
        glVertex3f(-80,553,-200); //A3
        glVertex3f(-80,553,-90); //A4
    glEnd();
}

void atapAtas17(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(0,575,-100); //A1
        glVertex3f(0,575,-190); //A2
        glVertex3f(-70,575,-190); //A3
        glVertex3f(-70,575,-100); //A4
    glEnd();
}

void atapAtas17_1(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(0,578,-100); //A1
        glVertex3f(0,578,-190); //A2
        glVertex3f(-70,578,-190); //A3
        glVertex3f(-70,578,-100); //A4
    glEnd();
}

void atapAtas18(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(-10,600,-110); //A1
        glVertex3f(-10,600,-180); //A2
        glVertex3f(-60,600,-180); //A3
        glVertex3f(-60,600,-110); //A4
    glEnd();
}

void atapAtas18_2(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(-10,603,-110); //A1
        glVertex3f(-10,603,-180); //A2
        glVertex3f(-60,603,-180); //A3
        glVertex3f(-60,603,-110); //A4
    glEnd();
}

void atapAtas19(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(-20,625,-120); //A1
        glVertex3f(-20,625,-170); //A2
        glVertex3f(-50,625,-170); //A3
        glVertex3f(-50,625,-120); //A4
    glEnd();
}

void atapAtas19_2(){
    glBegin(GL_POLYGON);
    glColor3ub(211,206,213);
        glVertex3f(-20,628,-120); //A1
        glVertex3f(-20,628,-170); //A2
        glVertex3f(-50,628,-170); //A3
        glVertex3f(-50,628,-120); //A4
    glEnd();
}
// ATAP

void tampil(void){

    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    // if(redisplay %2==0){
    //     gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // }
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);


    glScalef(1.3, 1.3, 1.0);

    // OBJEK
    waitingRoom();
    kanopi();
    tanah();
    kolam();
    jalanraya();

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

    //LANTAI 9
    lantai9();
    atapAtas9();
    line9();
    atapAtas9_2();

    //LANTAI 10
    lantai10();
    atapAtas10();
    line10();
    atapAtas10_2();

    //LANTAI 11
    lantai11();
    atapAtas11();
    line11();
    atapAtas11_2();

    //LANTAI 12
    lantai12();
    atapAtas12();
    line12();
    atapAtas12_2();

    //LANTAI 13
    lantai13();
    atapAtas13();
    line13();
    atapAtas13_2();

    //LANTAI 14
    lantai14();
    line14();
    atapAtas14_2();

    //LANTAI 15
    atapBawah15();
    lantai15();
    atapAtas15();
    line15();
    atapAtas15_2();

    //LANTAI16
    lantai16();
    atapAtas16();
    line16();
    atapAtas16_2();

    //LANTAI 17
    lantai17();
    atapAtas17();
    line17();
    atapAtas17_1();

    //LANTAI 18
    lantai18();
    atapAtas18();
    line18();
    atapAtas18_2();

    //LANTAI 19
    lantai19();
    atapAtas19();
    line19();
    atapAtas19_2();

    //LANTAI 20
    lantai20();

    // TITIK POTONG
    //Garis AB
    float ax=-300;
    float ay=300;
    float bx=-280;
    float by=301;

    //Garis CD
    float cx=-290;
    float cy=292;
    float dx=-291;
    float dy=308;

    //Garis EF
    float ex=-297;
    float ey=305;
    float fx=-282;
    float fy=295;

    //Garis GH
    float gx=-297;
    float gy=295;
    float hx=-285;
    float hy=305;

    float m1,c1,m2,c2,m3,c3,m4,c4,px,py;
        glBegin(GL_LINES);
            glVertex2f(ax,ay);
            glVertex2f(bx,by);

            glVertex2f(cx,cy);
            glVertex2f(dx,dy);

            glVertex2f(ex,ey);
            glVertex2f(fx,fy);

            glVertex2f(gx,gy);
            glVertex2f(hx,hy);
        glEnd();


 //Menentukan Persamaan Garis
        //AB
        m1 = (by-ay)/(bx-ax);
        c1 = ay - (m1*ax);

        //CD
        m2 = (dy-cy)/(dx-cx);
        c2 = cy - (m2*cx);

        //EF
        m3 = (fy-ey)/(fx-ex);
        c3 = ey - (m3*ex);

        //GH
        m4 = (hy-gy)/(hx-gx);
        c4 = gy - (m4*gx);

    //Menentukan Titik Potong
        px = (c2-c1)/(m1-m2);
        py = (m1*px) + c1;
            glPointSize(8);

        glBegin(GL_POINTS);
        glColor3f(0,1,0);
            glVertex2f(px,py);
        glEnd();

    glFlush();
    glPopMatrix();
    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    }else{
        mouseDown = false;
    }
    glutPostRedisplay();
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
        //GESER KE KIRI
    case 'a':
        glTranslatef(-10.0, 0.0, 0.0);
        break;
    case 'A':
        glTranslatef(-10.0, 0.0, 0.0);
        break;
        //GESER KE KANAN
    case 'd':
        glTranslatef(10.0, 0.0, 0.0);
        break;
    case 'D':
        glTranslatef(10.0, 0.0, 0.0);
        break;
        //GESER KE ATAS
    case 'w':
        glTranslatef(0.0, 10, 0.0);
        break;
    case 'W':
        glTranslatef(0.0, 10, 0.0);
        break;
        //GERAL KE BAWAH
    case 's':
        glTranslatef(0.0, -10, 0.0);
        break;
    case 'S':
        glTranslatef(0.0, -10, 0.0);
        break;
        //GERAK KE DEPAN
    case 'z':
        glTranslatef(0.0, 0.0, 10);
        break;
    case 'Z':
        glTranslatef(0.0, 0.0, 10);
        break;
        //GERAK KE BELAKANG
    case 'x':
        glTranslatef(0.0, 0.0, -10);
        break;
    case 'X':
        glTranslatef(0.0, 0.0, -10);
        break;
        //ROTATE KE KIRI
    case '4':
        glRotatef(1.0, 0.0, -5.0, 0.0);
        break;
    case 'K':
        // glRotatef(5.0, 0.0, -5.0, 0.0);
        pintu++;
        break;
        //ROTATE KE KANAN
    case '6':
        glRotatef(1.0, 0.0, 5.0, 0.0);
        break;
    case '/':
        glRotatef(2.0, 0.0, 5.0, 0.0);
        break;

    case '5':
        redisplay++;
        if(is_depth){
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    	//rotate ke samping kanan
		//case '9':
			//glRotatef(2.0, 0.0, 0.0, -5.0);
			//break;
		case '3':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case '1':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
		case 'i':
			glRotatef(5.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case '8':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
		case 'u':
			glRotatef(5.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case '2':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
		case 'l':
			glRotatef(5.0, 5.0, 0.0, 0.0);
			break;
//        case 'p':
//            if(pin==0)
//                pin=1;
//            else
//                pin=0;
//            break;
//        case 't':
//            if(tag==0)
//                tag=1;
//            else
//                tag=0;
//            break;
    }
    tampil();
}
void ukuran(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, aspect,5.0,900.0);
    glTranslatef(0.0,-100.0,-500.0);
    glMatrixMode(GL_MODELVIEW);
}

