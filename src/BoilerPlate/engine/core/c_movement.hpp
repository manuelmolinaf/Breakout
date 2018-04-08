#pragma once
#ifndef _C_MOVEMENT_HPP_
#define _C_MOVEMENT_HPP_

#include "component.hpp"



namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_movement : public core::component
			{
			public:

				c_movement(const std::string& pName, float pMovementValue);

				float* get_movement_value();
				float* get_angle();
			

			private:

				float mMovementValue;
				float mAngleDegree;
				
			};
		}
	}
}


#endif
