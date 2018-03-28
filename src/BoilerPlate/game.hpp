#pragma once

#ifndef GAME_HPP
#define GAME_HPP

#include "renderer.hpp"
#include "input_manager.hpp"

namespace game
{

	class game
	{
	public:

		game();
		~game();

		//members

		input_manager mInputManager;



		//functions

		void execute();
		void update();
		void render();
		void update_input();

		


	private:

		//members

		engine::renderer mRenderer;
		int mInputLimiter;

		//functions
		void reset_input_limiter();
		

	};

}

#endif
