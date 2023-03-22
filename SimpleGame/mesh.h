#pragma once
#include "stdafx.h"

class Mesh
{
public:
	Mesh(GLint shaderProgram);
	~Mesh() = default;

	void Render();
	void Update(GLfloat timeElapsed);

private:
	GLint				m_shaderProgram;
	GLuint m_primitiveTopology;

	GLuint m_vboPosition1;
	GLuint m_vboColor1;
	GLuint m_vboPosition2;
	GLuint m_vboColor2;
};

