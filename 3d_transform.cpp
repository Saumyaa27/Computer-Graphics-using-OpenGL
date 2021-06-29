#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
float p[8][3] = { {80, 80, -100}, { 180,80,-100 }, { 180,180,-100 }, { 80,180,-100 },
	{ 60,60,0 }, { 160,60,0 }, { 160,160,0 }, { 60,160,0 } };



void makeCuboid(float a[8][3]) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int i;
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0][0], a[0][1], a[0][2]);
	glVertex3f(a[1][0], a[1][1], a[1][2]);
	glVertex3f(a[2][0], a[2][1], a[2][2]);
	glVertex3f(a[3][0], a[3][1], a[3][2]);
	glEnd();
	i = 0;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
	glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
	glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
	glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0][0], a[0][1], a[0][2]);
	glVertex3f(a[3][0], a[3][1], a[3][2]);
	glVertex3f(a[7][0], a[7][1], a[7][2]);
	glVertex3f(a[4][0], a[4][1], a[4][2]);
	glEnd();
	i = 1;
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
	glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
	glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
	glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
	glEnd();
	i = 2;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
	glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
	glVertex3f(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
	glVertex3f(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
	glEnd();
	i = 4;
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
	glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
	glVertex3f(a[2 + i][0], a[2 + i][1], a[2 + i][2]);
	glVertex3f(a[3 + i][0], a[3 + i][1], a[3 + i][2]);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void translate(float a[8][3]) {
	int tx, ty, tz;
	cin >> tx >> ty >> tz;
	for (int i = 0; i < 8; i++) {
		a[i][0] = a[i][0] + tx;
		a[i][1] = a[i][1] + ty;
		a[i][2] = a[i][2] + tz;
	}
	makeCuboid(a);
}

void scale(float a[8][3]) {
	float sx, sy, sz;
	cin >> sx >> sy >> sz;
	for (int i = 0; i < 8; i++) {
		a[i][0] = a[i][0] * sx;
		a[i][1] = a[i][1] * sy;
		a[i][2] = a[i][2] * sz;
	}
	makeCuboid(a);
}

void rotation(float a[8][3]) {

	float theta;
	cin >> theta;

	float tempx, tempy, tempz;
	char axis;
	cin >> axis;

	switch (axis) {
	case 'x': {
		for (int i = 0; i < 8; i++) {
			tempx = a[i][0];
			tempy = a[i][1] * cos(theta) - a[i][2] * sin(theta);
			tempz = a[i][1] * sin(theta) + a[i][2] * cos(theta);
			a[i][0] = tempx;
			a[i][1] = tempy;
			a[i][2] = tempz;
		}
		break;
	}
	case 'y': {
		for (int i = 0; i < 8; i++) {
			tempx = a[i][2] * sin(theta) + a[i][0] * cos(theta);
			tempy = a[i][1];
			tempz = a[i][2] * cos(theta) - a[i][0] * sin(theta);
			a[i][0] = tempx;
			a[i][1] = tempy;
			a[i][2] = tempz;
		}
		break;
	}
	case 'z': {
		for (int i = 0; i < 8; i++) {
			tempx = a[i][0] * cos(theta) - a[i][1] * sin(theta);
			tempy = a[i][0] * sin(theta) + a[i][1] * cos(theta);;
			tempz = a[i][2];
			a[i][0] = tempx;
			a[i][1] = tempy;
			a[i][2] = tempz;
		}
		break;
	}
	}
	makeCuboid(a);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	makeCuboid(p);
	glFlush();
}
void ScanMenu(int id) {
	if (id == 1) {
		cout << "translation" << "\n";
		translate(p);
	}
	else if (id == 2) {
		cout << "scaling" << "\n";
		scale(p);
	}
	else if (id == 3) {
		cout << "rotation" << "\n";
		rotation(p);
	}
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
	glEnable(GL_DEPTH_TEST);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(800.0, 50.0);
	glutCreateWindow("Transforming point");
	glutCreateMenu(ScanMenu);
	glutAddMenuEntry("translate", 1);
	glutAddMenuEntry("scale", 2);
	glutAddMenuEntry("rotation", 3);
	//glutAddMenuEntry("translate about fixed point", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
