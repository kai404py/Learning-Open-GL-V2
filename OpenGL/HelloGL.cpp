#include <cstdlib>
#include <ctime>
#include "HelloGL.h"
#include "MeshLoader.h"

void HelloGL::InitObjects()
{
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);

	for (int i = 0; i < 100; i++)
	{
		objects[i] = new Cube(cubeMesh, texture,
			((rand() % 400) / 10.0f) - 20.0f,
			((rand() % 200) / 10.0f) - 10.0f,
			-(rand() % 1000) / 10.0f);
	}

	for (int i = 100; i < 200; i++)
	{
		objects[i] = new Pyramid(pyramidMesh, nullptr,
			((rand() % 400) / 10.0f) - 20.0f,
			((rand() % 200) / 10.0f) - 10.0f,
			-(rand() % 1000) / 10.0f);
	}
}

void HelloGL::InitGL(int argc, char* argv[])
{
	rotation1 = 0.0f;
	rotation2 = 0.0f;
	rotation3 = 0.0f;

	camera = new Camera();

	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;

	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	// Camera orbit settings
	cameraAngle = 0.0f;
	cameraSpeed = 0.05f;
	cameraRadius = 10.0f;

	camera->eye.x = 0.0f;
	camera->eye.y = 2.0f;
	camera->eye.z = cameraRadius;

	GLUTCallbacks::Init(this);

	// init glut stuff
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Open GL Resub 1");
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
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
}

HelloGL::HelloGL(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	InitGL(argc, argv);
	InitObjects();

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 1000; i++)
	{
		if (objects[i] != nullptr)
		{
			objects[i]->Draw();
		}
	}

	glFlush();
	glutSwapBuffers();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		camera->eye.z -= 0.5f;
	}
	if (key == 's')
	{
		camera->eye.z += 0.5f;
	}
	if (key == 'a')
	{
		camera->eye.y -= 0.5f;
	}
	if (key == 'd')
	{
		camera->eye.y += 0.5f;
	}
	if (key == 'q')
	{
		camera->eye.x -= 0.5f;
	}
	if (key == 'e')
	{
		camera->eye.x += 0.5f;
	}
	if (key == '+')
	{
		cameraSpeed += 0.005f;
	}

	if (key == '-')
	{
		cameraSpeed -= 0.005f;
	}
}

void HelloGL::SpecialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		cameraAngle += cameraSpeed;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		cameraAngle -= cameraSpeed;
	}

	if (key == GLUT_KEY_UP)
	{
		camera->eye.y -= 0.2f;
	}

	if (key == GLUT_KEY_DOWN)
	{
		camera->eye.y += 0.2f;
	}
}

void HelloGL::Update()
{
	glLoadIdentity();

	camera->eye.x = sin(cameraAngle) * cameraRadius;
	camera->eye.z = cos(cameraAngle) * cameraRadius;

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z);


	for (int i = 0; i < 1000; i++)
	{
		if (objects[i] != nullptr)
		{
			objects[i]->Update();
		}
	}

	glutPostRedisplay();
}

HelloGL::~HelloGL(void)
{
	// destry the camera object
	delete camera;
}