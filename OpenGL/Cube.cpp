#include <cstdlib>
#include "Cube.h"

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation = (GLfloat)(rand() % 360);

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
	if (_texture != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	}

	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, _axisX, _axisY, _axisZ);

	if (_mesh != nullptr &&
		_mesh->Vertices != nullptr &&
		_mesh->Colors != nullptr &&
		_mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
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

		_rotation = (GLfloat)(rand() % 360);
	}
}

Cube::~Cube(void)
{
}