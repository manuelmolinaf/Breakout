#pragma once
#ifndef _I_UPDATE_HPP_
#define _I_UPDATE_HPP_

namespace engine
{
	namespace core
	{
		class i_update
		{

		public:
			
			i_update() : m_nUpdates(0) {}
			virtual ~i_update() = default;

		
			void virtual update(double deltaTime) { m_nUpdates++; };

		protected:
		
			int	m_nUpdates;
		};
	}
}

#endif // !_I_UPDATE_HPP_