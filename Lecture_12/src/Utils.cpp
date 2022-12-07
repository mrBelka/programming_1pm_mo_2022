#include <Utils.hpp>
#include <math.h>

namespace mt::utils
{
	float Distance(Point p1, Point p2)
	{
		return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}
}