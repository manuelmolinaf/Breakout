#pragma once

#ifndef MAGIC_DRAW_HPP
#define MAGic_DRAW_hpp

#include "renderer.hpp"

class magic_draw
{
	public:

		renderer Renderer;
		texture Texture;

		magic_draw();
		~magic_draw();
};

#endif // !MAGIC_DRAW_HPP