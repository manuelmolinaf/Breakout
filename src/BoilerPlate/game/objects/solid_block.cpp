#include "solid_block.hpp"

//
#include "../../engine/core/include_components.hpp"

namespace game
{
	namespace objects
	{
		solid_block::solid_block()
		{
			attach_components();
		}

		solid_block::~solid_block()
		{

		}


		void solid_block::attach_components()
		{

			float vertices[36] =
			{
				0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.5f,-0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.5f, 0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* solid_blockVertices = new engine::core::components::c_vertices("vertices", vertices, indices);

			engine::core::components::c_position* solid_blockPosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* solid_blockModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			engine::core::components::c_object_type* solid_blockType = new engine::core::components::c_object_type("object_type", "solid_block");


			attach_component(solid_blockVertices);
			attach_component(solid_blockPosition);
			attach_component(solid_blockModelMatrix);
			attach_component(solid_blockType);
		}


	}

}
