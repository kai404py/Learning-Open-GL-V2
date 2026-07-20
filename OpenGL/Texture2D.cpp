#include "Texture2D.h"
#include <fstream>
#include <iostream>

using namespace std;

Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	_width = width;
	_height = height;

	unsigned char* data = new unsigned char[_width * _height * 3];

	ifstream file(path, ios::binary);
	if (!file.is_open())
	{
		cout << "Failed to open texture file: " << path << endl;
		delete[] data;
		return false;
	}

	file.read(reinterpret_cast<char*>(data), _width * _height * 3);
	file.close();

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	delete[] data;

	return true;
}
