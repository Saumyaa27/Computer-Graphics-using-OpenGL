#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

void makeTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glFlush();
}

void reflect_X(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(1, -1, 1);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
}

void reflect_Y(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(-1, 1, 1);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();	
}

void reflect_line(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	float m, c, d;
	cout << "enter m and c";
	cin >> m >> c;
	d = (m * m + 1);
	float tempx1, tempx2, tempx3, tempy1, tempy2, tempy3;


	tempx1 = (x1 + (2 * m * y1) + (-2 * c * m))/d;
	tempx2 = (x2 / d) + ((2 * m * y2) / d) + ((-2 * c * m) / d);
	tempx3 = ((x3 + (2 * m * y3) + (-2 * c * m)) / d);

	tempy1 = ((2 * m * x1) / d) + ((((m * m) - 1) * y1) / d) + ((2 * c) / d);
	tempy2 = ((2 * m * x2) / d) + ((((m * m) - 1) * y2) / d) + ((2 * c) / d);
	tempy3 = ((2 * m * x3) / d) + ((((m * m) - 1) * y3) / d) + ((2 * c) / d);
	
	x1 = tempx1;
	x2 = tempx2;
	x3 = tempx3;
	y1 = tempy1;
	y2 = tempy2;
	y3 = tempy3;

	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
}

void shear_x(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float shx;
	cout << " Enter shx";
	cin >> shx;

	x1 = x1 + (shx * y1);
	x2 = x2 + (shx * y2);
	x3 = x3 + (shx * y3);

	glClear(GL_COLOR_BUFFER_BIT);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	
}

void shear_y(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float shy;
	cout << " Enter shy";
	cin >> shy;

	y1 = y1 + (shy * x1);
	y2 = y2 + (shy * x2);
	y3 = y3 + (shy * x3);

	glClear(GL_COLOR_BUFFER_BIT);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();

}

void display()
{
	makeTriangle(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
}
void ScanMenu(int id) {
	if (id == 1) {
		cout << "reflection about X axis" << "\n";
		reflect_X(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
	}
	else if (id == 2) {
		cout << "reflection about Y axis" << "\n";
		reflect_Y(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
	}
	else if (id == 3) {
		cout << "reflection about line y=mx+c" << "\n";
		reflect_line(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
	}
	else if (id == 4) {
		cout << "shear about x axis" << "\n";
		shear_x(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
	}
	else if (id == 5) {
		cout << "shear about y axis" << "\n";
		shear_y(0.0, 0.0, 40.0, 35.0, 60.0, 0.0);
	}
	else
		return;

	}


void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 500, -100.0, 500.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(800.0, 50.0);
	glutCreateWindow("Transforming point");
	glutDisplayFunc(display);
	glutCreateMenu(ScanMenu);
	glutAddMenuEntry("reflection about X axis", 1);
	glutAddMenuEntry("reflection about Y axis", 2);
	glutAddMenuEntry("reflection about line y=mx+c", 3);
	glutAddMenuEntry("shear about x axis", 4);
	glutAddMenuEntry("shear about y axis", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	myinit();
	glutMainLoop();
}
