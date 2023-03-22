#pragma once
#include "stdafx.h"
#include "mesh.h"
// 여기서는 유니폼값을 관리하면서 서로 다른 위치에 메쉬를 렌더링한다.

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

