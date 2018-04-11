#pragma once
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <iostream>

#include "objects/include_game_objects.hpp"


namespace game
{
	class game_level
	{
	public:
		//constructor
		game_level();

		void load(const char *pFile, float pLevelWidth, float pLevelHeight);
		std::vector<objects::block*> get_level_blocks();
		//void update_window_size(int pWidth, int pHeight);

	private:

		std::vector<objects::block*> mBlocks;

		void init(std::vector<std::vector<int>> tileData, float levelWidth, float levelHeight);

		int mGameLevelWidth;
		int mGameLevelHeight;

	};
}

#endif