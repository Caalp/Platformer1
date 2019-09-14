#pragma once
#include "Drawable.h"
class CoordinateTransformer

{
public:
	CoordinateTransformer(Graphics& gfx) :
		gfx(gfx)
	{

	}
	void Draw(Drawable& drawable)
	{
		const Vec2f offset = {0.0f,0.0f};
		drawable.ScaleIndependent(1.0f, -1.0f);
		drawable.Translate(offset);
		drawable.Render(gfx);
	}
private:
	
	Graphics& gfx;
};