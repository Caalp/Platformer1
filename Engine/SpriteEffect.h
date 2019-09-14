#pragma once
#include "Character.h"
#include "Graphics.h" 
namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color c):
			chroma(c)
		{}
		void operator()(Color color, int xDest, int yDest, Graphics& gfx)
		{
			if (color != chroma)
			{
				gfx.PutPixel(xDest, yDest, color);
			}
		}
	private:
		Color chroma;
	};
}