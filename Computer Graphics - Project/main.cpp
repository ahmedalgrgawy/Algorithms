#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>

float moveC = 0.0f;
float moveB1 = 0.0f;
float moveB2 = 0.0f;
float speed = 0.02f;


void DrawAllComponents()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity(); // reset current matrix
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW); // Handles object transformations.


    //sky
    glBegin(GL_POLYGON);

    glColor3ub(112,160,228);

    glVertex2f(38.0,3.0);
    glVertex2f(38.0,14.0);
    glVertex2f(-12.0,14.0);
    glVertex2f(-12.0,3.0);

    glEnd();

    // Sun
    glPushMatrix();

    glColor3d(1,1,0);

    glTranslatef(1.0, 7.0, 0);

    glutSolidSphere(1.0, 750, 300);

    glPopMatrix();

    //Cloud-01

    glPushMatrix();

    glTranslatef(moveC,0.0f,0.0f);

    glPushMatrix();

    glColor3d(255,255,255);

    glTranslatef(1.0, 6.0, 0);

    glutSolidSphere(0.7, 250, 250);

    glPopMatrix();


    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPopMatrix();


    //cloud-02

    glPushMatrix();

    glTranslatef(moveC,0.0f,0.0f);

    glPushMatrix();

    glColor3d(255,255,255); // white

    glTranslatef(15.0, 9.0, 0);

    glutSolidSphere(0.8, 250, 250);

    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(16.0, 8.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(16.0, 9.0, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(14.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255,255,255);
    glTranslatef(17.0, 8.5, 0);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPopMatrix();


    //See portion

    glPushMatrix();

    glBegin(GL_POLYGON);

    glColor3ub(65,105,225); // blue + left top first

    glVertex2f(40.0,-19.0);  /// right-down
    glVertex2f(38.0,-11.0); /// right-top
    glVertex2f(-12.0,-11.0); /// left-top
    glVertex2f(-12.0,-19.0);  /// left-down

    glEnd();


    //Ground portion
    glBegin(GL_POLYGON);

    glColor3ub(25,128,0); // green

    glVertex2f(90.0f, -12.5f); /// angle
    glVertex2f(38.0f,-12.0f);  /// right-down
    glVertex2f(38.0f,3.0f); /// right-top
    glVertex2f(-12.0f,3.0f); /// left-top
    glVertex2f(-12.0f,-11.0f);  /// left-down

    glEnd();



    // House Drawing

    //black
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(8.09,-5.01);
    glVertex2f(10.96,-2.02);
    glVertex2f(14.10, -5.01);
    glEnd();

    //brown
    glColor3ub(145, 0, 12);
    glBegin(GL_QUADS);
    glVertex2f(9.15, -5.01);
    glVertex2f(9.14, -9.02);
    glVertex2f(12.85, -9.04);
    glVertex2f(12.84, -5.01);
    glEnd();

    //red
    glColor3ub(245, 10, 49);
    glBegin(GL_QUADS);
    glVertex2f(10.36, -6.79);
    glVertex2f(10.35, -8.91);
    glVertex2f(11.59, -8.99);
    glVertex2f(11.58, -6.79);
    glEnd();


    // Tree

    // triangle
    glColor3ub(22, 208, 70);
    glBegin(GL_TRIANGLES);
    glVertex2f(14.88, -6.16);
    glVertex2f(20, 0);
    glVertex2f(24.98, -6.16);
    glEnd();

    //wood
    glColor3ub(191, 158, 24);
    glBegin(GL_QUADS);
    glVertex2f(19.02, -6.06);
    glVertex2f(20.96, -6.09);
    glVertex2f(21, -10.08);
    glVertex2f(19.01, -10.08);
    glEnd();




    //boat-1 speed left to right
    glPushMatrix();
    glTranslatef(moveB1, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2f(1.0f, -14.0f);
    glVertex2f(1.50f, -13.0f);
    glVertex2f(-2.0f, -13.0f);
    glVertex2f(-3.0f, -14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-3.0f, -14.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(-3.0f, -14.5f);
    glVertex2f(-3.0f, -14.0f);
    glVertex2f(-4.5f, -13.7f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(2.0f, -14.5f);
    glVertex2f(3.5f, -13.7f);
    glVertex2f(2.0f, -14.0f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(2.0f, -14.0f);
    glVertex2f(1.5f, -13.0f);
    glVertex2f(1.0f, -14.0f);

    glEnd();

    glPopMatrix();



    //boat-2 motion right to left
    glPushMatrix();
    glTranslatef(moveB2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(21.0f, -16.5f);
    glVertex2f(17.50f, -16.5f);
    glVertex2f(18.0f, -17.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(17.0f, -18.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(17.0f, -18.0f);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(15.5f, -17.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(22.0f, -17.5f);
    glVertex2f(22.0f, -18.0f);
    glVertex2f(23.5f, -17.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2f(17.0f, -17.5f);
    glVertex2f(18.0f, -17.5f);
    glVertex2f(17.5f, -16.5f);
    glEnd();

    glPopMatrix();


    //end
    glPopMatrix();
    glutSwapBuffers();
}



void updateC(int value)
{

    if(moveC > +36)
    {
        moveC = -38;
    }
    moveC += 0.15;

    glutTimerFunc(20, updateC, 0);
    glutPostRedisplay();
}


void updateB1(int value)
{

    moveB1 += speed;
    if(moveB1 > 38)
    {
        moveB1 = -38;
    }
    glutTimerFunc(20, updateB1, 0); //Notify GLUT to call update again in 20 milliseconds
    glutPostRedisplay();
}



void updateB2(int value)
{


    if(moveB2 < -36)
    {
        moveB2 = +38;
    }

    //Notify GLUT that the display has changed

    moveB2 -= 0.13;

    glutTimerFunc(20, updateB2, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}



void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's'://stops
        speed = 0.0f;
        break;
    case 'r'://runs
        speed = 0.02f;
        break;
        glutPostRedisplay();
    }
}


void handleMouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        speed += 0.05f;
    }


    else if (button == GLUT_RIGHT_BUTTON)
    {
        speed -= 0.05f;
    }
    glutPostRedisplay();
}





void display(void)
{
    DrawAllComponents();
    glFlush ();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1300, 700);
    glutInitWindowPosition(100,100);
    glutCreateWindow(" Moving Boats");
    init();

    glutTimerFunc(100, updateC, 1);    // cloud speed
    glutTimerFunc(100, updateB1, 0); //Boat 1
    glutTimerFunc(100, updateB2, 0); //boat 2

    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
