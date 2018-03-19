
#include "renderer.hpp"


namespace engine
{
	renderer::renderer()
	{
		mPolygonMode = true;
		
	}

	renderer::~renderer()
	{
		glDeleteBuffers(1, &VertexBufferObject);
		glDeleteVertexArrays(1, &VertexArrayObject);
		glDeleteProgram(ProgramID);

	}

	void renderer::initialize_program_id()
	{
		ProgramID = mShaderUtilities.LoadShaders("vertex.glsl", "frag.glsl");
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
		glUseProgram(ProgramID);
		glBindVertexArray(VertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void renderer::load_vertices(/*char* pVertices[]*/)
	{
		// set up vertex data (and buffer(s)) and configure vertex attributes
		// ------------------------------------------------------------------

		float vertices[] = {
			// first triangle
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f,  0.5f, 0.0f, // top left 
			// second triangle
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f, // bottom left
			-0.5f,  0.5f, 0.0f  // top left
		};

		glGenVertexArrays(1, &VertexArrayObject);
		glGenBuffers(1, &VertexBufferObject);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VertexArrayObject);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


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
