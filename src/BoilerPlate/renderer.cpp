#include "renderer.hpp"



renderer::renderer()
{
	mProgramID = mTexture.LoadShaders("vertex.glsl", "frag.glsl");

	// first triangle

	// top right
	mVertices[0] = 0.5f;
	mVertices[1] = 0.5f;
	mVertices[2] = 0.0f;
	// bottom right
	mVertices[3] = 0.5f;
	mVertices[4] = -0.5f;
	mVertices[5] = 0.0f;
	// top left
	mVertices[6] = -0.5f;
	mVertices[7] = 0.5f;
	mVertices[8] = 0.0f;

	// second triangle

	// bottom right
	mVertices[9] = 0.5f;
	mVertices[10] = -0.5f;
	mVertices[11] = 0.0f;
	// bottom left
	mVertices[12] = -0.5f;
	mVertices[13] = -0.5f;
	mVertices[14] = 0.0f;
	// top left
	mVertices[15] = -0.5f;
	mVertices[16] = 0.5f;
	mVertices[17] = 0.0f;
	

	glGenVertexArrays(1, &mVertexArrayObject);
	glGenBuffers(1, &mVertexBufferObject);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(mVertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);


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




renderer::~renderer()
{
}
