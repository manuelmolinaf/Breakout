#pragma once
#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "../../engine/core/game_object.hpp"

namespace game
{
	namespace entities
	{
		class ball : public engine::core::game_object
		{

		public:
			ball();
			~ball();




		private:

			void attach_components();

		};

	}

}



#endif