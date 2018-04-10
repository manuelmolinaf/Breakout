#pragma once
#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_

#include "../../engine/core/game_object.hpp"


namespace game
{
	namespace objects
	{
		class paddle : public engine::core::game_object
		{

		public:
			paddle();
			~paddle();


		private:

			void attach_components();

		};

	}

}



#endif