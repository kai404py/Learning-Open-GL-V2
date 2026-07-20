#pragma once
#include "Structures.h"
#include <iostream>
#include <fstream>

class MeshLoader
{
public:
	static Mesh* Load(char* path);
};
