#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotation1 = 0.0f;
	rotation2 = 0.0f;
	rotation3 = 0.0f;
		
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	GLUTCallbacks::Init(this);

	// init glut stuff
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Open GL Resub 1");
	glEnable(GL_CULL_FACE);
	glEnable(GL_BACK);

	// other setup bits before main loop
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutSpecialFunc(GLUTCallbacks::SpecialKeyboard);

	// set up the projection matrix and viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawPolygon();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation1, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation2, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation3, 0.0f, 0.0f, 1.0f);

	//DrawCube();
	//glutWireTeapot(1.0f);
	//DrawCubeArray();
	DrawIndexedCube();

	glFlush();
	glutSwapBuffers();
}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
		// face v0-v1-v2
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		// face v2-v3-v0
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		// face v0-v3-v4
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		// face v4-v5-v0
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		// face v0-v5-v6 
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		// face v6-v1-v0 
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(1, 1, 1);
		glVertex3f(1, 1, 1);
		// face  v1-v6-v7 
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		// face v7-v2-v1 
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(1, 1, 0);
		glVertex3f(-1, 1, 1);
		// face v7-v4-v3 
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		// face v3-v2-v7 
		glColor3f(1, 0, 1);
		glVertex3f(1, -1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		// face v4-v7-v6 
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(0, 0, 0);
		glVertex3f(-1, -1, -1);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		// face v6-v5-v4 
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, -1);
		glColor3f(0, 1, 1);
		glVertex3f(1, 1, -1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
	glEnd();
}

void HelloGL::DrawCubeArray() 
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) 
		{
			glColor3fv(&colors[i].r);
			glVertex3fv(&vertices[i].x);
		}
	glEnd();
	glPopMatrix();
}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
	glEnd();
	glPopMatrix();
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
	glTranslatef(0.833f, 0.9f, -5.0f); // Move the pivot to the origin
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(-0.833f, -0.9f, -5.0f); // Move back

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
	glTranslatef(-0.8f, 0.6667f, -5.0f); // Move the pivot to the origin
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(0.8f, -0.6667f, -5.0f); // Move back

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
	glTranslatef(0.8f, 0.0833f, -5.0f); // Move the pivot to the origin
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f); // Rotate about the origin
	glTranslatef(-0.8f, -0.0833f, -5.0f); // Move back

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
	glTranslatef(-0.8333f, -0.0833f, -5.0f);
	glRotatef(rotation3, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.8333f, 0.0833f, -5.0f);

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
	glTranslatef(0.0833f, 0.0833f, -5.0f);
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.0833f, -0.0833f, -5.0f);

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
	glTranslatef(0.0833f, -0.4167f, -5.0f);
	glRotatef(rotation2, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.0833f, 0.4167f, -5.0f);

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
	glTranslatef(-0.6f, -0.65f, -5.0f);
	glRotatef(rotation1, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.6f, 0.65f, -5.0f);

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

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		camera->eye.z -= 0.1f;
	}
	if (key == 's')
	{
		camera->eye.z += 0.1f;
	}
	//if (key == 'a')
	//{
	//	rotation1 -= 0.5f;
	//}
	//if (key == 'd')
	//{
	//	rotation1 += 0.5f;
	//}
}

void HelloGL::SpecialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		rotation1 -= 1.0f;
	}

	if (key == GLUT_KEY_DOWN)
	{
		rotation1 += 1.0f;
	}

	if (key == GLUT_KEY_LEFT)
	{
		rotation2 += 1.0f;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		rotation2 -= 1.0f;
	}
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);
	// FPS testing
	//Sleep(10);

	// replaced with keyboard input for rotation1
	// Update rotation angles for rotations 1 2 and 3
	//rotation1 += 0.5f;

	//if (rotation1 >= 360.0f)
	//	rotation1 = 0.0f;

	//rotation2 += 1.5f;
	//
	//if (rotation2 >= 360.0f)
	//	rotation2 = 0.0f;
	//
	//rotation3 -= 0.5f;
	//
	//if (rotation3 <= -360.0f)
	//	rotation3 = 0.0f;

	glutPostRedisplay();
}

HelloGL::~HelloGL(void)
{
	// destry the camera object
	delete camera;
}