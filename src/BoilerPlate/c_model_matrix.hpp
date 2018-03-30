#pragma once

#ifndef _C_MODEL_MATRIX_HPP_
#define _C_MODEL_MATRIX_HPP_

#include "engine\core\component.hpp"
#include "engine\math\matrix_4.hpp"


namespace engine
{
	namespace core
	{
		struct c_texture : engine::core::component
		{
			math::matrix_4 mModelMatrtix;
		};
	}
}


#endif