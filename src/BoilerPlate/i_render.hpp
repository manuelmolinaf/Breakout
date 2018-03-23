#pragma once
#ifndef _I_RENDER_HPP_
#define _I_RENDER_HPP_

namespace engine
{
	namespace core
	{
		class i_render
		{
		public:
			virtual ~i_render() = default;
			
			void virtual Render() = 0;
		};
	}
}

#endif // !_I_RENDER_HPP_