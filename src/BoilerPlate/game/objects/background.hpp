#pragma once
#ifndef _BACKGROUND_HPP_
#define _BACKGROUND_HPP_

#include "../../engine/core/game_object.hpp"

namespace game
{
	namespace objects
	{
		class background : public engine::core::game_object
		{

		public:
			background();
			~background();




		private:

			void attach_components();

		};

	}

}



#endif