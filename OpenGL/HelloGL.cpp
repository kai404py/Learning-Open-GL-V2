#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Open GL Resub 1");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon();
	glFlush();
}

void HelloGL::DrawPolygon()
{
	// Self notes
	// first number is X so left right
	// second number is Y so up down
	//so 1, 1 is top right corner
	// and -1, -1 is bottom left corner
	
	// Scalene triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.9, 1);
		glVertex2f(1, 0.85);
		glVertex2f(0.6, 0.85);
		glEnd();
	}

	// Isosceles triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.8, 1);
		glVertex2f(-1, 0.5);
		glVertex2f(-0.6, 0.5);
		glEnd();
	}

	// Equilateral triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(0.8, 0.25);
		glVertex2f(1, 0.0);
		glVertex2f(0.6, 0.0);
		glEnd();
	}

	// acture triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.9, 0.25);
		glVertex2f(-1, -0.25);
		glVertex2f(-0.6, -0.25);
		glEnd();
	}

	// Right triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(0.0, 0.25);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.25, 0.0);
		glEnd();
	}

	// Obtuse triangle
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(-0.25, -0.25);
		glVertex2f(0.0, -0.5);
		glVertex2f(0.5, -0.5);
		glEnd();
	}

	// Hexagon
	glBegin(GL_POLYGON);
	{
		glColor4f(0.5f, 0.75f, 0.5f, 1.0f);
		glVertex2f(-0.75, -0.5);
		glVertex2f(-0.45, -0.5);
		glVertex2f(-0.35, -0.6);
		glVertex2f(-0.35, -0.7);
		glVertex2f(-0.45, -0.8);
		glVertex2f(-0.75, -0.8);
		glVertex2f(-0.85, -0.7);
		glVertex2f(-0.85, -0.6);
		glEnd();
	}
}

HelloGL::~HelloGL(void)
{

}