#pragma once

#ifndef SHADER_UTILITIES_HPP
#define SHADER_UTILITIES_HPP

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>



namespace engine
{

	struct shader_utilities
	{
	public:


		shader_utilities();
		
		GLuint LoadShaders(const char* pVertexFilePath, const char* pFragmentFilePath);


	};

}

#endif
