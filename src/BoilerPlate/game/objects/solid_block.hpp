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

		};

	}

}



#endif