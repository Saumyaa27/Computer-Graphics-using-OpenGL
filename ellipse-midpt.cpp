#include<GL/glut.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	float rx = 70.0, ry = 50.0, x = 0, y = 50.0;
	float dx = 2 * ry * ry * x, dy = 2 * rx * rx * y;
	float p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;
	while (dx <= dy) {
		glVertex2f(x, y);
		glVertex2f(-x, y);
		glVertex2f(x, -y);
		glVertex2f(-x, -y);
		if (p1 < 0) {
			x = x + 1;
			dx = dx + 2 * ry * ry;
			p1 = p1 + dx + ry * ry;
		}
		else {
			y = y - 1;
			x = x + 1;
			dx = dx + 2 * ry * ry;
			dy = dy - 2 * rx * rx;
			p1 = p1 + dx - dy + ry * ry;
		}
	}
	float p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
	while (y > 0) {
		glVertex2f(x, y);
		glVertex2f(-x, y);
		glVertex2f(x, -y);
		glVertex2f(-x, -y);
		if (p2 > 0) {
			y = y - 1;
			dy = dy - 2 * rx * rx;
			p2 = p2 - dy + rx * rx;
		}
		else {
			x = x + 1;
			y = y - 1;
			dy = dy - 2 * rx * rx;
			dx = dx + 2 * ry * ry;
			p2 = p2 + dx - dy + rx * rx;
		}
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