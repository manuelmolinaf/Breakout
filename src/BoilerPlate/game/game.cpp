#include "game.hpp"
#include "../engine/math/vector_4.hpp"
namespace game
{
	game::game()
	{
		reset_input_limiter();

		mPaddle.get_component("model_matrix")->get_model_matrix()->translate(engine::math::vector_4(0.0f, -0.9f, 0.0f, 0.0f));
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
		mRenderer.render(mBlock);
	}

	void game::update_input()
	{
		if (mInputManager.T_IsPressed() && mInputLimiter == 0)
		{
			mRenderer.toggle_polygon_mode();

			reset_input_limiter();
		}

	}

	void game::reset_input_limiter()
	{
		mInputLimiter = 10;
	}

	void game::update_window_size(int pWidth, int pHeight)
	{
		mRenderer.update_window_size(pWidth, pHeight);
	}

}