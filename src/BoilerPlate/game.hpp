#pragma once

#ifndef GAME_HPP
#define GAME_HPP

#include "renderer.hpp"
#include "input_manager.hpp"
#include "block.hpp"

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
		void update_window_size(int pWidth, int pHeight);
		


	private:

		//members

		engine::renderer mRenderer;
		int mInputLimiter;

		//functions
		void reset_input_limiter();

		entities::block* mBlock;
		

	};

}

#endif
