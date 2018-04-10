#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_utilities.hpp"
#include "texture_manager.hpp"
#include"../../game/objects/block.hpp"
#include "game_object.hpp"

const int MAX_TEXTURES = 16;



const GLuint SIZE_OF_VERTICES = 144;
const GLuint SIZE_OF_INDICES = 24;

const int BLOCK_TEXTURE_INDEX = 0;
const int SOLID_BLOCK_TEXTURE_INDEX = 1;
const int BALL_TEXTURE_INDEX = 2;
const int PADDLE_TEXTURE_INDEX = 3;

namespace engine
{

	class renderer
	{
	public:

		renderer();
		~renderer();
		
		void initialize_program_id();
		void render(engine::core::game_object& pGameObject);
		void toggle_polygon_mode();
		void generate_buffers();
		void update_window_size(int pWidth, int pHeight);
		void initialize_textures();
		
	private:

		bool mPolygonMode;
		int mWidth;
		int mHeight;
		int mObjectIndex;

		GLuint mVertexArrayObject;
		GLuint mVertexBufferObject;
		GLuint mElementsBufferObject;
		GLuint mProgramID;

		shader_utilities mShaderUtilities;

		texture mTextures[MAX_TEXTURES];

		void bind_texture(engine::core::game_object& pGameObject);
		void load_vertices(engine::core::game_object& pGameObject);
		void mvp(math::matrix_4 pModelMatrix);

	};

}

#endif
