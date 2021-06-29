// ConsoleApplication5.cpp : Defines the entry point for the console application.
#include<GL/glut.h>
#include<cmath>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float x1 = 10.0, y1 = 100, x2 = 50.0, y2 = 50.0;
	float diffx = x2 - x1;
	float diffy = y2 - y1;
	float m = diffy / diffx;
	int steps = 0;
	if (fabs(diffx) >= abs(diffy))
		steps = diffx;
	else
		steps = diffy;
	float yinc = diffy / steps;
	float xinc = diffx / steps;
	for (int i = 0; i <= steps; i += 1) {
		x1 = x1 + xinc;
		y1 = y1 + yinc;
		glVertex2f(x1, y1);
	}
	glEnd();
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}