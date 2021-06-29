// ConsoleApplication5.cpp : Defines the entry point for the console application.
#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float x1 = 10.0, y1 = 10.0, x2 = 50.0, y2 = 50.0;
	float diffx = x2 - x1;
	float diffy = y2 - y1;
	float p = 2 * diffy - diffx;
	while (x1 < x2) {
		if (p < 0)
		{
			x1 = x1 + 1;
			p = p + (2 * diffy);
		}
		else
		{
			x1 = x1 + 1;
			y1 = y1 + 1;
			p = p + (2 * diffy) - (2 * diffx);
		}
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