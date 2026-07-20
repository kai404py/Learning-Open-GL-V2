#include "OBJ.h"


// Definitions for static members declared in OBJ.h

Vertex* OBJ::indexedVertices = nullptr;
Color* OBJ::indexedColors = nullptr;
GLushort* OBJ::indices = nullptr;

int OBJ::numColors = 0;
int OBJ::numVertices = 0;
int OBJ::numIndices = 0;

OBJ::OBJ(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation = rand() % 360;

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

void OBJ::Draw()
{
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, _axisX, _axisY, _axisZ);
	
	if (indexedVertices != nullptr &&
		indexedColors != nullptr &&
		indices != nullptr)
	{
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < numIndices; i++)
		{
			glColor3fv(&indexedColors[indices[i]].r);
			glVertex3fv(&indexedVertices[indices[i]].x);
		}

		glEnd();
	}
	glPopMatrix();
}

bool OBJ::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);

	if (!inFile.good())
	{
		std::cerr << "Can't open OBJ file " << path << std::endl;
		return false;
	}

	std::vector<Vertex> vertices;
	std::vector<GLushort> objIndices;

	std::string line;

	while (getline(inFile, line))
	{
		std::stringstream ss(line);
		std::string type;

		ss >> type;


		// Vertex position
		if (type == "v")
		{
			Vertex vertex;

			ss >> vertex.x;
			ss >> vertex.y;
			ss >> vertex.z;

			vertices.push_back(vertex);
		}


		// Triangle face
		else if (type == "f")
		{
			GLushort a, b, c;

			ss >> a >> b >> c;

			// OBJ starts at 1, OpenGL starts at 0
			objIndices.push_back(a - 1);
			objIndices.push_back(b - 1);
			objIndices.push_back(c - 1);
		}
	}


	// Copy vertices into static array

	numVertices = vertices.size();

	indexedVertices = new Vertex[numVertices];

	for (int i = 0; i < numVertices; i++)
	{
		indexedVertices[i] = vertices[i];
	}


	// Create default colours

	numColors = numVertices;

	indexedColors = new Color[numColors];

	for (int i = 0; i < numColors; i++)
	{
		indexedColors[i].r = 1.0f;
		indexedColors[i].g = 1.0f;
		indexedColors[i].b = 1.0f;
	}


	// Copy indices

	numIndices = objIndices.size();

	indices = new GLushort[numIndices];

	for (int i = 0; i < numIndices; i++)
	{
		indices[i] = objIndices[i];
	}


	inFile.close();

	return true;
}

void OBJ::Update()
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

		_rotation = rand() % 360;
	}
}

OBJ::~OBJ(void)
{
}