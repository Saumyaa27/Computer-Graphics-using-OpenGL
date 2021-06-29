#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float x = 0.100, y = 180.0;
	float r = 10;
	float p = 1 - r;
	while (x <= y) {
		if (p < 0) {
			p = p + 2 * x + 3;
			x = x + 1;
		}
		else {
			y = y - 1;
			x = x + 1;
			p = p + 2 * (x - y) + 5;
		}
		glVertex2f(x, y);
		glVertex2f(-x, y);
		glVertex2f(x, -y);
		glVertex2f(-x, -y);
		glVertex2f(y, x);
		glVertex2f(-y, x);
		glVertex2f(y, -x);
		glVertex2f(-y, -x);
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
	gluOrtho2D(-500, 499.0, -500.0, 499.0);
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