#include "c_texture.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_texture::c_texture(const std::string& pName)
			{
				mName = pName;
				
			}

			texture c_texture::get_texture()
			{
				mTexture.initialize_texture("game/assets/block.png", false);

				return mTexture;

			}
		}
	}
}