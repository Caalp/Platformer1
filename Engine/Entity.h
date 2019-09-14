#pragma once
#include <vector>
#include "Vec2.h"
#include "Drawable.h"
class Entity
{
public:
	Entity(std::vector<Vec2f> model, const Vec2f& pos = { 0.0f,0.0f }, Color c = Colors::Green) :
		c(c),
		model(std::move(model)),
		pos(pos)
	{}
	Entity(std::vector<std::string>& p_model) : 
		p_model(std::move(p_model))
	{}
	const Vec2f& GetPos() const
	{
		return pos;
	}
	void SetPos(const Vec2f& newPos)
	{
		pos = newPos;
	}
	void TranslateBy(const Vec2f& offset)
	{
		pos += offset;
	}
	void SetScale(float Scale)
	{
		scale = Scale;
	}
	float GetScale()
	{
		return scale;
	}
	Drawable GetDrawable() const
	{
		Drawable d(p_model);

		d.Scale(scale);
		d.Translate(pos);
		return d;
	}
	const std::vector<std::string> GetModel() const
	{
		return p_model;
	}

public:
	void GetTile(Character& chr)
	{
		auto GetTile = [&]() {
			auto ChrPos = chr.GetPos();
			int posx = ChrPos.x / 4;
			int posy = ChrPos.y / 33;
			auto column = p_model;
			auto a = column[posy];
			auto b = a[posx];
			//auto row = column[posx];
			return b;
		};
		GetTile();
	}
private:
	
	Color c;
	std::vector<Vec2f> model;
	std::vector<std::string> p_model;
	Vec2f pos = { 0.0f,0.0f };
	float scale = 1.0f;
};