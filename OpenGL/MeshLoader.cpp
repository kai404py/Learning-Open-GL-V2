#include "MeshLoader.h"

Mesh* MeshLoader::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return nullptr;
	}

	Mesh* mesh = new Mesh();

	inFile >> mesh->VertexCount;
	mesh->Vertices = new Vertex[mesh->VertexCount];
	for (int i = 0; i < mesh->VertexCount; i++)
	{
		inFile >> mesh->Vertices[i].x >> mesh->Vertices[i].y >> mesh->Vertices[i].z;
	}

	inFile >> mesh->TexCoordCount;
	mesh->TexCoords = new TexCoord[mesh->TexCoordCount];
	for (int i = 0; i < mesh->TexCoordCount; i++)
	{
		inFile >> mesh->TexCoords[i].u >> mesh->TexCoords[i].v;
	}

	inFile >> mesh->NormalCount;
	mesh->Normals = new Vector3[mesh->NormalCount];
	for (int i = 0; i < mesh->NormalCount; i++)
	{
		inFile >> mesh->Normals[i].x >> mesh->Normals[i].y >> mesh->Normals[i].z;
	}

	inFile >> mesh->IndexCount;
	mesh->Indices = new GLushort[mesh->IndexCount];
	for (int i = 0; i < mesh->IndexCount; i++)
	{
		inFile >> mesh->Indices[i];
	}

	inFile.close();
	return mesh;
}