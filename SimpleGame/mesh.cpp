#include "stdafx.h"
#include "mesh.h"

Mesh::Mesh(GLint shaderProgram) : m_shaderProgram{ shaderProgram }, m_primitiveTopology { GL_TRIANGLES }
{
	float verticesPosition1[] = { 1.0f, 1.0f, 0.0f,
								1.0f, -1.0f, 0.0f,
								-1.0f, -1.0f, 0.f };
	float verticesColor1[] = { 1.0f, 0.0f, 0.0f, 1.0f,
									1.0f, 0.0f, 0.0f, 1.0f,
									1.0f, 0.0f, 0.0f, 1.0f };

	// get Buffer Ojbect ID
	glGenBuffers(1, &m_vboPosition1);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboPosition1);	// bind to array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPosition1), verticesPosition1, GL_STATIC_DRAW);
	// glBufferData를 통해 데이터가 GPU로 이동한다.

	glGenBuffers(1, &m_vboColor1);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboColor1);	// bind to array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor1), verticesColor1, GL_STATIC_DRAW); // 

	float verticesPosition2[] = { -1.0f, -1.0f, 0.0f,
									1.0f, 1.0f, 0.0f,
									-1.0f, 1.0f, 0.f };
	float verticesColor2[] = { 1.0f, 0.0f, 0.0f, 1.0f,
									1.0f, 0.0f, 0.0f, 1.0f,
									1.0f, 0.0f, 0.0f, 1.0f };

	glGenBuffers(1, &m_vboPosition2);	// get Buffer Ojbect ID
	glBindBuffer(GL_ARRAY_BUFFER, m_vboPosition2);	// bind to array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPosition2), verticesPosition2, GL_STATIC_DRAW); // 

	glGenBuffers(1, &m_vboColor2);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboColor2);	// bind to array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor2), verticesColor2, GL_STATIC_DRAW); // 
}

void Mesh::Render()
{
	int attributePosition = glGetAttribLocation(m_shaderProgram, "a_position");
	int attributeColor = glGetAttribLocation(m_shaderProgram, "a_color");

	glEnableVertexAttribArray(attributePosition);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboPosition1);
	glVertexAttribPointer(attributePosition, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(attributeColor);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboColor1);
	glVertexAttribPointer(attributeColor, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glEnableVertexAttribArray(attributePosition);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboPosition2);
	glVertexAttribPointer(attributePosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(attributeColor);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboColor2);
	glVertexAttribPointer(attributeColor, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Mesh::Update(GLfloat timeElapsed)
{
}
