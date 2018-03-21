#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "IUpdate.hpp"
#include "IRender.hpp"
#include "UniqueID.hpp"

namespace engine
{
	namespace core
	{
		class component;
		class scene;
		class game_object : public iupdate, public irender, public unique_id
		{
		public:
			template<typename T>
			T* GetComponent()
			{
				// If no components have been attached then return nothing
				if (m_components.size() == 0) return nullptr;
				std::vector<Component*>::iterator comp = m_components.begin();
				for (; comp != m_components.end(); ++comp)
				{
					T* theComponent = dynamic_cast<T*>(*comp);
					if (theComponent)
					{
						return theComponent;
					}
				}
				return nullptr;
			}
		protected:
			std::vector<component*> m_components;
			scene* m_scene;
			std::vector<game_object*> m_children;
			game_object* m_parent;
		};
	}
}

#endif _GAMEOBJECT_HPP_


