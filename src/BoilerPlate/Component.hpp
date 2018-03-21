#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

//
#include "IUpdate.hpp"

namespace engine
{
	namespace core
	{
		class game_object;
		class component : iupdate
		{
			public:
				/*
				 * PUBLIC FUNCTIONS
				 */
				explicit component(const std::string& name);
				~component();
				void Update(double deltaTime) override;

				void SetOwner(game_object* owner) { m_owner = owner; }
				game_object* GetOwner() const { return m_owner; }
				std::string GetName() const { return m_name; }
		protected:
			game_object * m_owner;
			std::string m_name;
		};
	}
}

#endif _COMPONENT_HPP_



