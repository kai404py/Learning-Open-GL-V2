#include "Cube.h"

Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation = rand() % 360;

	_rotationSpeed = ((rand() % 19) + 2) / 10.0f;

	if (rand() % 2)
		_rotationSpeed *= -1.0f;

	_moveSpeed = ((rand() % 11) + 5) / 100.0f;

	_axisX = (rand() % 200 - 100) / 100.0f;
	_axisY = (rand() % 200 - 100) / 100.0f;
	_axisZ = (rand() % 200 - 100) / 100.0f;

	if (_axisX == 0 && _axisY == 0 && _axisZ == 0)
		_axisY = 1.0f;
}

void Cube::Draw()
{
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, _axisX, _axisY, _axisZ);

	if (_mesh != nullptr &&
		_mesh->Vertices != nullptr &&
		_mesh->Colors != nullptr &&
		_mesh->Indices != nullptr)
	{
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < _mesh->IndexCount; i++)
		{
			glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}

		glEnd();
	}
	glPopMatrix();
}

void Cube::Update()
{
	_rotation += _rotationSpeed;
	_position.z += _moveSpeed;

	if (_position.z > 1.0f)
	{
		_position.x = ((rand() % 400) / 10.0f) - 20.0f;
		_position.y = ((rand() % 200) / 10.0f) - 10.0f;
		_position.z = -(rand() % 1000) / 10.0f;

		_moveSpeed = ((rand() % 11) + 5) / 100.0f;

		_rotationSpeed = ((rand() % 19) + 2) / 10.0f;

		if (rand() % 2)
			_rotationSpeed *= -1.0f;

		_axisX = (rand() % 200 - 100) / 100.0f;
		_axisY = (rand() % 200 - 100) / 100.0f;
		_axisZ = (rand() % 200 - 100) / 100.0f;

		if (_axisX == 0 && _axisY == 0 && _axisZ == 0)
			_axisY = 1.0f;

		_rotation = rand() % 360;
	}
}

Cube::~Cube(void)
{
}