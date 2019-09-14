/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Animation.h"
#include "Character.h"
#include "Platform.h"
#include "Star.h"
#include "Camera.h"
#include "Mat2D.h"
#include "Entity.h"
#include "FrameTimer.h"

#include "Simple Physics.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();

	
private:
	MainWindow& wnd;
	Graphics gfx;
	Surface surface;
	Character chr = Character(surface,gfx);
	bool isJumped = true;
	std::vector<std::string> lvl =
	{
		"............................................................",
		"............................................................",
		"........xx..................................................",
		"............xxxx............................................",
		"......x..xx.................................................",
		"............................................................",
		".......xxxxxx..............................xxxxxxx..........",
		".........................................x..................",
		"....................................xxxxx...................",
		"............................................................",
		"............................................................",
		"............................................................",
		"............................................................",
		"............................................................",
		"################################...#####.....################"

	};
	
	//Platform pf = Platform(lvl);
	std::vector<Entity> entities;
	CoordinateTransformer ct;
	Camera cam;
	FrameTimer ft;
	
	Physics::Gravity g;
	bool fall = false;
};