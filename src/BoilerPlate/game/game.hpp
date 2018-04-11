#pragma once

#ifndef GAME_HPP
#define GAME_HPP

#include "../engine/core/renderer.hpp"
#include "../engine/core/input_manager.hpp"
#include "objects/include_game_objects.hpp"
#include "game_level.hpp"

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

		objects::ball mBall;
		objects::block mBlock;
		objects::solid_block mSolidBlock;
		objects::paddle mPaddle;

		std::vector<objects::block> mBlocks;
		int mWidth;
		int mHeight;

		game_level mLevel;

		//void initial
		
		

	};

}

#endif
