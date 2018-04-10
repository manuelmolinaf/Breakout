#pragma once
#ifndef _BLOCK_HPP_
#define _BLOCK_HPP_

#include "engine/core/game_object.hpp"


namespace game
{
	namespace entities
	{
		class block : public engine::core::game_object
		{

		public:
			block();
			~block();


		private:

			void attach_components();

		};

	}

}



#endif