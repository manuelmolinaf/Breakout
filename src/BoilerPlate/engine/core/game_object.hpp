#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "i_update.hpp"
#include "i_render.hpp"
#include "unique_id.hpp"

namespace engine
{
	namespace core
	{
		class component;
		class game_object : public i_update, public i_render, public unique_id
		{
		public:
			
			game_object();
			~game_object();

			//public
			void attach_component(component*);
			void remove_component(component*);
			void add_child(game_object*);
			void remove_child(game_object*);
			void update(double deltaTime) override;
			void render() override;

			//getters
			std::vector<component*>get_components() const { return mComponents; }
			std::vector<game_object*> get_children() const { return mChildren; }
			game_object* get_parent() const { return mParent; }

			template<typename T>
			T* get_component()
			{
				// If no components have been attached then return nothing
				//
				if (mComponents.size() == 0) return nullptr;

				std::vector< component* >::iterator comp = mComponents.begin();
				for (; comp != mComponents.end(); ++comp)
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

			//members
			std::vector<component*>	mComponents;
			std::vector<game_object*> mChildren;
			game_object* mParent;

		};

	}
}

#endif // !_GAMEOBJECT_HPP_