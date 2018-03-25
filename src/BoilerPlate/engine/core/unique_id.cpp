#include "unique_id.hpp"

namespace engine
{
	namespace core
	{
		int unique_id::nextID = 0;

		unique_id::unique_id()
		{
			id = ++nextID;
		}

		unique_id::unique_id(const unique_id& orig)
		{
			id = orig.id;
		}

		unique_id& unique_id::operator=(const unique_id& orig)
		{
			id = orig.id;
			return(*this);
		}
	}
}