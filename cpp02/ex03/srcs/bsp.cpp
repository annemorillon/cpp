#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

/* Calculating the position of the point relative to the line :
- v0 = vector of the line
- v1 = vector of a point on the line with the point to be defined */
float	positionOfpoint(Point const a, Point const b, Point const point)
{
	float v0x = b.getX().toFloat() - a.getX().toFloat();
	float v0y = b.getY().toFloat() - a.getY().toFloat();
	float v1x = point.getX().toFloat() - a.getX().toFloat();
	float v1y = point.getY().toFloat() - a.getY().toFloat();

	return ((v0y * v1x) - (v0x * v1y));
}

/* The points abc represent the triangle, and the point is the one to be checked.
The point is in the triangle if it is to the right or left of all the points.
- has_neg = to the right of the line
- has_pos = to the left of the line
ps: if the point is on an edge or a vertex it's false */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float ab = positionOfpoint(a, b, point);
	float bc = positionOfpoint(b, c, point);
	float ca = positionOfpoint(c, a, point);

	bool has_neg = (ab < 0) || (bc < 0) || (ca < 0);
	bool has_pos = (ab > 0) || (bc > 0) || (ca > 0);
	
	if (ab == 0 || bc == 0 || ca == 0)
		return (false);
	if (has_neg && has_pos)
		return (false);
	return (true);
}