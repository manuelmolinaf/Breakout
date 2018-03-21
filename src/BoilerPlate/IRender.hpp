#pragma once
#ifndef _IRENDER_HPP_
#define _IRENDER_HPP_

namespace engine
{
	namespace core
	{
		class irender
		{
			public:
				virtual ~irender() = default;
				/*
				* PUBLIC FUNCTIONS
				*/
				void virtual Render() = 0;
		};
	}
}

#endif _IRENDER_HPP_


