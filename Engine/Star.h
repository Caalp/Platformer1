#pragma once
#include "Vec2.h"
#include <vector>
class Star
{
public:
	static std::vector<Vec2f> Make(float outerR, float innerR, int nFlares = 5)
	{
		std::vector<Vec2f> star;
		star.reserve(nFlares * 2);
		const float dTheta = 2.0f * 3.14159f / float(nFlares * 2);
		for (int i = 0; i < nFlares * 2; i++)
		{
			const float rad = (i % 2 == 0) ? outerR : innerR;
			star.emplace_back(
				rad*cos(float(i)*dTheta),
				rad*sin(float(i)*dTheta)
			);
		}
		return star;
	}
};
