#include "renderer.hpp"


namespace engine
{
	float vertices[] =
	{
	  0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
	  0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
	 -0.5f,-0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
	 -0.5f, 0.5f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3 

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
		mProgramID = mShaderUtilities.LoadShaders("engine/shaders/vertex.glsl", "engine/shaders/frag.glsl");

		texture test;
		test.initialize_texture("game/assets/block.png", false);
		mTextures[0] = test;

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

		//FIX
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mTextures[0].get_texture());
		//


		glUseProgram(mProgramID);
		//math::matrix_4 model = math::matrix_4();
		//math::matrix_4 view = math::matrix_4();
		//math::matrix_4 projection = math::matrix_4();

		//model.translate(math::vector_4(0.0f, 0.80f, 0.0f, 1.0f));
		//model.rotateZ(0.0f);

		//view.translate(math::vector_4(0.0f, 0.0f, -3.0f, 1.0f));
		//view.rotateZ(0.0f);
		//projection.make_perspective(35.0f, 0.1f, 100.0f, (float)mHeight / mWidth);

		//// retrieve the matrix uniform locations
		//GLuint modelLoc = glGetUniformLocation(mProgramID, "model");
		//GLuint viewLoc = glGetUniformLocation(mProgramID, "view");
		//GLuint projectionLoc = glGetUniformLocation(mProgramID, "projection");

		//float modelMatrix[16];
		//float viewMatrix[16];
		//float projectionMatrix[16];

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, (void*)0); //limit vector buffering

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
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
}