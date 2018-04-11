#include<iostream>

#include "game.hpp"
#include "../engine/math/vector_4.hpp"
namespace game
{
	game::game()
	{
		reset_input_limiter();
		mLevel.load("game/levels/test.txt", 3.12, 0.9);

		for (int i = 0; i < mLevel.get_level_blocks().size(); i++)
		{
			mBlocks.push_back(mLevel.get_level_blocks()[i]);
		}
		
	}

	game::~game()
	{
		
	}

	void game::execute()
	{
		mRenderer.initialize_program_id();

		mRenderer.generate_buffers();
		mRenderer.initialize_textures();
		
		
	}

	void game::update()
	{

		mBall.ball_update();
		
		update_input();

		if (mInputLimiter != 0)
		{
			mInputLimiter--;
		}

		for (int i = 0; i < mBlocks.size(); i++)
		{
			if (mBall.is_colliding(mBlocks[i]->get_component("position")->get_position()))
			{
				mBlocks.erase(mBlocks.begin() + i);
			}
		}



	}

	void game::render()
	{
		mRenderer.render(mBackground);
		mRenderer.render(mPaddle);

		for (int i = 0; i < mBlocks.size(); i++)
		{
			mRenderer.render(*mBlocks[i]);
		}

		mRenderer.render(mBall);

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

			if (mBall.get_attached_state())
			{
				mBall.translate(engine::math::vector_4(-0.025f, 0.0f, 0.0f, 0.0f));
			}
			
		}

		if (mInputManager.D_IsPressed() && mPaddle.get_component("position")->get_position().mX < 1.45f)
		{
			mPaddle.translate(engine::math::vector_4(0.025f, 0.0f, 0.0f, 0.0f));

			if (mBall.get_attached_state())
			{
				mBall.translate(engine::math::vector_4(0.025f, 0.0f, 0.0f, 0.0f));
			}

		}

		if (mInputManager.SPACE_IsPressed() && mInputLimiter == 0)
		{
			mBall.detach_ball();
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