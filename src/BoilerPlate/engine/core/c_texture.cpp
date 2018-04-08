#include "c_texture.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_texture::c_texture(const std::string& pName, int pTextureIndex)
			{
				mName = pName;
				mTextureIndex = pTextureIndex;
			}

			int c_texture::get_texture_index()
			{
				return mTextureIndex;
			}
		}
	}
}