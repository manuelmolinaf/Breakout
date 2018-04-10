#include "renderer.hpp"

#include <iostream>
namespace engine
{


	renderer::renderer()
	{
		mPolygonMode = true;
		//mObjects.push_back(new game::entities::block());

		//add_object(new game::entities::block());
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

	void renderer::load_textures(const char* pTexturePaths[])
	{
		texture init;
		for (int i = 0; i < sizeof(pTexturePaths); i++)
		{
			init.initialize_texture(pTexturePaths[i], false);
			mTextures[i] = init;
		}
	}

	void renderer::render()
	{
		
		load_vertices();
		
		
		glUseProgram(mProgramID);
		

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mObjects[0]->get_component("texture")->get_texture().get_texture());

		//std::cout << mObjects[0]->get_component("vertices")->get_vertices()[0];
		

		glDrawElements(GL_TRIANGLES, SIZE_OF_INDICES, GL_UNSIGNED_INT, (void*)0); //limit vector buffering

	}

	void renderer::generate_buffers()
	{
		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);
		glGenBuffers(1, &mElementsBufferObject);
	}

	void renderer::load_vertices()
	{

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------


		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, SIZE_OF_VERTICES, mObjects[0]->get_component("vertices")->get_vertices(), GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, SIZE_OF_INDICES, mObjects[0]->get_component("vertices")->get_indices(), GL_STATIC_DRAW);

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


		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	void renderer::toggle_polygon_mode()
	{
		if (mPolygonMode)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			mPolygonMode = false;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			mPolygonMode = true;
		}
	}

	void renderer::update_window_size(int pWidth, int pHeight)
	{
		mWidth = pWidth;
		mHeight = pHeight;
	}

	void renderer::add_object(engine::core::game_object* pGameObject)
	{
		mObjects.push_back(pGameObject);
	}
}