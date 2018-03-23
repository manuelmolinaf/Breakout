#include "renderer.hpp"


namespace engine
{
	float vertices[][8] = 
	{
	{ 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, }, //0
	{ 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, }, //1
	{ -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f, }, //2 
	{ -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f }, //3 
	};

	int indices[] = {0,2,3,0,1,2};


	renderer::renderer()
	{
		mPolygonMode = true;

	}

	renderer::~renderer()
	{
		glDeleteBuffers(1, &mVertexBufferObject);
		glDeleteVertexArrays(1, &mVertexArrayObject);
		glDeleteProgram(mProgramID);

	}

	void renderer::initialize_program_id()
	{
		mProgramID = mShaderUtilities.LoadShaders("vertex.glsl", "frag.glsl");
		texture test;
		test.initialize_texture("test.png");
		mTextures[0] = test;
	}

	void renderer::load_textures(const char* pTexturePaths[])
	{
		texture init;
		for (int i = 0; i < sizeof(pTexturePaths); i++)
		{
			init.initialize_texture(pTexturePaths[i]);
			mTextures[i] = init;
		}
	}

	void renderer::render()
	{
		glUseProgram(mProgramID);
		//glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		//glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mTextures[0].get_texture());


		glBindVertexArray(mVertexArrayObject);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0);

	}

	void renderer::load_vertices()
	{
		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------

		glGenVertexArrays(1, &mVertexArrayObject);
		glGenBuffers(1, &mVertexBufferObject);
		glGenBuffers(1, &mElementsBufferObject);

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(mVertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// vertex position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);


		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		//glUseProgram(mProgramID);

		// Remember this needs to be set after the program is activated
		glUniform1i(glGetUniformLocation(mProgramID, "test"), 0);
		
		

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
}