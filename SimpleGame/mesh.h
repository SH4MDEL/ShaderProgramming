#pragma once
#include "stdafx.h"

class Mesh
{
public:
	Mesh();
	~Mesh() = default;

private:
	GLuint m_primitiveTopology;

	GLuint m_vboPosition;
	GLuint m_vboColor;
};

