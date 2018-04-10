#include "renderer.hpp"

#include <iostream>
namespace engine
{


	renderer::renderer()
	{
		mPolygonMode = true;
		mObjectIndex = 0;
	}

	renderer::~renderer()
	{
		glDeleteBuffers(1, &mVertexBufferObject);
		glDeleteVertexArrays(1, &mVertexArrayObject);
		glDeleteProgram(mProgramID);

	}

	void renderer::initialize_program_id()
	{
		mProgramID = mShaderUtilities.LoadShaders("engine/shaders/vertex.glsl", "engine/shaders/frag.glsl");

	}



	void renderer::render(engine::core::game_object& pGameObject)
	{
		
		load_vertices(pGameObject);
		mvp(*pGameObject.get_component("model_matrix")->get_model_matrix());
		
		glUseProgram(mProgramID);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);


		bind_texture(pGameObject);
		

		glDrawElements(GL_TRIANGLES, SIZE_OF_INDICES, GL_UNSIGNED_INT, (void*)0); //limit vector buffering

	}

	void renderer::generate_buffers()
	{
		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);
		glGenBuffers(1, &mElementsBufferObject);
	}

	void renderer::mvp(math::matrix_4 pModelMatrix)
	{
		math::matrix_4 model = math::matrix_4();
		math::matrix_4 view = math::matrix_4();
		math::matrix_4 projection = math::matrix_4();

		model.translate(math::vector_4(0.0f, 0.80f, 0.0f, 1.0f));
		model.rotateZ(0.0f);

		view.translate(math::vector_4(0.0f, 0.0f, -3.0f, 1.0f));
		view.rotateZ(0.0f);
		projection.make_perspective(35.0f, 0.1f, 100.0f, (float)mHeight / mWidth);

		// retrieve the matrix uniform locations
		GLuint modelLoc = glGetUniformLocation(mProgramID, "model");
		GLuint viewLoc = glGetUniformLocation(mProgramID, "view");
		GLuint projectionLoc = glGetUniformLocation(mProgramID, "projection");

		float modelMatrix[16];
		float viewMatrix[16];
		float projectionMatrix[16];

		pModelMatrix.assign_matrix(modelMatrix);

		view.assign_matrix(viewMatrix);
		projection.assign_matrix(projectionMatrix);

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix);

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix);
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix);

		float resolution[] = { static_cast<float>(1136), static_cast<float>(640) };
	}

	void renderer::load_vertices(engine::core::game_object& pGameObject)
	{

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, SIZE_OF_VERTICES, pGameObject.get_component("vertices")->get_vertices(), GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, SIZE_OF_INDICES, pGameObject.get_component("vertices")->get_indices(), GL_STATIC_DRAW);

		// vertex position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);


		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		if (mPolygonMode)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
	}

	void renderer::toggle_polygon_mode()
	{
		mPolygonMode = !mPolygonMode;
	}

	void renderer::initialize_textures()
	{
		texture textureInitializer;
		
		textureInitializer.initialize_texture("game/assets/block.png", false);
		mTextures[BLOCK_TEXTURE_INDEX] = textureInitializer;

		textureInitializer.initialize_texture("game/assets/solid_block.png", false);
		mTextures[SOLID_BLOCK_TEXTURE_INDEX] = textureInitializer;

		textureInitializer.initialize_texture("game/assets/ball.png", true);
		mTextures[BALL_TEXTURE_INDEX] = textureInitializer;

		textureInitializer.initialize_texture("game/assets/paddle.png", true);
		mTextures[PADDLE_TEXTURE_INDEX] = textureInitializer;

	}


	void renderer::bind_texture(engine::core::game_object& pGameObject)
	{
		if ((pGameObject.get_component("object_type")->get_object_type()) == "block")
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTextures[BLOCK_TEXTURE_INDEX].get_texture());
		}
		else if (pGameObject.get_component("object_type")->get_object_type() == "solid_block")
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTextures[SOLID_BLOCK_TEXTURE_INDEX].get_texture());
		}
		else if(pGameObject.get_component("object_type")->get_object_type() == "ball")
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTextures[BALL_TEXTURE_INDEX].get_texture());
		}
		else if (pGameObject.get_component("object_type")->get_object_type() == "paddle")
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, mTextures[PADDLE_TEXTURE_INDEX].get_texture());
		}
	}

	


	void renderer::update_window_size(int pWidth, int pHeight)
	{
		mWidth = pWidth;
		mHeight = pHeight;
	}
}