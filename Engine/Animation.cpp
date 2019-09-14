#include "Animation.h"
#include "SpriteEffect.h"


Animation::Animation(int x, int y, int width, int height,int nframe,const Surface & surf, float holdTime, float CurTime):
	surf(surf),
	holdTime(holdTime),
	CurTime(CurTime)
{
	for (int i = 0; i < nframe; i++)
	{
		frames.emplace_back(Rect(x+i*width , (i + 1)*width , y, height));
	}
}

void Animation::Update(float dt)
{
	CurTime += dt;
	if (dt == 0)
	{
		CurFrame = 0;
	}
	while (CurTime >= holdTime)
	{
		Advance();
		CurTime -= holdTime;
	}
	
}

void Animation::Draw(const Vec2f& pos, Graphics & gfx)
{
	gfx.DrawSprite(pos.x, pos.y, frames[CurFrame], { 0,800,0,600 }, surf, SpriteEffect::Chroma{Colors::Red});
}

void Animation::Advance()
{
	if (++CurFrame >= frames.size()-1)
	{
		CurFrame = 0;
	}
}
