#pragma once

#ifndef _C_VERTICES_HPP_
#define _C_VERTICES_HPP_

#include "component.hpp"




namespace engine
{
	namespace core
	{
		namespace components
		{
			class c_vertices : public engine::core::component
			{
			public:
				c_vertices(const std::string pName, float pVertices[MAX_VERTICES], int pIndices[MAX_INDICES]);

				float* get_vertices();
				int* get_indices();

			private:

				float mObjectVertices[MAX_VERTICES];
				int mIndices[MAX_INDICES];

			};
		}
	}
}



#endif