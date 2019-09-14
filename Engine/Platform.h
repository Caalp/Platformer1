#pragma once

#include <vector>
#include <string>
#include "Graphics.h"
class Platform
{
	
public:
	Platform(std::vector<std::string>&);
	void Draw(Graphics& gfx);
	Vec2f Get_c_speed();
public:
	Vec2f c_speed = { 0.0f,0.0f };
private:
	int TileHeight = 40;
	int TileWidth = 40;
	std::string slevel;
	std::vector<std::string> P_LEVEL;
	
};