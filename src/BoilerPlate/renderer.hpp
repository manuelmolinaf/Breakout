#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_utilities.hpp"
#include "texture_manager.hpp"
#include "engine\math\vector_4.hpp"
#include "engine\math\matrix_4.hpp"
#include "engine\core\game_object.hpp"

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
		void generate_buffers();
		

	private:

		bool mPolygonMode;
		int mWidth;
		int mHeight;

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
