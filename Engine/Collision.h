#pragma once
#include "FrameTimer.h"
#include "Graphics.h"
#include <vector>
class Collision
{
public:
	Collision();
	struct AABB // Axis Aligned Bounding Box
	{
		Vec2f vi;
		Vec2f vf;
		Vec2f min;
		Vec2f max;
		float mass;
		//float restitution;
	};
	struct Circle
	{
		float radius;
		Vec2f position;
	};
	bool AABBvsAABB(AABB a, AABB b);
	float Distance(Vec2f a, Vec2f b);
	bool CirclevsCircleUnoptimized(Circle a, Circle b);
	bool CirclevsCircleOptimized(Circle a, Circle b);
	void ResolveCollision(AABB a , AABB b);
	float DotProduct(const Vec2f& v1, const Vec2f& v2);
	void Draw(Graphics& gfx);
	void Advance();
	void Update(float dt);
	
	
	Vec2f minimum = { 100,150 };
	Vec2f maximum = { 150,200 };
	float dt = 0.5f;
	Vec2f v0 = { 5.0f,0.0f };
	float curTime = 0.11f;
	float holdTime = 0.10f;
	int curFrame = 0;
	std::vector<float> loc;
	FrameTimer ft;
	float m = 0.0f;
};	