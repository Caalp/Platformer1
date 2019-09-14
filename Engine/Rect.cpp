#include "Rect.h"


Rect::Rect(int xLeft, int xRight, int yTop, int yBottom):
	right(xRight),
	left(xLeft),
	top(yTop),
	bottom(yBottom)
{
}

int Rect::GetWidth()
{
	return right - left;
}

int Rect::GetHeight()
{
	return bottom - top;
}
