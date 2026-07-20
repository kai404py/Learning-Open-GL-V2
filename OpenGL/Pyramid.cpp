#include "Pyramid.h"

Pyramid::Pyramid(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
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
		_mesh->Normals != nullptr &&
		_mesh->Indices != nullptr)
	{
		if (_texture != nullptr)
		{
			glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

		if (_mesh->TexCoords != nullptr)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		}

		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		if (_mesh->TexCoords != nullptr)
		{
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	glPopMatrix();
}

void Pyramid::Update()
{
}

Pyramid::~Pyramid()
{
}