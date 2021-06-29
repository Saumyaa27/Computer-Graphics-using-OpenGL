#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//head
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	float x1 = 0.0, y1 = 25.0;
	float r = 25;
	float p1 = 1 - r;
	while (x1 <= y1) {
		if (p1 < 0) {
			p1 = p1 + 2 * x1 + 3;
			x1 = x1 + 1;
		}
		else {
			y1 = y1 - 1;
			x1 = x1 + 1;
			p1 = p1 + 2 * (x1 - y1) + 5;
		}
		glVertex2f(x1 + 250, y1 + 450);
		glVertex2f(-x1 + 250, y1 + 450);
		glVertex2f(x1 + 250, -y1 + 450);
		glVertex2f(-x1 + 250, -y1 + 450);
		glVertex2f(y1 + 250, x1 + 450);
		glVertex2f(-y1 + 250, x1 + 450);
		glVertex2f(y1 + 250, -x1 + 450);
		glVertex2f(-y1 + 250, -x1 + 450);
	}
	glEnd();
	//body of man
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(230, 350);
	glVertex2f(230, 425);
	glVertex2f(270, 425);
	glVertex2f(270, 350);
	glEnd();
	//legs
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(250, 350);
	glVertex2f(270, 350);
	glVertex2f(285, 270);
	glVertex2f(260, 270);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(215, 270);
	glVertex2f(230, 350);
	glVertex2f(250, 350);
	glVertex2f(240, 270);
	glEnd();
	//feet
	//foot1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	float x3 = 0.0, y3 = 13.0;
	float p3 = 1 - y3;
	while (x3 <= y3) {
		if (p3 < 0) {
			p3 = p3 + 2 * x3 + 3;
			x3 = x3 + 1;
		}
		else {
			y3 = y3 - 1;
			x3 = x3 + 1;
			p3 = p3 + 2 * (x3 - y3) + 5;
		}
		glVertex2f(x3 + 230, y3 + 260);
		glVertex2f(-x3 + 230, y3 + 260);
		glVertex2f(x3 + 230, -y3 + 260);
		glVertex2f(-x3 + 230, -y3 + 260);
		glVertex2f(y3 + 230, x3 + 260);
		glVertex2f(-y3 + 230, x3 + 260);
		glVertex2f(y3 + 230, -x3 + 260);
		glVertex2f(-y3 + 230, -x3 + 260);
	}

	glEnd();
	//foot2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	float x4 = 0.0, y4 = 13.0;
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
		glVertex2f(x4 + 275, y4 + 260);
		glVertex2f(-x4 + 275, y4 + 260);
		glVertex2f(x4 + 275, -y4 + 260);
		glVertex2f(-x4 + 275, -y4 + 260);
		glVertex2f(y4 + 275, x4 + 260);
		glVertex2f(-y4 + 275, x4 + 260);
		glVertex2f(y4 + 275, -x4 + 260);
		glVertex2f(-y4 + 275, -x4 + 260);
	}

	glEnd();

	//arms
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(300, 370);
	glVertex2f(285, 370);
	glVertex2f(270, 425);
	glVertex2f(285, 425);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(200, 370);
	glVertex2f(215, 370);
	glVertex2f(230, 425);
	glVertex2f(215, 425);
	glEnd();
	//hand1
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	float x = 0.0, y = 9.0;
	float p = 1 - y;
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
		glVertex2f(x + 210, y + 370);
		glVertex2f(-x + 210, y + 370);
		glVertex2f(x + 210, -y + 370);
		glVertex2f(-x + 210, -y + 370);
		glVertex2f(y + 210, x + 370);
		glVertex2f(-y + 210, x + 370);
		glVertex2f(y + 210, -x + 370);
		glVertex2f(-y + 210, -x + 370);
	}

	glEnd();
	//hand2
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.6, 0.0);
	float x2 = 0.0, y2 = 9.0;
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
		glVertex2f(x2 + 290, y2 + 370);
		glVertex2f(-x2 + 290, y2 + 370);
		glVertex2f(x2 + 290, -y2 + 370);
		glVertex2f(-x2 + 290, -y2 + 370);
		glVertex2f(y2 + 290, x2 + 370);
		glVertex2f(-y2 + 290, x2 + 370);
		glVertex2f(y2 + 290, -x2 + 370);
		glVertex2f(-y2 + 290, -x2 + 370);
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
