#include "Cube.h"


// Definitions for static members declared in Cube.h

Vertex Cube::indexedVertices[] = {
	{ 1.0f,  1.0f,  1.0f},   // 0
	{-1.0f,  1.0f,  1.0f},   // 1
	{-1.0f, -1.0f,  1.0f},   // 2
	{ 1.0f, -1.0f,  1.0f},   // 3
	{ 1.0f, -1.0f, -1.0f},   // 4
	{ 1.0f,  1.0f, -1.0f},   // 5
	{-1.0f,  1.0f, -1.0f},   // 6
	{-1.0f, -1.0f, -1.0f}    // 7
};

Color Cube::indexedColors[] = {
	{1.0f, 1.0f, 1.0f}, // v0
	{1.0f, 1.0f, 0.0f}, // v1
	{1.0f, 0.0f, 0.0f}, // v2
	{1.0f, 0.0f, 1.0f}, // v3
	{0.0f, 0.0f, 1.0f}, // v4
	{0.0f, 1.0f, 1.0f}, // v5
	{0.0f, 1.0f, 0.0f}, // v6
	{0.0f, 0.0f, 0.0f}  // v7
};

GLushort Cube::indices[] = {
	0,1,2,  2,3,0,   // front
	0,3,4,  4,5,0,   // right
	0,5,6,  6,1,0,   // top
	1,6,7,  7,2,1,   // left
	7,4,3,  3,2,7,   // back
	4,7,6,  6,5,4    // bottom
};

Cube::Cube()
{
	_rotation = 0.0f;
	Vector3 _position = { 0.0f, 0.0f, -5.0f };
}

void Cube::Draw(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(_rotation, 0.0f, 1.0f, 0.0f);
	
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
	glEnd();
	glPopMatrix();
}


void Cube::Update()
{
	_rotation += 0.1f;
}

Cube::~Cube(void)
{
}