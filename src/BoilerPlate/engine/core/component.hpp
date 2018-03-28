#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

//
#include "i_update.hpp"

namespace engine
{
	namespace core
	{
		class game_object;
		class component : i_update
		{
		public:

			//public
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			//getters
			void set_owner(game_object* owner) { mOwner = owner; }
			game_object* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }
		protected:

			//memebers
			game_object*	mOwner;
			std::string 	mName;
		};
	}
}
#endif // !_COMPONENT_HPP_