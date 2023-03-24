#include "stdafx.h"
#include "object.h"

Object::Object() : 
	m_shaderProgram{0}, m_position{0.f, 0.f, 0.f, 1.f}, m_velocity{ 0.f, 0.f, 0.f, 0.f }, m_color{1.f, 1.f, 1.f, 1.f}, m_scale{1.f}
{}

Object::Object(GLint shaderProgram, Utiles::FLOAT4 position, Utiles::FLOAT4 velocity, Utiles::FLOAT4 color, GLfloat scale) :
	m_shaderProgram{ shaderProgram }, m_position{ position }, m_velocity{ velocity }, m_color{color}, m_scale{ scale }
{
	m_age = Utiles::GetRandomFLOAT(-10.f, 0.f);
}

void Object::Render()
{
	if (m_age > 0.f) {
		glUniform4f(glGetUniformLocation(m_shaderProgram, "u_trans"), m_position.x, m_position.y, m_position.z, m_position.w);
		glUniform4f(glGetUniformLocation(m_shaderProgram, "u_color"), m_color.x, m_color.y, m_color.z, m_color.w);
		glUniform1f(glGetUniformLocation(m_shaderProgram, "u_scale"), m_scale);

		if (m_mesh) m_mesh->Render();
	}
}

void Object::Update(GLfloat timeElapsed)
{
	m_age += timeElapsed;
	if (m_age < 0) return;
	if (m_age >= m_lifeTime) {
		m_age = 0.f;
		m_position = { 0.f, 0.f, 0.f, 1.f };
		m_velocity.x = Utiles::GetRandomFLOAT(-20.f, 20.f);
		m_velocity.y = Utiles::GetRandomFLOAT(15.f, 35.f);
	}
	m_velocity.y += g_gravity.y * timeElapsed;

	m_position.x += m_velocity.x * timeElapsed;
	m_position.y += m_velocity.y * timeElapsed;

	if (m_mesh) m_mesh->Update(timeElapsed);
}

void Object::SetMesh(const shared_ptr<Mesh>& mesh)
{
	m_mesh = mesh;
}
