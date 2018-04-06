#pragma once
#ifndef _C_MODEL_MATRIX_HPP_
#define _C_MODEL_MATRIX_HPP_

#include "component.hpp"
#include "..\math\matrix_4.hpp"


namespace engine
{
	namespace core
	{
		struct c_model_matrix : engine::core::component
		{
			c_model_matrix(std::string pName);
			math::matrix_4 mModelMatrtix;
		};
	}
}


#endif