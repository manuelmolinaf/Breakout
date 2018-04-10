#include "block.hpp"

//
#include "../../engine/core/include_components.hpp"
#include "../../engine/math/vector_4.hpp"


namespace game
{
	namespace entities
	{
		block::block()
		{
			attach_components();
		}

		block::~block()
		{
			
		}


		void block::attach_components()
		{
	
			float vertices[36] =
			{
				0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.5f,-0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.5f, 0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			int indices[6] = { 0,2,3,0,1,2 };

			engine::core::components::c_vertices* blockVertices = new engine::core::components::c_vertices("vertices", vertices, indices);

			engine::core::components::c_texture* blockTexture = new engine::core::components::c_texture("texture", "game/assets/block.png", false);
			
			engine::core::components::c_position* blockPosition = new engine::core::components::c_position("position", engine::math::vector_4(0.0f, 0.0f, 0.0f, 0.0f));

			engine::core::components::c_model_matrix* blockModelMatrix = new engine::core::components::c_model_matrix("model_matrix");

			attach_component(blockVertices);
			attach_component(blockTexture);
			attach_component(blockPosition);
			attach_component(blockModelMatrix);
			
		}


	}

}

