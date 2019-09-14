#pragma once
#include "Animation.h"
class Character
{
private:
	enum class ChrState
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown

	};
public:
	
	Character(const Surface& surface,Graphics& gfx);
	void Draw();
	void Update(float dt);
	void SetDirection(const Vec2f& dir);
	Vec2f GetPos();
	Vec2f SetPos(const Vec2f& v);
	
private:
	
	std::vector<Animation> animation;
	Graphics& gfx;
	Character::ChrState state = ChrState::WalkingRight;
	Vec2f pos = { 30.0f,480.0f };
	
};