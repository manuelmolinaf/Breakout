#pragma once

#ifndef _C_VERTICES_HPP_
#define _C_VERTICES_HPP_

#include "engine\core\component.hpp"

const int MAX_VERTICES = 36;
const int MAX_INDICES = 6;


namespace engine
{
	namespace core
	{
		struct c_vertices : engine::core::component
		{

		public:

			float mObjectVertices[MAX_VERTICES];
			int mIndices[MAX_INDICES];

			
		
		};
	}
}



#endif