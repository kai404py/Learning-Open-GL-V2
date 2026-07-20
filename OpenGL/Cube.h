#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "Structures.h"
#include <iostream>
#include <fstream>

class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;

	Mesh* _mesh;
	Vector3 _position;

	GLfloat _rotation;
	GLfloat _rotationSpeed;
	GLfloat _moveSpeed;

	GLfloat _axisX;
	GLfloat _axisY;
	GLfloat _axisZ;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();
	
	static bool Load(char* path);

	void Draw();
	void Update();
};

