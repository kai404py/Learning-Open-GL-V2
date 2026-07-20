#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Open GL Resub 1");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop;
}

void HelloGL::Display()
{

}

HelloGL::~HelloGL(void)
{

}