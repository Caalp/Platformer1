#include "Collision.h"


Collision::Collision()
{
	
	
		/*while (dt < 4)
		{
			dt += 0.1;
			m = m + v0.x*dt;
			loc.emplace_back(m);
		}
	*/
}

bool Collision::AABBvsAABB(AABB a, AABB b)
{
	if (a.max.x < b.min.x || a.min.x < b.max.x) return false;
	if (a.max.y < b.min.y || a.min.y < b.max.y) return false;

	return true;
}

float Collision::Distance(Vec2f a, Vec2f b)
{
	return sqrt(((a.x-b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}

bool Collision::CirclevsCircleUnoptimized(Circle a, Circle b)
{
	float r = a.radius + b.radius;
	return r < Distance(a.position, b.position);
}

bool Collision::CirclevsCircleOptimized(Circle a, Circle b)
{
	float r = a.radius + b.radius;
	r *= r;
	return r < ((a.position.x + b.position.x) *(a.position.x + b.position.x)) + ((a.position.y + b.position.y) * (a.position.y + b.position.y));
	
}

void Collision::ResolveCollision(AABB a, AABB b)
{
	

}

float Collision::DotProduct(const Vec2f & v1, const Vec2f & v2)
{
	return (v1.x + v2.x) + (v1.y + v2.y);
}

void Collision::Draw(Graphics& gfx)
{
	//gfx.DrawRect(m , 100.0f, minimum, maximum, Colors::Blue);
	Update(0.039f);
}

void Collision::Advance()
{
	
	
	if (++m > Graphics::ScreenWidth-300)
	{
		
		
		/*	loc.clear();
		curFrame = 0;

			v0.x = -5.0f;
			dt = 0.1f;
	
		
		while (dt < 3)
		{
			dt += 0.1;
			
			m += v0.x*dt;
			loc.emplace_back(m);
		}*/
		
	
	}
}

void Collision::Update(float dt)
{
	//if (loc[curFrame] < 420.0f)
	//{
		curTime += dt;
		if (dt == 0)
		{
			curFrame = 35;
		}

		while (curTime >= holdTime)
		{
			Advance();
			curTime -= holdTime;
		}
	//}
}
