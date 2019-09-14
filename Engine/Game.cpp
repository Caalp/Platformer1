/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	surface("boi.bmp"),
	ct(gfx),
	cam(ct)
	
	

{
	
	//entities.emplace_back(Star::Make(100.0f, 50.0f, 5), Vec2f{ 460.f,0.0f });
	/*entities.emplace_back(Star::Make(150.0f, 50.0f, 5), Vec2f{ 150.f,330.0f });
	entities.emplace_back(Star::Make(100.0f, 50.0f, 5), Vec2f{ 250.f,-200.0f });
	entities.emplace_back(Star::Make(150.0f, 50.0f, 5), Vec2f{ -250.f,200.0f });
	entities.emplace_back(Star::Make(100.0f, 50.0f, 5), Vec2f{ 0.0f,0.0f });
	entities.emplace_back(Star::Make(200.0f, 50.0f, 5), Vec2f{ -150.f,-300.0f });
	entities.emplace_back(Star::Make(100.0f, 50.0f, 5), Vec2f{ 400.f,300.0f });*/
	entities.emplace_back(lvl);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	
	 float speedY;
	 float speedX;
	
	const float dt = ft.PerFrame();
	auto a = chr.GetPos().y;
	auto GetTile = [&](int posx, int posy, int x = 0, int y = 0) {
		
		posx = posx / 30+x;
		posy = posy/ 40+y;
		auto column = entities[0].GetModel();
		auto a = column[posy];
		auto b = a[posx];
		return b;
		
		
	};
	auto x = chr.GetPos().x;
	auto y = chr.GetPos().y;
	if (GetTile(x, y, 0, 2) != '#' && GetTile(x,y,0,0) != 'x')

	{
		
		speedX = 5.0f;
		speedY = 10.0f;
		g.gravity(chr);
	}
	else
	{
		speedX = 5.0f;
		speedY = 0.0f;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		chr.Update(0.96434);


			
			cam.MoveTo({chr.GetPos().x, 0.0f});

			chr.SetDirection({ speedX,0.0f });

		}

		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			chr.Update(0.96434);



			cam.MoveTo({ chr.GetPos().x,0.0f });

			chr.SetDirection({ -speedX,0.0f });

		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			chr.Update(0.0);
			chr.SetDirection({ 0.0f,5.0f });

		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			chr.Update(0.0);
			chr.SetDirection({ 0.0f,-speedY });

		}
	
	
}

void Game::ComposeFrame()
{
	
	for (auto entity : entities)
	{
		cam.Draw(entity.GetDrawable());
	}
	chr.Draw();
	
	
		
}
