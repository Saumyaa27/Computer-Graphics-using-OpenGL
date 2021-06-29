#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float x1 =150.0, y1 = 150.0, x2 = 250.0, y2 = 180.0, x3 = 300.0, y3 = 300.0;
	float m1 = float(y2 - y1) / (x2 - x1);
	float m2 = float(y3 - y2) / (x3 - x2);
	float m3 = float(y1 - y3) / (x1 - x3);
	float c1 = y1 - m1 * x1;
	float c2 = y2 - m2 * x2;
	float c3 = y3 - m3 * x3;
	int i = 0;

	while (x1 + i <= x2) {
		glVertex2f(x1 + i, m1 * (x1 + i) + c1);
		i++;
	}
	i = 0;
	while (x2 + i <= x3) {
		glVertex2f(x2 + i, m2 * (x2 + i) + c2);
		i++;
	}
	i = 0;
	while (x3 - i >= x1) {
		glVertex2f(x3 - i, m3 * (x3 - i) + c3);
		i++;
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
