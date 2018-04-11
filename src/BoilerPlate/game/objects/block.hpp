#pragma once
#ifndef _BLOCK_HPP_
#define _BLOCK_HPP_

#include "../../engine/core/game_object.hpp"
#include "../../engine/math/vector_3.hpp"

namespace game
{
	namespace objects
	{
		class block : public engine::core::game_object
		{

		public:
			block();
			block(engine::math::vector_3 pColor);
			~block();

		private:

			void attach_components();
			

		float vertices[MAX_VERTICES] =
			{
				0.194f,  0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.194f, -0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.194f,-0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.194f, 0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

			//float vertices[MAX_VERTICES] =
			//{
			//	1.0f,  1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
			//	1.0f, -1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
			//	-1.0f,  -1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
			//	-1.0f,  1.0f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			//};
			//


		};

	}

}



#endif