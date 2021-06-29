#include <iostream>
#include <math.h>
#include <GL/glut.h>

float  counterr = 0.0;
float counterl = 500.0;
float rmargin = 500.0;
float lmargin = 0;
void initOpenGl()
{
    glClearColor(0.0, 0.0, 0.0, 1); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void circle(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glEnd();

}

void lr() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    counterr = counterr + 0.03;
    glTranslated(counterr, 100, 0.0);
    circle(200, 100);
    glutSwapBuffers();
    glFlush();
}
void rl() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    counterl = counterl - 0.03;
    glTranslated(counterl, 100, 0.0);
    circle(200, 100);
    glutSwapBuffers();
    glFlush();
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    while (counterr < rmargin) {
        lr();
    }
    counterr = 0;
    while (counterl > lmargin) {
        rl();
    }
    counterl = 500.0;
  
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