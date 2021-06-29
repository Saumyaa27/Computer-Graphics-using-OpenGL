#include<GL/glut.h>
#include<math.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	//car boundary
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(480, 100);
	glVertex2f(480, 150);
	glVertex2f(430, 160);
	glVertex2f(380, 200);
	glVertex2f(200, 200);
	glVertex2f(150, 160);
	glVertex2f(100, 150);
	glEnd();
	//wheel 1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	float x = 0.0, y = 25.0;
	float r = 25;
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
		glVertex2f(x+200, y+95);
		glVertex2f(-x+200, y + 95);
		glVertex2f(x + 200, -y + 95);
		glVertex2f(-x + 200, -y + 95);
		glVertex2f(y + 200, x + 95);
		glVertex2f(-y + 200, x + 95);
		glVertex2f(y + 200, -x + 95);
		glVertex2f(-y + 200, -x +95);
	}

	glEnd();
	//wheel 2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	float x1 = 0.0, y1 = 25.0;
	float p2 = 1 - r;
	while (x1 <= y1) {
		if (p2 < 0) {
			p2 = p2 + 2 * x1 + 3;
			x1 = x1 + 1;
		}
		else {
			y1 = y1 - 1;
			x1 = x1 + 1;
			p2 = p2 + 2 * (x1 - y1) + 5;
		}
		glVertex2f(x1 + 380, y1 + 95);
		glVertex2f(-x1 + 380, y1 + 95);
		glVertex2f(x1 + 380, -y1 + 95);
		glVertex2f(-x1 + 380, -y1 + 95);
		glVertex2f(y1 + 380, x1 + 95);
		glVertex2f(-y1 + 380, x1 + 95);
		glVertex2f(y1 + 380, -x1 + 95);
		glVertex2f(-y1 + 380, -x1 + 95);
	}
	glEnd();
	//headlight
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	float x2 = 0.0, y2 = 13.0;
	float p3 = 1 - r;
	while (x2 <= y2) {
		if (p3 < 0) {
			p3 = p3 + 2 * x2 + 3;
			x2 = x2 + 1;
		}
		else {
			y2 = y2 - 1;
			x2 = x2 + 1;
			p3 = p3 + 2 * (x2 - y2) + 5;
		}
		glVertex2f(-x2 + 100, y2 + 125);
		glVertex2f(-x2 + 100, -y2 + 125);
		glVertex2f(-y2 + 100, x2+ 125);
		glVertex2f(-y2 + 100, -x2 + 125);
	}
	glEnd();

	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}
