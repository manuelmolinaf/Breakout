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
		
		GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);



	};

}

#endif
