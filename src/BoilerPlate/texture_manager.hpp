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
		texture(const char* texture_path, bool pAlpha);

		GLuint load_texture(const char* pTexturePath, bool pAlpha);

		GLuint get_texture();

		void initialize_texture(const char* pTexturePath, bool pAlpha);

	private:

		GLuint mTexture;

	};

}

#endif
