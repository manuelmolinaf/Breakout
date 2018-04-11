#include "paddle.hpp"

//
#include "../../engine/core/include_components.hpp"
#include "../../engine/math/vector_4.hpp"
namespace game
{
	namespace objects
	{
		paddle::paddle()
		{
			attach_components();

		}

		paddle::~paddle()
		{

		}


		void paddle::attach_components()
		{

			float vertices[36] =
			{
				0.2f,  0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.2f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.2f,-0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.2f, 0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* paddleVertices = new engine::core::components::c_vertices("vertices", vertices, indices);

			engine::core::components::c_position* paddlePosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* paddleModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			engine::core::components::c_object_type* paddleType = new engine::core::components::c_object_type("object_type", "paddle");

			engine::core::components::c_movement* paddleMovement = new engine::core::components::c_movement("movement", 0.0001f);



			attach_component(paddleVertices);
			attach_component(paddlePosition);
			attach_component(paddleModelMatrix);
			attach_component(paddleType);
			attach_component(paddleMovement);

			this->translate(engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f));
		}


	}

}
