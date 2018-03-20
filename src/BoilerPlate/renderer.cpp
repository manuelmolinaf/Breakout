#include "renderer.hpp"


namespace engine
{
	float vertices[][3] = 
	{
	{  0.1f,  0.2f, 0.0f  },  // top right 0
	{  0.1f, -0.2f, 0.0f  },  // bottom right 1
	{ -0.1f,  0.2f, 0.0f  },  // top left 2
	{ -0.1f, -0.2f, 0.0f  },  // bottom left 3
	{  0.0f,  0.65f,0.0f  },  //4
	{  0.45f, 0.0f, 0.0f  },  //5
	{  0.0f, -0.65f,0.0f  },  //6
	{ -0.45f, 0.0f, 0.0f  }   //7
	};

	int indices[] = {0, 1, 2, 1, 3, 2, 2, 4, 0, 0, 5, 1, 1, 6, 3, 3, 7, 2 };


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