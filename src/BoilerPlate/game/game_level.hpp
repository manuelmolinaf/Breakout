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
		std::vector<engine::core::game_object*> get_level_blocks();
		

	private:

		std::vector<engine::core::game_object*> mBlocks;

		void init(std::vector<std::vector<int>> tileData, float levelWidth, float levelHeight);

		int mGameLevelWidth;
		int mGameLevelHeight;

	};
}

#endif