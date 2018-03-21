#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace engine
{
	namespace core
	{
		class unique_id
		{
				/*
				* CTOR / DTOR
				*/
				unique_id();
				unique_id(const unique_id& orig);

				/*
				* OPERATORS
				*/
				unique_id& operator=(const unique_id& orig);

				/*
				* MEMBERS
				*/
				int id;
			protected:
				static int nextID;
		};
	}
}

#endif _UNIQUEID_HPP_


