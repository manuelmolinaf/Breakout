#include "c_vertices.hpp"

namespace engine
{
	namespace core
	{
		namespace components
		{
			c_vertices::c_vertices(const std::string pName, float pVertices[MAX_VERTICES], int pIndices[MAX_INDICES])
			{
				mName = pName;

				for (int i = 0; i <MAX_VERTICES; i++)
				{
					mObjectVertices[i] = pVertices[i];
				}

				for (int i = 0; i <MAX_INDICES; i++)
				{
					mIndices[i] = pIndices[i];
				}
				
			}

			float* c_vertices::get_vertices()
			{
				return mObjectVertices;
			}

			int* c_vertices::get_indices()
			{
				return mIndices;
			}

		}
	}
}