#include "Pyramid.h"

Pyramid::Pyramid(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void Pyramid::Draw()
{
	if (_texture != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	}

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);

	if (_mesh != nullptr &&
		_mesh->Vertices != nullptr &&
		_mesh->Colors != nullptr &&
		_mesh->Indices != nullptr)
	{
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < _mesh->IndexCount; i++)
		{
			glArrayElement(_mesh->Indices[i]);
		}

		glEnd();
	}
	glPopMatrix();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Pyramid::Update()
{
}

Pyramid::~Pyramid()
{
}