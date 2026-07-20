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

	cube = new Cube();

	GLUTCallbacks::Init(this);

	// init glut stuff
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Open GL Resub 1");
	glEnable(GL_CULL_FACE);
	glEnable(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	// other setup bits before main loop
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutSpecialFunc(GLUTCallbacks::SpecialKeyboard);

	// set up the projection matrix and viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000);
	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//DrawPolygon();

	cube->Draw();

	glFlush();
	glutSwapBuffers();
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
	cube->Update();
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