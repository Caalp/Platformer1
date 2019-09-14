#include "Platform.h"

Platform::Platform(std::vector<std::string>& nLevel ):
	P_LEVEL(nLevel)
{
	
}

void Platform::Draw(Graphics& gfx)
{
	Surface surf = Surface("beach.bmp");
	Surface surf2 = Surface("rock.bmp");
	for (int i = 0; i < P_LEVEL.size(); i++)
	{
		for (int j = 0; j < 61; j++)
		{
			std::string temp = P_LEVEL[i];
			switch (temp[j])
			{
			case '.':
				gfx.DrawRect(j*TileWidth + c_speed.x, i*TileHeight , { 0,0 }, { 40,40 }, {0,800,0,600}, Colors::Cyan);
				break;
			case '#':
				
				gfx.DrawSprite(int(j*TileWidth + c_speed.x), int(i*TileHeight + c_speed.y), { 0,40,0,40 }, {0, 800, 0, 600}, surf);
				//gfx.DrawRect(j*TileWidth, i*TileHeight, { 0,0 }, { 40,40 }, Colors::Red);
				break;
			case 'x':
			
				gfx.DrawSprite(int(j*TileWidth + c_speed.x), int(i*TileHeight + c_speed.y), { 0,40,0,40 }, {0,800,0,600}, surf2);
				//gfx.DrawRect(j*TileWidth, i*TileHeight, { 0,0 }, { 40,40 }, Colors::Red);
				break;
			}
		}
	}
}

Vec2f Platform::Get_c_speed()
{
	return c_speed;
}
