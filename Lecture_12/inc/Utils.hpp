#pragma once

namespace mt::utils
{
	struct Point
	{
		float x;
		float y;
	};

	struct Vec
	{
		float x;
		float y;
	};

	float Distance(Point p1, Point p2);
}