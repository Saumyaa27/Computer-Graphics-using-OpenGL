#include<iostream>
#include<GL/glut.h>
using namespace std;

// 4-way symmetry
void ellipse1(int x, int y) {
	glVertex2f(x + 200, y + 150);
	glVertex2f(-x + 200, y + 150);
	glVertex2f(x + 200, -y + 150);
	glVertex2f(-x + 200, -y + 150);
}
// Plot the points of Region-2
void ellipse2(int x, int y) {
	glVertex2f(x + 200, y + 150);
	glVertex2f(-x + 200, y + 150);
	glVertex2f(x + 200, -y + 150);
	glVertex2f(-x + 200, -y + 150);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// BODY
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_POLYGON);
	float rx = 130, ry = 40, p, x, y;
	x = 0;
	y = ry;
	p = (ry * ry) - (rx * rx) * ry + (0.25 * rx * rx);
	float dx = 2 * ry * ry * x;
	float dy = 2 * rx * rx * y;
	while (dx < dy) {
		ellipse1(x, y);
		if (p < 0) {
			dx = dx + 2 * ry * ry;
			p = p + 2 * ry * ry * x + ry * ry;
		}
		else {
			dx = dx + 2 * ry * ry;
			dy = dy - 2 * rx * rx;
			p = p + dx - dy + ry * ry;
			y = y - 1;
		}
		x = x + 1;
	}
	cout << x << "\t" << y << endl;
	float p_next = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

	while (y > 0) {
		ellipse2(x, y);
		if (p_next < 0) {
			dy = dy - 2 * rx * rx;
			dx = dx + 2 * ry * ry;
			p_next = p_next + dx - dy + rx * rx;
			x = x + 1;
		}
		else {
			dy = dy - 2 * rx * rx;
			p_next = p_next - dy + rx * rx;
		}
		y = y - 1; \
	}
	glEnd();

	// TAIL
	glColor3f(1.0, 0.5, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(325, 160);
	glVertex2i(400, 175);
	glVertex2i(400, 132);
	glVertex2i(325, 147);
	glEnd();

	// FISH FINS
	glColor3f(1.0, 0.5, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2i(175, 188);
	glVertex2i(250, 210);
	glVertex2i(260, 186);
	glEnd();

	// PARTITION
	glColor3f(0.0, 0.0, 0.0);

	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2i(140, 184);
	glVertex2i(140, 116);
	glEnd();
	//bubble1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	float x4 = 0.0, y4 = 8.0;
	float p4 = 1 - y4;
	while (x4 <= y4) {
		if (p4 < 0) {
			p4 = p4 + 2 * x4 + 3;
			x4 = x4 + 1;
		}
		else {
			y4 = y4 - 1;
			x4 = x4 + 1;
			p4 = p4 + 2 * (x4 - y4) + 5;
		}
		glVertex2f(x4 + 45, y4 + 150);
		glVertex2f(-x4 + 45, y4 + 150);
		glVertex2f(x4 + 45, -y4 + 150);
		glVertex2f(-x4 + 45, -y4 + 150);
		glVertex2f(y4 + 45, x4 + 150);
		glVertex2f(-y4 +45, x4 + 150);
		glVertex2f(y4 + 45, -x4 + 150);
		glVertex2f(-y4 + 45, -x4 + 150);
	}
	glEnd();
	//bubble2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	float x5 = 0.0, y5 = 8.0;
	float p5 = 1 - y5;
	while (x5 <= y5) {
		if (p5 < 0) {
			p5 = p5 + 2 * x5 + 3;
			x5 = x5 + 1;
		}
		else {
			y5 = y5 - 1;
			x5 = x5 + 1;
			p5 = p5 + 2 * (x5 - y5) + 5;
		}
		glVertex2f(x5 + 35, y5 + 175);
		glVertex2f(-x5 + 35, y5 + 175);
		glVertex2f(x5 + 35, -y5 + 175);
		glVertex2f(-x5 + 35, -y5 + 175);
		glVertex2f(y5 + 35, x5 + 175);
		glVertex2f(-y5 + 35, x5 + 175);
		glVertex2f(y5 + 35, -x5 + 175);
		glVertex2f(-y5 + 35, -x5 + 175);
	}

	glEnd();



	// EYE
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POINTS);
	float x2 = 0.0, y2 = 2.0;
	float p2 = 1 - y2;
	while (x2 <= y2) {
		if (p2 < 0) {
			p2 = p2 + 2 * x2 + 3;
			x2 = x2 + 1;
		}
		else {
			y2 = y2 - 1;
			x2 = x2 + 1;
			p2 = p2 + 2 * (x2 - y2) + 5;
		}
		glVertex2f(x2 + 105, y2 + 155);
		glVertex2f(-x2 + 105, y2 + 155);
		glVertex2f(x2 + 105, -y2 + 155);
		glVertex2f(-x2 + 105, -y2 + 155);
		glVertex2f(y2 + 105, x2 + 155);
		glVertex2f(-y2 + 105, x2 + 155);
		glVertex2f(y2 + 105, -x2 + 155);
		glVertex2f(-y2 + 105, -x2 + 155);
	}

	glEnd();
	glFlush();

}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("fish");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}