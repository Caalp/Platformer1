#pragma once

#include "Graphics.h"
#include <vector>

class Animation
{

public:
	Animation(int x, int y, int width, int height,int nframe,const Surface& surf, float holdTime,float CurTime);
	void Update(float dt);
	void Draw( const Vec2f& pos, Graphics& gfx);
private:
	void Advance();

private:
	const Surface& surf;
	std::vector<Rect> frames;
	int CurFrame = 0;
	float holdTime;
	float CurTime = 0.0f;

};