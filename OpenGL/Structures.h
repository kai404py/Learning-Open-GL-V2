#pragma once
#include "GL/freeglut.h"

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

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Vector4
{
	GLfloat x, y, z, w;
};

struct Lighting
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

struct Material
{
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
};

struct Mesh
{
	Vertex* Vertices;
	TexCoord* TexCoords;
	Vector3* Normals;
	GLushort* Indices;
	int VertexCount, TexCoordCount, NormalCount, IndexCount;
};