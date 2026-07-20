#include "Pyramid.h"

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void Pyramid::Draw()
{
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);

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

void Pyramid::Update()
{
}

Pyramid::~Pyramid()
{
}