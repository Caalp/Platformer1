#pragma once
#include "Graphics.h"
class Drawable
{
public:
	Drawable(std::vector<Vec2f> model , Color c):
		c(c),
		model(std::move(model))
		
	{}
	Drawable (std::vector<std::string> p_model):
		p_model(std::move(p_model))
	{}
	void Translate(const Vec2f translation_in)
	{
		translation += translation_in;
	}
	void Scale(float scale_in)
	{
		scale_x *= scale_in;
		scale_y *= scale_in;
		translation *= scale_in;
	}
	void ScaleIndependent(float scale_in_x, float scale_in_y)
	{
		scale_x *= scale_in_x;
		scale_y *= scale_in_y;
		translation.x *= scale_in_x;
		translation.y *= scale_in_y;
	}

	void Render(Graphics& gfx)
	{

		/*for (auto& v : model)
		{
			v.x *= scale_x;
			v.y *= scale_y;
			v += translation;
		}
		gfx.DrawClosedPolyline(model, c);*/
		
		
		
		Platform pf = Platform(p_model);
		CameraPos = pf.c_speed += translation;

		pf.Draw(gfx);
		
		
	}
	Vec2f GetCameraPos() 
	{
		return CameraPos;
	}
private:
	Color c;
	std::vector<Vec2f> model;
	std::vector<std::string> p_model;
	Vec2f translation = { 0.0f, 0.0f };
	Vec2f CameraPos = { 0.0f,0.0f };
	float scale_x = 1.0f;
	float scale_y = 1.0f;
	
};
