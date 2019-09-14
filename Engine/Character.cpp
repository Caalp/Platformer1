#include "Character.h"

Character::Character(const Surface& surface, Graphics& gfx):
	gfx(gfx)
{
	for (int i = 0; i < 5; i++)
	{
		animation.emplace_back(Animation(0, 96*i, 64, 96*i+96, 4, surface, 0.0903909f, 0.50f));
	}
}

void Character::Draw()
{
	Vec2f CameraSpeed = { 5.0f,0.0f };
	animation[(int)state].Draw(pos+CameraSpeed, gfx);
	Update(0.0f);
}

void Character::Update(float dt)
{
	animation[(int)state].Update(dt);
	
}

void Character::SetDirection(const Vec2f& dir)
{
	
	if (dir.x > 0 && dir.y ==0 )
	{
		 state = ChrState::WalkingRight;
		 pos.x += dir.x;
	}
	else if (dir.x < 0 && dir.y == 0 )
	{
		 state = ChrState::WalkingLeft;
		 pos.x += dir.x;
	}
	else if (dir.y > 0 && dir.x == 0)
	{
		
		pos.y -= dir.y*4;
		
	}
	else if (dir.y < 0 && dir.x == 0)
	{

		pos.y -= dir.y;

	}
}

Vec2f Character::GetPos()
{
	
	return pos;
}

Vec2f Character::SetPos(const Vec2f& v)
{
	pos.x += v.x;
	pos.y += v.y;
	return pos;
}









