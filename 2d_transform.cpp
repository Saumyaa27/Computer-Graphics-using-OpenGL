#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <time.h>
using namespace std;

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

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

void translate_origin(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);

	x1 = x1 + 100;
	x2 = x2 + 100;
	x3 = x3 + 100;

	y1 = y1 + 250;
	y2 = y2 + 250;
	y3 = y3 + 250;

	makeTriangle(x1, y1, x2, y2, x3, y3);

	glFlush();
	delay(1500);
}

void translate_inbuilt(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(100, 250, 0);
	makeTriangle(x1, y1, x2, y2, x3, y3);

	glFlush();
	delay(1500);
}

void translate_fixed(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);

	x1 = x1 + 100;
	x2 = x2 + 100;
	x3 = x3 + 100;

	y1 = y1 + 250;
	y2 = y2 + 250;
	y3 = y3 + 250;

	makeTriangle(x1, y1, x2, y2, x3, y3);

	glFlush();
	delay(1500);
}
void rotate_fixed_inbuilt(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float theta = 45.0;
	glTranslatef(-x2, -y2, 0);
	glRotatef(theta, 0, 0, 1.0);
	glTranslatef(x2, y2, 0);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(500);
}

void rotate_origin_inbuilt(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float theta = 45.0;
	glRotatef(theta, 0, 0, 1.0);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void rotate_origin(float x1, float y1, float x2, float y2, float x3, float y3) {
	float theta = 45;
	float tempx,tempy;
	makeTriangle(x1, y1, x2, y2, x3, y3);
	tempx= x1 * cos(theta) - y1 * sin(theta);
	tempy = x1 * sin(theta) + y1 * cos(theta);
	x1 = tempx;
	y1 = tempy;

	tempx = x2 * cos(theta) - y2 * sin(theta);
	tempy = x2 * sin(theta) + y2 * cos(theta);
	x2 = tempx;
	y2 = tempy;

	tempx = x3 * cos(theta) - y3 * sin(theta);
	tempy = x3 * sin(theta) + y3 * cos(theta);
	x3 = tempx;
	y3 = tempy;
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void rotate_fixed(float x1, float y1, float x2, float y2, float x3, float y3) {
	
	glClear(GL_COLOR_BUFFER_BIT);

	x1 = x1 - 100;
	x2 = x2 - 100;
	x3 = x3 - 100;

	y1 = y1 - 250;
	y2 = y2 - 250;
	y3 = y3 - 250;

	float theta = 45;
	float tempx, tempy;
	tempx = x1 * cos(theta) - y1 * sin(theta);
	tempy = x1 * sin(theta) + y1 * cos(theta);
	x1 = tempx;
	y1 = tempy;

	tempx = x2 * cos(theta) - y2 * sin(theta);
	tempy = x2 * sin(theta) + y2 * cos(theta);
	x2 = tempx;
	y2 = tempy;

	tempx = x3 * cos(theta) - y3 * sin(theta);
	tempy = x3 * sin(theta) + y3 * cos(theta);
	x3 = tempx;
	y3 = tempy;
	
	x1 = x1 + 100;
	x2 = x2 + 100;
	x3 = x3 + 100;

	y1 = y1 + 250;
	y2 = y2 + 250;
	y3 = y3 + 250;

	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void scale_origin(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	x1 = x1 * 1.5;
	y1 = y1 * 2;
	x2 = x2 * 1.5;
	y2 = y2 * 2;
	x3 = x3 * 1.5;
	y3 = y3 * 2;
	makeTriangle(x1, y1, x2, y2, x3, y3);

	glFlush();
	delay(1500);
}
void scale_fixed(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	x1 = (x1 - x1) * 1.5 + x1;
	y1 = (y1 - y1) * 2 + y1;
	x2 = (x2 - x1) * 1.5 + x1;
	y2 = (y2 - y1) * 2 + y1;
	x3 = (x3 - x1) * 1.5 + x1;
	y3 = (y3 - y1) * 2 + y1;

	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void scale_origin_inbuilt(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(1.75, 1.5, 0);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void scale_fixed_inbuilt(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-100, -50,0);
	glScalef(1.75, 1.5, 0);
	glTranslatef(100, 50, 0);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(1500);
}

void reflect_X(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(1, -1, 1);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(500);
}

void reflect_Y(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(-1, 1, 1);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(500);
}

void reflect_origin(float x1, float y1, float x2, float y2, float x3, float y3)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(-1, -1, 1);
	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(500);
}

void shear(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glClear(GL_COLOR_BUFFER_BIT);

	x3 = x3 + .5 * y3;

	makeTriangle(x1, y1, x2, y2, x3, y3);
	glFlush();
	delay(500);
}

void display()
{
	makeTriangle(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);

}
void ScanMenu(int id) {
	if (id == 1) {
		cout << "translation about origin" << "\n";
		translate_origin(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 2) {
		cout << "translation about fixed point" << "\n";
		translate_fixed(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 3) {
		cout << "translation using inbuilt function" << "\n";
		translate_inbuilt(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 4) {
		cout << "rotation about origin using inbuilt function" << "\n";
		rotate_origin_inbuilt(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 5) {
		cout << "rotation about fixed point using inbuilt function" << "\n";
		rotate_fixed_inbuilt(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 6) {
		cout << "rotation about origin" << "\n";
		rotate_origin(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 7) {
		cout << "rotation about fixed point" << "\n";
		rotate_fixed(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 8) {
		cout << "scaling about origin" << "\n";
		scale_origin(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 9) {
		cout << "scaling about fixed point" << "\n";
		scale_fixed(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 10) {
		cout << "scaling about origin using inbuilt function" << "\n";
		scale_origin_inbuilt(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 11) {
		cout << "scaling about fixed point using inbuilt function" << "\n";
		scale_fixed_inbuilt(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 12) {
		cout << "reflection about X axis" << "\n";
		reflect_X(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 13) {
		cout << "reflection about Y axis" << "\n";
		reflect_Y(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 14) {
		cout << "reflection about origin" << "\n";
		reflect_Y(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else if (id == 15) {
		cout << "shear" << "\n";
		shear(-0.100, -100.0, 150.0, -50.0, 200.0, 150.0);
	}
	else
		return;

	glutPostRedisplay();
}


void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 499.0, -500.0, 499.0);
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
	glutAddMenuEntry("translate about origin", 1);
	glutAddMenuEntry("translate about fixed point", 2);
	glutAddMenuEntry("translate using inbuilt function", 3);
	glutAddMenuEntry("rotate about origin using inbuilt function", 4);
	glutAddMenuEntry("rotate about fixed point  using inbuilt function", 5);
	glutAddMenuEntry("rotate about origin", 6);
	glutAddMenuEntry("rotate about fixed point", 7);
	glutAddMenuEntry("scale about origin", 8);
	glutAddMenuEntry("scale about fixed point", 9);
	glutAddMenuEntry("scale about origin using inbuilt function", 10);
	glutAddMenuEntry("scale about fixed point using inbuilt function", 11);
	glutAddMenuEntry("reflection about X axis", 12);
	glutAddMenuEntry("reflection about Y axis", 13);
	glutAddMenuEntry("reflection about origin", 14);
	glutAddMenuEntry("shear", 15);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	myinit();
	glutMainLoop();
}
