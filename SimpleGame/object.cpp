#include "stdafx.h"
#include "object.h"

Object::Object() : 
	m_shaderProgram{0}, m_position{0.f, 0.f, 0.f, 1.f}, m_color{1.f, 1.f, 1.f, 1.f}, m_scale{1.f}
{}

Object::Object(GLint shaderProgram, Utiles::FLOAT4 position, Utiles::FLOAT4 color, GLfloat scale) :
	m_shaderProgram{ shaderProgram }, m_position{position}, m_color{color}, m_scale{scale}
{}

void Object::Render()
{
	glUniform4f(glGetUniformLocation(m_shaderProgram, "u_trans"), m_position.x, m_position.y, m_position.z, m_position.w);
	glUniform4f(glGetUniformLocation(m_shaderProgram, "u_color"), m_color.x, m_color.y, m_color.z, m_color.w);
	glUniform1f(glGetUniformLocation(m_shaderProgram, "u_scale"), m_scale);

	if (m_mesh) m_mesh->Render();
}

void Object::Update(GLfloat timeElapsed)
{
	if (m_mesh) m_mesh->Update(timeElapsed);
}

void Object::SetMesh(const shared_ptr<Mesh>& mesh)
{
	m_mesh = mesh;
}
