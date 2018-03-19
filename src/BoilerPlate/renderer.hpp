#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

#include <string>
#include <vector>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "texture.hpp"

class renderer
{
public:

	GLuint mVertexArrayObject;
	GLuint mVertexBufferObject;
	GLuint mProgramID;
	texture mTexture;
	float mVertices[18];
	bool mPolygonFill;
	
	renderer();
	~renderer();
};

#endif //RENDERER_HPP_INCLUDED