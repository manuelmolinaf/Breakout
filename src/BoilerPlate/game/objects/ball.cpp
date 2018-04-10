#include "ball.hpp"

namespace game
{
	namespace objects
	{
		ball::ball()
		{
			attach_components();
		}
		
		ball::~ball()
		{
			
		}


		void ball::attach_components()
		{
			float vertices[36] =
			{
				0.2f,  0.2f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.2f, -0.2f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.2f,-0.2f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.2f, 0.2f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* ballVertices = new engine::core::components::c_vertices("vertices", vertices, indices);

			engine::core::components::c_position* ballPosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* ballModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			engine::core::components::c_object_type* ballType = new engine::core::components::c_object_type("object_type", "ball");

			attach_component(ballVertices);
			attach_component(ballPosition);
			attach_component(ballModelMatrix);
			attach_component(ballType);
		
			
		}


	}

}

