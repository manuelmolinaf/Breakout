#pragma once
#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "../../engine/core/game_object.hpp"
#include "../../engine/math/matrix_4.hpp"
namespace game
{
	namespace objects
	{
		class ball : public engine::core::game_object
		{

		public:
			ball();
			~ball();

			void ball_update();
			void detach_ball();
			bool get_attached_state();

			bool is_colliding(engine::math::vector_4 pBlockPosition);;

		private:

			void attach_components();

			float mRadius;
			float mSpeed;
			bool mAttached;

		};

	}

}



#endif