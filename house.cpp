#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// ROOF TOP
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(200, 500);
	glVertex2i(600, 500);
	glVertex2i(700, 350);
	glVertex2i(300, 350);
	glEnd();


	//CHIMNEY
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(550, 500);
	glVertex2i(600, 500);
	glVertex2i(600, 550);
	glVertex2i(550, 550);
	glEnd();

	// FRONT ROOF
	glColor3f(0.6, 0.6, 0.0);

	glBegin(GL_TRIANGLES);
	glVertex2i(200, 500);
	glVertex2i(100, 350);
	glVertex2i(300, 350);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(200, 500);
	glVertex2i(205, 496);
	glVertex2i(100, 350);
	glVertex2i(95, 350);
	glEnd();

	// FRONT WALL
	glColor3f(0.6, 0.6, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(100, 350);
	glVertex2i(300, 350);
	glVertex2i(300, 100);
	glVertex2i(100, 100);
	glEnd();

	// FRONT DOOR
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(150, 250);
	glVertex2i(250, 250);
	glVertex2i(250, 100);
	glVertex2i(150, 100);
	glEnd();
	//WINDOW
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	float x2 = 0.0, y2 = 40.0;
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
		glVertex2f(x2 + 200, y2 + 370);
		glVertex2f(-x2 + 200, y2 + 370);
		glVertex2f(x2 + 200, -y2 + 370);
		glVertex2f(-x2 + 200, -y2 + 370);
		glVertex2f(y2 + 200, x2 + 370);
		glVertex2f(-y2 + 200, x2 + 370);
		glVertex2f(y2 + 200, -x2 + 370);
		glVertex2f(-y2 + 200, -x2 + 370);
	}

	glEnd();

	// SIDE WALL
	glColor3f(0.0, 0.3, 1.0);

	glBegin(GL_POLYGON);
	glVertex2i(300, 350);
	glVertex2i(650, 350);
	glVertex2i(650, 100);
	glVertex2i(300, 100);
	glEnd();

	// SIDE WINDOW - 1
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex2i(400, 320);
	glVertex2i(600, 320);
	glVertex2i(600, 230);
	glVertex2i(400, 230);
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
	glutCreateWindow("2D HOUSE");
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();
}