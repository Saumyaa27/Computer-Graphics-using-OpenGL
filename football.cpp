#include <iostream>
#include <math.h>
#include <GL/glut.h>

float  counterx = 0.0;
float  countery = 0.0;
void initOpenGl()
{
    glClearColor(0.0, 1.0, 0.0, 1); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void circle(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glEnd();

}

void goal_post() {

    // Sky
    glColor3f(0.000, 0.60, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(800, 500);
    glVertex2f(0, 500);
    glColor3f(0.933, 0.933, 0.933);
    glVertex2f(0, 200);
    glVertex2f(800, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(675, 50);
    glVertex2f(675, 380);
    glVertex2f(675, 50);
    glVertex2f(680, 50);
    glVertex2f(680, 50);
    glVertex2f(680, 380);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(555, 100);
    glVertex2f(555, 420);
    glVertex2f(555, 100);
    glVertex2f(560, 100);
    glVertex2f(560, 100);
    glVertex2f(560, 420);
    glEnd();

    glLineWidth(1);
    glPointSize(1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(680, 340);
    glVertex2i(565, 380);
    glEnd();

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    goal_post();
    if(countery<=200)
    {
        countery = countery + 0.03;
    }
    else if(countery>200) {
        countery = countery - 0.03;
    }
    counterx = counterx + 0.06;
    if (counterx >= 450) {
        counterx = 0.0;
        countery = 0.0;
    }
    glTranslated(counterx, countery, 0.0);
    circle(200, 100);
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("animation");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}