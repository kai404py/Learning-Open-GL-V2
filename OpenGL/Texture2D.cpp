#include "Texture2D.h"
#include <fstream>
#include <iostream>

using namespace std;

Texture2D::Texture2D()
{
	_ID = 0;
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

	Upload(data);

	return true;
}

void Texture2D::Upload(unsigned char* data)
{
	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _width, _height, GL_RGB, GL_UNSIGNED_BYTE, data);

	delete[] data;
}

bool Texture2D::LoadBMP(char* path)
{
	ifstream file(path, ios::binary);
	if (!file.is_open())
	{
		cout << "Failed to open BMP file: " << path << endl;
		return false;
	}

	unsigned short bfType;
	unsigned int bfOffBits;
	unsigned int biWidth, biHeight;
	unsigned short biBitCount;

	file.read(reinterpret_cast<char*>(&bfType), 2);
	if (bfType != 0x4D42)
	{
		cout << "Not a valid BMP file: " << path << endl;
		file.close();
		return false;
	}

	file.seekg(10);
	file.read(reinterpret_cast<char*>(&bfOffBits), 4);

	file.seekg(18);
	file.read(reinterpret_cast<char*>(&biWidth), 4);
	file.read(reinterpret_cast<char*>(&biHeight), 4);

	file.seekg(28);
	file.read(reinterpret_cast<char*>(&biBitCount), 2);

	_width = biWidth;
	_height = biHeight;

	int channels = biBitCount / 8;
	int rowSize = ((_width * channels) + 3) & ~3;
	int dataSize = rowSize * _height;

	unsigned char* bmpData = new unsigned char[dataSize];
	file.seekg(bfOffBits);
	file.read(reinterpret_cast<char*>(bmpData), dataSize);
	file.close();

	unsigned char* rgbData = new unsigned char[_width * _height * 3];

	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			int srcRow = (_height - 1 - y) * rowSize;
			int srcOffset = srcRow + x * 3;
			int dstOffset = (y * _width + x) * 3;

			rgbData[dstOffset + 0] = bmpData[srcOffset + 2];
			rgbData[dstOffset + 1] = bmpData[srcOffset + 1];
			rgbData[dstOffset + 2] = bmpData[srcOffset + 0];
		}
	}

	delete[] bmpData;

	Upload(rgbData);

	return true;
}
