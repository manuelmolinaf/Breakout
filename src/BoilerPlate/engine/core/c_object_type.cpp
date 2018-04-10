#include "c_object_type.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_object_type::c_object_type(const std::string& pName, const std::string& pObjectType)
			{
				mName = pName;
				mObjectType = pObjectType;
			}

			std::string c_object_type::get_object_type()
			{
				return mObjectType;
			}

		}
	}
}