#include "game.hpp"
#include "../engine/math/vector_4.hpp"

#include<iostream>
namespace game
{
	game::game()
	{
		reset_input_limiter();

		
		mBall.get_component("model_matrix")->get_model_matrix()->translate(engine::math::vector_4(0.3f, -0.4f, 0.0f, 0.0f));

		
	}

	game::~game()
	{
		
	}

	void game::execute()
	{
		mRenderer.initialize_program_id();

		mRenderer.generate_buffers();

		mRenderer.initialize_textures();

		mLevel.load("game/levels/test.txt", 3.12, 0.9);
		
	}

	void game::update()
	{
		update_input();

		if (mInputLimiter != 0)
		{
			mInputLimiter--;
		}

	}

	void game::render()
	{

		mRenderer.render(mPaddle);
		mRenderer.render(mBall);
		//mRenderer.render(mBlock);

		for (int i = 0; i < mLevel.get_level_blocks().size(); i++)
		{
			mRenderer.render(*mLevel.get_level_blocks()[i]);
		}

	}

	void game::update_input()
	{
		if (mInputManager.T_IsPressed() && mInputLimiter == 0)
		{
			mRenderer.toggle_polygon_mode();

			reset_input_limiter();
		}

		if (mInputManager.A_IsPressed() && mPaddle.get_component("position")->get_position().mX > -1.45f)
		{
			mPaddle.translate(engine::math::vector_4(-0.025f, 0.0f, 0.0f, 0.0f));
			
		}

		if (mInputManager.D_IsPressed() && mPaddle.get_component("position")->get_position().mX < 1.45f)
		{
			mPaddle.translate(engine::math::vector_4(0.025f, 0.0f, 0.0f, 0.0f));
		}

	}

	void game::reset_input_limiter()
	{
		mInputLimiter = 10;
	}

	void game::update_window_size(int pWidth, int pHeight)
	{
		mWidth = pWidth;
		mHeight = pHeight;
		mRenderer.update_window_size(pWidth, pHeight);
	}

}