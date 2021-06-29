#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400, 0.0, 300.0);
}

float current_angle = 0.0f;
float step_angle = 0.1f;
float x = 168.0f;
float y = 180.0f;

void windmill() {
    //  tower
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(160, 50);
    glVertex2f(160, 180);
    glVertex2f(160, 50);
    glVertex2f(175, 50);
    glVertex2f(175, 50);
    glVertex2f(172, 180);
    glEnd();

    // Rotate object
    glTranslatef(x, y, 0.0f);
    glRotatef(current_angle, 0, 0, 1);
    current_angle += step_angle;
    glTranslatef(-x, -y, 0.0f);

    // first blade
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(173, 180);
    glVertex2f(163, 180);
    glVertex2f(168, 270);
    glEnd();
    // second blade
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(170, 174);
    glVertex2f(175, 180);
    glVertex2f(247, 140);
    glEnd();
    // third blade
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(162, 180);
    glVertex2f(167, 174);
    glVertex2f(88, 140);
    glEnd();
    // circle in the middle
    float theta;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i <= 360; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(168 + 7 * cos(theta), 180 + 6.5 * sin(theta));
    }
    glEnd();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    windmill();
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Wind Mill");
    init();
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}