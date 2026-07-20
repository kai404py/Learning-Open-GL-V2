#pragma once
#include "SceneObject.h"

class Cube : public SceneObject
{
private:
	Vector3 _position;

	GLfloat _rotation;
	GLfloat _rotationSpeed;
	GLfloat _moveSpeed;

	GLfloat _axisX;
	GLfloat _axisY;
	GLfloat _axisZ;

public:
	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

