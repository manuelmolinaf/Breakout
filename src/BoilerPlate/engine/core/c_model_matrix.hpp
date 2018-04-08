#pragma once
#ifndef _C_MODEL_MATRIX_HPP_
#define _C_MODEL_MATRIX_HPP_

#include "component.hpp"
#include "..\math\matrix_4.hpp"


namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_model_matrix : public core::component
			{
			public:

				c_model_matrix(const std::string& pName);
				math::matrix_4* get_model_matrix();

			private:

				math::matrix_4 mModelMatrix;
			};
		}
	}
}


#endif