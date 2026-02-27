#include "../includes/Point.hpp"

Point::Point(): _x(Fixed(0)), _y(Fixed(0))
{
}

Point::~Point()
{
}

Point::Point(float const x, float const y): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point& point): _x(Fixed(point._x)), _y(Fixed(point._y))
{
}

Point	&Point::operator=(const Point& point)
{
	(void) point;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}