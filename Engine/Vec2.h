#pragma once

template<typename T>
class Vec2
{

public:

	Vec2() = default;
	Vec2(T x, T y) :
		x(x),
		y(y)
	{

	}
	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
	bool operator>(T rhs)
	{
		return x > rhs;
	}
	bool operator < (T rhs)
	{
		return x < rhs;
	}
	Vec2 operator++(int)
	{
		return Vec2(x + 1, y + 1);
	}
	Vec2& operator++()
	{
		this->x += 1;
		this->y += 1;
		return *this;
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vec2& operator+=(const T rhs)
	{
		x += rhs;
		y += rhs;
		return *this;
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(x - rhs.x, y - rhs.y);
	}
	Vec2& operator-=(Vec2& rhs)
	{
		return *this = *this - rhs;
	}
	Vec2 operator*(T rhs) const
	{
		return Vec2(x*rhs, y*rhs);
	}
	Vec2& operator*=(T rhs)
	{
		return *this = *this *rhs;
	}
	float operator*(const Vec2& rhs)
	{
		return (x*rhs.x) + (y*rhs.y);
	}
	/*Vec2& operator/=(Vec2& rhs)
	{
		return *this = *this / rhs;
	}*/
public:
	T x;
	T y;
};
typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;



