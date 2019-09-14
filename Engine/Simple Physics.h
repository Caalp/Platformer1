#pragma once
#include "Character.h"

namespace Physics
{
	struct Gravity
	{
	
		void gravity(Character& chr)
		{
			chr.SetPos({ 0.0f,4.81f });
		}
	
		const float g = 9.81f;
	};
}