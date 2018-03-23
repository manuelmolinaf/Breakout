#pragma once

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace engine
{

	class texture
	{
	public:

		texture();
		//texture(const char* texture_path);

		GLuint load_texture(const char* texture_path);

		GLuint get_texture();

		void initialize_texture(const char* texture_path);

	private:

		GLuint mTexture;

	};

}

#endif
