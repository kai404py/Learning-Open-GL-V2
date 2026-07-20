#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16
struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	void Display();
	void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
	void DrawCamera();

	~HelloGL(void);

private:
	float rotation1;
	float rotation2;
	float rotation3;
	Camera* camera;
};
