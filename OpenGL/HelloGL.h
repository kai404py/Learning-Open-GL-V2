#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"

#define REFRESHRATE 2

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);

	~HelloGL(void);

private:
	float rotation1;
	float rotation2;
	float rotation3;
	Camera* camera;
	Cube* cube;
};
