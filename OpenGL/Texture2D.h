#pragma once
#include "GL/freeglut.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	bool Load(char* path, int width, int height);
	bool LoadBMP(char* path);
	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

private:
	void Upload(unsigned char* data);
	GLuint _ID;
	int _width, _height;
};
