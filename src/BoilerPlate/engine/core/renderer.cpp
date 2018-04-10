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

	void renderer::render_objects()
	{

		for (int i = 0; i < mObjects.size() ; i++)
		{
			render(mObjects[i]);
		}
		//render(mObjects[0]);
		//render(mObjects[1]);
	}


	void renderer::render(engine::core::game_object* pGameObject)
	{
		
		load_vertices(pGameObject);
		
		glUseProgram(mProgramID);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, pGameObject->get_component("texture")->get_object_texture().get_texture());
		

		glDrawElements(GL_TRIANGLES, SIZE_OF_INDICES, GL_UNSIGNED_INT, (void*)0); //limit vector buffering

	}

	void renderer::generate_buffers()
	{
		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);
		glGenBuffers(1, &mElementsBufferObject);
	}

	void renderer::load_vertices(engine::core::game_object* pGameObject)
	{

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, SIZE_OF_VERTICES, pGameObject->get_component("vertices")->get_vertices(), GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, SIZE_OF_INDICES, pGameObject->get_component("vertices")->get_indices(), GL_STATIC_DRAW);

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

	void renderer::update_window_size(int pWidth, int pHeight)
	{
		mWidth = pWidth;
		mHeight = pHeight;
	}

	void renderer::add_object(engine::core::game_object* pGameObject)
	{
		mObjects.push_back(pGameObject);
		//mObjects[mObjectIndex] = pGameObject;

		mObjectIndex++;
	}
}