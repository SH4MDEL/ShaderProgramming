#pragma once
#include "stdafx.h"
#include "object.h"
#include "mesh.h"
#include "timer.h"

class Renderer
{
public:
	Renderer(int windowSizeX, int windowSizeY);
	~Renderer();

	bool IsInitialized();
	void Update();
	void Render();

private:
	void Initialize(int windowSizeX, int windowSizeY);
	void BuildObjects();

	bool ReadFile(char* filename, std::string *target);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void CreateVertexBufferObjects();
	void GetGLPosition(float x, float y, float *newX, float *newY);

private:
	bool m_Initialized = false;
	
	unsigned int m_WindowSizeX = 0;
	unsigned int m_WindowSizeY = 0;

	unique_ptr<Timer>			m_timer;

	vector<shared_ptr<Object>> m_objects;
	GLuint m_shaderProgram;

	GLuint m_VBORect = 0;
	GLuint m_SolidRectShader = 0;
	GLuint m_particleShader = 0;
};

