#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};
void myinit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

Color getPixel(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &color);
	return color;
}
void setPixel(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void draw_poly() {
	glLineWidth(2);
	glPointSize(1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(250, 250);
	glVertex2i(300, 250);
	glVertex2i(300, 250);
	glVertex2i(250, 150);
	glEnd();
	glFlush();
}
void boundaryFill8(float x, float y, Color fc, Color bc)
{
	Color color;
	color = getPixel(x, y);
	//printf("r:%f,g:%f,b:%f\n", color.r, color.g, color.b);
	if ((color.r != bc.r || color.g != bc.g || color.b != bc.b) && (color.r != fc.r || color.g != fc.g || color.b != fc.b))
	{
		setPixel(x, y, fc);
		boundaryFill8(x + 1, y, fc, bc);
		boundaryFill8(x, y + 1, fc, bc);
		boundaryFill8(x - 1, y, fc, bc);
		boundaryFill8(x, y - 1, fc, bc);
		boundaryFill8(x + 1, y+1, fc, bc);
		boundaryFill8(x-1, y + 1, fc, bc);
		boundaryFill8(x - 1, y-1, fc, bc);
		boundaryFill8(x+1, y - 1, fc, bc);
	}
	return;
}
void onMouseClick(int btn, int state, int x, int y)
{
	y = 500 - y;
	Color bc = { 0.0f, 0.0f, 0.0f };
	Color fc = { 1.0f, 0.0f, 1.0f };
	if (btn == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			boundaryFill8(x, y, fc, bc);
		}
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(draw_poly);
	glutMouseFunc(onMouseClick);
	myinit();
	glutMainLoop();
	return 0;
}