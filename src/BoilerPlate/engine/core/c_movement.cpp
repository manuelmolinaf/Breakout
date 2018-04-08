#include "c_movement.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_movement::c_movement(const std::string& pName, float pMovementValue)
			{
				mName = pName;
				mAngleDegree = 0.0f;
				mMovementValue = pMovementValue;
			}

			float* c_movement::get_movement_value()
			{
				return &mMovementValue;
			}

			float* c_movement::get_angle()
			{
				return &mAngleDegree;
			}
		}
	}
}