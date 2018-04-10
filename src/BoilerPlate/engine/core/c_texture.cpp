#include "c_texture.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_texture::c_texture(const std::string& pName, const char* pTexturePath, bool pHasAlpha)
			{
				mName = pName;
				mTexturePath = pTexturePath;
				mHasAlpha = pHasAlpha;
			}

			texture c_texture::get_object_texture()
			{
				mTexture.initialize_texture(mTexturePath, mHasAlpha);

				return mTexture;

			}
		}
	}
}