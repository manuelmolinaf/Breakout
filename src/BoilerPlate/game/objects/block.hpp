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
			~block();

		private:

			void attach_components();
			float vertices[MAX_VERTICES];


		};

	}

}



#endif