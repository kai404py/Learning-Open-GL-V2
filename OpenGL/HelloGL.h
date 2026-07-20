#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 2
#include "Structures.h"

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	void Display();
	void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
	void DrawCube();
	void DrawCubeArray();
	void DrawIndexedCube();

	~HelloGL(void);

private:
	float rotation1;
	float rotation2;
	float rotation3;
	Camera* camera;

};
