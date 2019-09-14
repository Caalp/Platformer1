#pragma once
#include "CoordinateTransformer.h"
class Camera
{
public:

	Camera(CoordinateTransformer& ct):
		ct(ct)
	{}
	Vec2f GetPos() const
	{
		return pos;
	}
	void MoveBy(const Vec2f& offset)
	{
		pos += offset;
	}
	void MoveTo(const Vec2f& pos_in)
	{
		pos = pos_in;
	}
	
	void SetScale(float newScale)
	{
		scale = newScale;
	}
	float GetScale()
	{
		return scale;
	}
	void Draw(Drawable& drawable) 
	{
		drawable.Translate(pos*-1.0f );
		drawable.Scale(scale);
		ct.Draw(drawable);
		CameraPos = drawable.GetCameraPos();
		
	}
	Vec2f returnCamPos()
	{
		return CameraPos;
	}
private:
	float scale = 1.0f;
	Vec2f pos = { 0.0f,0.0f };
	Vec2f CameraPos = { 0.0f,0.0f };
	CoordinateTransformer& ct;
};