#include "renderer.hpp"


namespace engine
{
	float vertices[][3] = 
	{
	{  0.0f,  0.0f, 0.0f  }, //0
	{  0.0f,  1.0f, 0.0f  }, //1
	{  1.0f,  0.0f, 0.0f  }, //2 
	{  0.0f, -1.0f, 0.0f  }, //3 
	{ -1.0f,  0.0f, 0.0f  }, //4
	{  1.0f,  1.0f, 0.0f  }, //5
	{  1.0f, -1.0f, 0.0f  }, //6
	{ -1.0f, -1.0f, 0.0f  }, //7
	{ -1.0f,  1.0f, 0.0f  }, //8
	{  0.5f,  0.5f, 0.0f  }, //9
	{  0.5f, -0.5f, 0.0f  }, //10
	{ -0.5f, -0.5f, 0.0f  }, //11
	{ -0.5f,  0.5f, 0.0f  }  //12

	};

	int indices[] = {8, 12, 4, 0, 12, 1, 0, 1, 9, 5, 9, 2, 4, 11, 7, 0, 11, 3, 0, 10, 3, 2, 10, 6};


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
	}

	void renderer::load_textures(const char* pTexturePaths[])
	{
		for (int i = 0; i < sizeof(pTexturePaths); i++)
		{
			mTextures[i] = texture(pTexturePaths[i]);
		}
	}

	void renderer::render()
	{
		glUseProgram(mProgramID);
		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
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


		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			3 * sizeof(float),  // stride
			(void*)0            // array buffer offset
		);


		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


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

}