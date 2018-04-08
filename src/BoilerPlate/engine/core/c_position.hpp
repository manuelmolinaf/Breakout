#pragma once
#ifndef _C_POSITION_HPP_
#define _C_POSITION_HPP_

#include "component.hpp"
#include "..\math\vector_4.hpp"


namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_position : public core::component
			{
			public:

				c_position(const std::string& pName);
				c_position(std::string& pName, math::vector_4 pPosition);

				math::vector_4* get_position();
				void set_position(math::vector_4 pPosition);

			private:

				math::vector_4 mPosition;
				
			};
		}
	}
}


#endif