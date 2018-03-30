#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_utilities.hpp"
#include "texture_manager.hpp"

const int MAX_TEXTURES = 16;

namespace engine
{

	class renderer
	{
	public:

		renderer();
		~renderer();
		
		void load_textures(const char* pTexturePaths[]);
		void load_vertices();
		void initialize_program_id();
		void render();
		void toggle_polygon_mode();
		

	private:

		bool mPolygonMode;

		GLuint mVertexArrayObject;
		GLuint mVertexBufferObject;
		GLuint mElementsBufferObject;
		GLuint mProgramID;

		shader_utilities mShaderUtilities;

		texture mTextures[MAX_TEXTURES];

		//float vertices[];

	};

}

#endif
