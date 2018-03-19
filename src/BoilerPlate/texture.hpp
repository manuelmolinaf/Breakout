#pragma once

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

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

class texture
{
	public:
	
	/*PUBLIC FUNCTIONS*/
	GLuint LoadTexture(const char * texture_path);
	GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

	texture();
	~texture();
	
};

#endif //TEXTURE_HPP_INCLUDED