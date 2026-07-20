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

	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);

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

void Pyramid::Update()
{
}

Pyramid::~Pyramid()
{
}