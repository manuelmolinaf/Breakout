#pragma once
#ifndef _C_OBJECT_TYPE_HPP_
#define _C_OBJECT_TYPE_HPP_

#include "component.hpp"


namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_object_type : public core::component
			{

			public:

				c_object_type(const std::string& pName, const std::string& pObjectType);

				std::string get_object_type();

			private:

				std::string mObjectType;
				
			};
		}
	}
}


#endif