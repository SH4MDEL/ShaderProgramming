#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
using namespace std;

#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

extern mt19937				g_randomEngine;

namespace Utiles {
	inline GLuint GetRandomUINT(GLuint min, GLuint max)
	{
		uniform_int_distribution<GLuint> dis{ min, max };
		return dis(g_randomEngine);
	}
	inline GLfloat GetRandomFLOAT(GLfloat min, GLfloat max)
	{
		uniform_real_distribution<GLfloat> dis{ min, max };
		return dis(g_randomEngine);
	}
}