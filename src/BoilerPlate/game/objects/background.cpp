#include "background.hpp"

namespace game
{
	namespace objects
	{
		background::background()
		{
			attach_components();
		}

		background::~background()
		{

		}


		void background::attach_components()
		{
			float vertices[36] =
			{
				1.0f,  1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				1.0f, -1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-1.0f,-1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* backgroundVertices = new engine::core::components::c_vertices("vertices", vertices, indices);

			engine::core::components::c_position* backgroundPosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* backgroundModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			engine::core::components::c_object_type* backgroundType = new engine::core::components::c_object_type("object_type", "background");

			attach_component(backgroundVertices);
			attach_component(backgroundPosition);
			attach_component(backgroundModelMatrix);
			attach_component(backgroundType);


		}


	}

}

