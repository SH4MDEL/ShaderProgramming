#pragma once
#include "stdafx.h"
#include "mesh.h"
// ���⼭�� ���������� �����ϸ鼭 ���� �ٸ� ��ġ�� �޽��� �������Ѵ�.

class Object
{
public:
	Object();
	Object(GLint shaderProgram, Utiles::FLOAT4 position, Utiles::FLOAT4 color, GLfloat scale);
	~Object() = default;

	void Render();
	void Update(GLfloat timeElapsed);

	void SetMesh(const shared_ptr<Mesh>& mesh);

private:
	GLint				m_shaderProgram;

	Utiles::FLOAT4		m_position;
	Utiles::FLOAT4		m_color;
	GLfloat				m_scale;

	shared_ptr<Mesh>	m_mesh;
	
};

