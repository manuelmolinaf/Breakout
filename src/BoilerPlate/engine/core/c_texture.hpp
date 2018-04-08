#pragma once

#ifndef _C_TEXTURE_HPP_
#define _C_TEXTURE_HPP_

#include "component.hpp"
#include "..\..\texture_manager.hpp"


namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_texture : public engine::core::component
			{
			public:
				c_texture(const std::string& pName, int pTextureIndex);

				int get_texture_index();

			private:

				int mTextureIndex;
			};
		}
	}
}


#endif