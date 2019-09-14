#pragma once
#include "Vec2.h"
template<typename T>
class Mat2D
{
public:
	
	Mat2D& operator=(const Mat2D& rhs)
	{
		memcpy(elements, rhs.elements, sizeof(elements));
		return *this;
	}
	Mat2D operator*(const Mat2D& rhs)
	{
		return
		{
		elements[0][0] * rhs.elements[0][0] + elements[0][1] * rhs.elements[1][0],
		elements[0][0] * rhs.elements[0][1] + elements[0][1] * rhs.elements[1][1],
		elements[1][0] * rhs.elements[0][0] + elements[1][1] * rhs.elements[1][0],
		elements[1][0] * rhs.elements[0][1] + elements[1][1] * rhs.elements[1][1]
		};
	}
	Mat2D& operator*=(const Mat2D& rhs)
	{
		return *this = *this * rhs;
	}
	
public:
	T elements[2][2];
};