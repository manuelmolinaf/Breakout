#pragma once
#ifndef _UNIQUE_ID_HPP_
#define _UNIQUE_ID_HPP_

namespace engine
{
	namespace core
	{
		class unique_id
		{
		public:
			
			unique_id();
			unique_id(const unique_id& orig);

			
			unique_id& operator=(const unique_id& orig);

			
			int id;
		protected:
			static int nextID;
		};

	}
}

#endif // !_UNIQUEID_HPP_