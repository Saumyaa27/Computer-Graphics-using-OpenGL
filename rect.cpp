#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	int i = 0;
	for (int i = 200; i <= 450; i += 1) {
		glVertex2f(i, 200);
	}
	for (int i = 200; i <= 450; i += 1) {
		glVertex2f(i, 350);
	}
	for (int i = 200; i <= 350; i += 1) {
		glVertex2f(200, i);
	}
	for (int i = 200; i <= 350; i += 1) {
		glVertex2f(450, i);
	}

	glEnd();
	glFlush();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
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
