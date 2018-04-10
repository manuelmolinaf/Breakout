#pragma once

#ifndef _C_TEXTURE_HPP_
#define _C_TEXTURE_HPP_

#include "component.hpp"
#include "texture_manager.hpp"


namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_texture : public engine::core::component
			{
			public:
				c_texture(const std::string& pName, const char* pTexturePath, bool pHasAlpha);

				texture get_object_texture();

			private:

				texture mTexture;
				const char* mTexturePath;
				bool mHasAlpha;
			};
		}
	}
}


#endif