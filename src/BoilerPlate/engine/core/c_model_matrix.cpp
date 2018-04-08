#include "c_model_matrix.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_model_matrix::c_model_matrix(const std::string& pName)
			{
				mName = pName;
				mModelMatrix = math::matrix_4();
			}


			math::matrix_4* c_model_matrix::get_model_matrix()
			{
				return &mModelMatrix;
			}
		}
	}
}