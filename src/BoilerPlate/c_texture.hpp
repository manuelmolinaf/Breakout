#pragma once

#ifndef _C_TEXTURE_HPP_
#define _C_TEXTURE_HPP_

#include "engine\core\component.hpp"
#include "texture_manager.hpp"


namespace engine
{
	namespace core
	{
		struct c_texture : engine::core::component
		{
			texture mObjectTexture;
		};
	}
}


#endif