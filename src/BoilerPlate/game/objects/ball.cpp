#include "ball.hpp"

#include <algorithm>
namespace game
{
	namespace objects
	{
		ball::ball()
		{
			attach_components();

			mAttached = true;
		}
		
		ball::~ball()
		{
			
		}

		void ball::ball_update(float pDeltaTime, float pWidth)
		{
			if (!mAttached)
			{
				translate(engine::math::vector_4(0.0f, 0.02f, 0.0f, 0.0f));
			}
		}

		bool ball::is_colliding(engine::math::vector_4 pBlockPosition)
		{
			float nearestX = std::max(pBlockPosition.mX, std::min(get_component("position")->get_position().mX, pBlockPosition.mX + 0.388f));
			float nearestY = std::max(pBlockPosition.mY, std::min(get_component("position")->get_position().mY, pBlockPosition.mY + 0.218f));

			float deltaX = get_component("position")->get_position().mX - nearestX;
			float deltaY = get_component("position")->get_position().mY - nearestY;

			return (deltaX * deltaX + deltaY * deltaY) < (0.05f * 0.05f);
		}

		void ball::detach_ball()
		{
			mAttached = false;
		}

		bool ball::get_attached_state()
		{
			return mAttached;
		}

		void ball::attach_components()
		{
			float vertices[36] =
			{
				0.03f,  0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.03f,-0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.03f, 0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
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

			translate(engine::math::vector_4(0.0f,-0.85f,0.0f,0.0f));
		
			
		}


	}

}

