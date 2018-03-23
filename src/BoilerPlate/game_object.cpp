#include "game_object.hpp"

// STL
#include <algorithm>

// 
#include "component.hpp"

namespace engine
{
	namespace core
	{
		game_object::game_object()
			: m_parent(nullptr)
		{}

		game_object::~game_object()
		{
			// Delete all attached components
			//
			while (!m_components.empty()) delete m_components.back(), m_components.pop_back();

			// Delete all attached children
			//
			while (!m_children.empty()) delete m_children.back(), m_children.pop_back();
		}

		void game_object::AttachComponent(component* component)
		{
			component->set_owner(this);
			m_components.push_back(component);
		}

		void game_object::RemoveComponent(component* component)
		{
			m_components.erase(
				remove(m_components.begin(), m_components.end(), component), m_components.end()
			);

			delete component;
		}

		void game_object::AddChild(game_object* child)
		{
			// Set the child parent
			child->m_parent = this;

			// 
			m_children.push_back(child);
		}

		void game_object::RemoveChild(game_object* child)
		{
			m_children.erase(
				remove(m_children.begin(), m_children.end(), child), m_children.end()
			);

			delete child;
		}

		void game_object::update(double deltaTime)
		{
			// Update components
			//
			std::vector< component* >::iterator comp = m_components.begin();
			for (; comp != m_components.end(); ++comp)
			{
				(*comp)->update(deltaTime);
			}

			// Update children
			//
			std::vector< game_object* >::iterator child = m_children.begin();
			for (; child != m_children.end(); ++child)
			{
				(*child)->update(deltaTime);
			}

			// Base class function call
			//
			i_update::update(deltaTime);
		}

		void game_object::Render()
		{
			//if ((m_nUpdates % 60) == 0)
			{
				// Render children
				//
				std::vector< game_object* >::iterator child = m_children.begin();
				for (; child != m_children.end(); ++child)
				{
					(*child)->Render();
				}
			}
		}
	}
}