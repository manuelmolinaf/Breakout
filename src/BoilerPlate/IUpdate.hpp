#pragma once
#ifndef _IUPDATE_HPP_
#define _IUPDATE_HPP_

namespace engine
{
	namespace core
	{
		class iupdate
		{
			public:
				/*
				* CTOR // DTOR
				*/
				iupdate() : m_nUpdates(0) {};
				virtual ~iupdate() = default;

				/*
				* PUBLIC FUNCTIONS
				*/
				void virtual Update(double deltaTime) { m_nUpdates++; };
			protected:
				/*
				* MEMBERS
				*/
				int m_nUpdates;
		};
	}
}

#endif _IUPDATE_HPP_


