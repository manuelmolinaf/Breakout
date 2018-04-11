#include "game_level.hpp"

#include "../engine/math/vector_2.hpp"
#include "../engine/math/vector_3.hpp"
#include "../engine/math/vector_4.hpp"

namespace game
{
	game_level::game_level()
	{

	}


	void game_level::load(const char *pFile, float pLevelWidth, float pLevelHeight)
	{

		// Clear old data
		this->mBlocks.clear();

		// Load from file
		int tileCode;
		//game_level level;
		std::string line;
		std::ifstream fstream(pFile);
		std::vector<std::vector<int>> tileData;
		if (fstream)
		{
			while (std::getline(fstream, line)) // Read each line from level file
			{
				std::istringstream sstream(line);
				std::vector<int> row;
				while (sstream >> tileCode) // Read each word seperated by spaces
				{
					row.push_back(tileCode);
				}

				tileData.push_back(row);
			}
			if (tileData.size() > 0)
				this->init(tileData, pLevelWidth, pLevelHeight);
		}
	}



	void game_level::init(std::vector<std::vector<int>> tileData, float levelWidth, float levelHeight)
	{
		int height = tileData.size();
		int width = tileData[0].size();
		float unitWidth = levelWidth / static_cast<float>(width);
		float unitHeight = levelHeight / height;

		// Initialize level tiles based on tileData		
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				// Check block type from level data (2D level array)
				if (tileData[y][x] == 1)
				{
					objects::solid_block* newBlock = new objects::solid_block();

					newBlock->translate(engine::math::vector_4((unitWidth * x)-1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));

					this->mBlocks.push_back(newBlock);
				}
				else if (tileData[y][x] > 1)
				{
					if (tileData[y][x] == 2)
					{
						objects::block* newBlock = new objects::block(engine::math::vector_3(0.2f, 0.6f, 1.0f));
						newBlock->translate(engine::math::vector_4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
						this->mBlocks.push_back(newBlock);
					}
					else if (tileData[y][x] == 3)
					{
						objects::block* newBlock = new objects::block(engine::math::vector_3(0.0f, 0.7f, 0.0f));
						newBlock->translate(engine::math::vector_4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
						this->mBlocks.push_back(newBlock);
					}
					else if (tileData[y][x] == 4)
					{
						objects::block* newBlock = new objects::block(engine::math::vector_3(0.8f, 0.8f, 0.4f));
						newBlock->translate(engine::math::vector_4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
						this->mBlocks.push_back(newBlock);
					}
					else if (tileData[y][x] == 5)
					{
						objects::block* newBlock = new objects::block(engine::math::vector_3(1.0f, 0.5f, 0.0f));
						newBlock->translate(engine::math::vector_4((unitWidth * x) - 1.365, (unitHeight * -y) + 0.8, 0.0f, 0.0f));
						this->mBlocks.push_back(newBlock);
					}

				}

			}
		}

	}

	std::vector<engine::core::game_object*> game_level::get_level_blocks()
	{
		return mBlocks;
	}


}