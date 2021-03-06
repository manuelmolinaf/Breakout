#include "block.hpp"

//
#include "../../engine/core/include_components.hpp"



namespace game
{
	namespace objects
	{
		block::block()
		{
			attach_components();



		}

		block::block(engine::math::vector_3 pColor)
		{

			for (int i = 3; i < 31; i+=9) 
			{
				vertices[i] = pColor.mX;
				vertices[i + 1] = pColor.mY;
				vertices[i + 2] = pColor.mZ;
			}

			attach_components();
		}

		block::~block()
		{
			
		}


		void block::attach_components()
		{
	

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* blockVertices = new engine::core::components::c_vertices("vertices", vertices, indices);
			
			engine::core::components::c_position* blockPosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* blockModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			engine::core::components::c_object_type* blockType = new engine::core::components::c_object_type("object_type", "block");


			attach_component(blockVertices);
			attach_component(blockPosition);
			attach_component(blockModelMatrix);
			attach_component(blockType);
		}


	}

}

