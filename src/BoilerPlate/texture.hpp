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
		texture(const char* texture_path);

		GLuint LoadTexture(const char* texture_path);

		GLuint get_texture();

	private:

		GLuint mTexture;

	};

}

#endif
