#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	void Display();
	void DrawPolygon();
	void Update();

	~HelloGL(void);

private:
	float rotation1;
	float rotation2;
	float rotation3;
};

