#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

//
#include "i_update.hpp"
#include "../math/matrix_4.hpp"
#include "texture_manager.hpp"

const int MAX_VERTICES = 36;
const int MAX_INDICES = 6;

namespace engine
{
	namespace core
	{
		class game_object;
		class component : i_update
		{
		public:

			//public
			explicit component();
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			//getters and setters
			void set_owner(game_object* owner) { mOwner = owner; }
			game_object* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }

			//virtual functions
			virtual float* get_vertices() { float emptyVertices[MAX_VERTICES]; return emptyVertices; }
			virtual int* get_indices() { int emptyIndices[MAX_INDICES]; return emptyIndices; }
			virtual texture get_object_texture() { texture emptyTexture; return emptyTexture; }
			virtual void set_position(math::vector_4 pNewPosition) {}
			virtual math::vector_4 *get_position() { return NULL; }
			virtual float* get_movement_value() { return NULL; }
			virtual float* get_angle() { return NULL; }
			virtual math::matrix_4* get_model_matrix() { return NULL; }
		protected:

			//memebers
			game_object*	mOwner;
			std::string 	mName;
		};
	}
}
#endif // !_COMPONENT_HPP_