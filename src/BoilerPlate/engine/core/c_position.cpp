#include "c_position.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_position::c_position(const std::string& pName)
			{
				mName = pName;
				mPosition = math::vector_4();
			}

			c_position::c_position(const std::string& pName, math::vector_4 pPosition)
			{
				mName = pName;
				mPosition = pPosition;
			}

			math::vector_4* c_position::get_position()
			{
				return &mPosition;
			}

			void c_position::set_position(math::vector_4 pPosition)
			{
				mPosition = pPosition;
			}
		}
	}
}