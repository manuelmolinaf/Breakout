#pragma once
#ifndef _SOLID_BLOCK_HPP_
#define _SOLID_BLOCK_HPP_

#include "../../engine/core/game_object.hpp"


namespace game
{
	namespace objects
	{
		class solid_block : public engine::core::game_object
		{

		public:
			solid_block();
			~solid_block();


		private:

			void attach_components();

			float vertices[MAX_VERTICES] =
			{
				0.194f,  0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,  //0
				0.194f, -0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,  //1
				-0.194f,-0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,  //2 
				-0.194f, 0.109f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f,  //3
			};

		};

	}

}



#endif