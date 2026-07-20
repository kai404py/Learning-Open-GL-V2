#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation1 = 0.0f;
	rotation2 = 0.0f;
	rotation3 = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Open GL Resub 1");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
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

	glPushMatrix();
	glTranslatef(0.833f, 0.9f, 0.0f); // Move the pivot to the origin
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(-0.833f, -0.9f, 0.0f); // Move back

	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(0.9f, 1.0f);
		glVertex2f(1.0f, 0.85f);
		glVertex2f(0.6f, 0.85f);
		glEnd();
	}
	glPopMatrix();

	// Isosceles triangle

	glPushMatrix();
	glTranslatef(-0.8f, 0.6667f, 0.0f); // Move the pivot to the origin
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(0.8f, -0.6667f, 0.0f); // Move back

	glBegin(GL_TRIANGLES);
	{
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.8f, 1.0f);
		glVertex2f(-1.0f, 0.5f);
		glVertex2f(-0.6f, 0.5f);
		glEnd();
	}
	glPopMatrix();

	// Equilateral triangle

	glPushMatrix();
	glTranslatef(0.8f, 0.0833f, 0.0f); // Move the pivot to the origin
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(-0.8f, -0.0833f, 0.0f); // Move back

	glBegin(GL_TRIANGLES);
	{
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(0.8f, 0.25f);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(0.6f, 0.0f);
		glEnd();
	}

	glPopMatrix();

	// Acute triangle

	glPushMatrix();
	glTranslatef(-0.8333f, -0.0833f, 0.0f);
	glRotatef(rotation3, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.8333f, 0.0833f, 0.0f);

	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(-0.9f, 0.25f);
		glVertex2f(-1.0f, -0.25f);
		glVertex2f(-0.6f, -0.25f);
		glEnd();
	}

	glPopMatrix();

	// Right triangle

	glPushMatrix();
	glTranslatef(0.0833f, 0.0833f, 0.0f);
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.0833f, -0.0833f, 0.0f);

	glBegin(GL_TRIANGLES);
	{
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, 0.25f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.25f, 0.0f);
		glEnd();
	}

	glPopMatrix();

	// Obtuse triangle

	glPushMatrix();
	glTranslatef(0.0833f, -0.4167f, 0.0f);
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.0833f, 0.4167f, 0.0f);

	glBegin(GL_TRIANGLES);
	{
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f(0.0f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
	}

	glPopMatrix();

	// Hexagon

	glPushMatrix();
	glTranslatef(-0.6f, -0.65f, 0.0f);
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.6f, 0.65f, 0.0f);

	glBegin(GL_POLYGON);
	{
		glColor4f(0.5f, 0.75f, 0.5f, 1.0f);
		glVertex2f(-0.75f, -0.5f);
		glVertex2f(-0.45f, -0.5f);
		glVertex2f(-0.35f, -0.6f);
		glVertex2f(-0.35f, -0.7f);
		glVertex2f(-0.45f, -0.8f);
		glVertex2f(-0.75f, -0.8f);
		glVertex2f(-0.85f, -0.7f);
		glVertex2f(-0.85f, -0.6f);
		glEnd();
	}

	glPopMatrix();
}

void HelloGL::Update()
{
	rotation1 += 0.5f;

	if (rotation1 >= 360.0f)
		rotation1 = 0.0f;

	rotation2 += 1.5f;

	if (rotation2 >= 360.0f)
		rotation2 = 0.0f;

	rotation3 -= 0.5f;

	if (rotation3 <= -360.0f)
		rotation3 = 0.0f;

	glutPostRedisplay();
}

HelloGL::~HelloGL(void)
{

}