#include "game.hpp"

namespace game
{
	game::game()
	{
		reset_input_limiter();
		mBlock = new entities::block();
	}

	game::~game()
	{

	}

	void game::execute()
	{
		mRenderer.initialize_program_id();
		mRenderer.generate_buffers();
		mRenderer.add_object(mBlock);
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
		/*mRenderer.render(mBlock.get_component("vertices")->get_vertices(), mBlock.get_component("block_vertices")->get_indices(),
						 mBlock.get_component("block_texture")->get_texture_index(), *mBlock.get_component("block_model_matrix")->get_model_matrix());*/

		mRenderer.render();
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