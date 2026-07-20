#pragma once
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "SceneObject.h"
#include "Cube.h"
#include "Pyramid.h"
#include "Texture2D.h"
#include <cmath>

#define REFRESHRATE 2

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialKeyboard(int key, int x, int y);
	void InitObjects();
	void InitLighting();
	void InitGL(int argc, char* argv[]);
	float cameraAngle;
	float cameraSpeed;
	float cameraRadius;
	int lastMouseX;
	int lastMouseY;
	bool mousePressed = false;

	~HelloGL(void);

private:
	float rotation1;
	float rotation2;
	float rotation3;
	Camera* camera;
	Vector4* _lightPosition;
	Lighting* _lightData;
	SceneObject* objects[1000] = {};
};
