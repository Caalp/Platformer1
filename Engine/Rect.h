#pragma once
#include "Vec2.h"
class Rect
{
public:
	Rect() = default;
	Rect(int xLeft, int xRight, int yTop, int yBottom);
	int GetWidth();
	int GetHeight();
	
public:
	int right;
	int left;
	int top;
	int bottom;
};
