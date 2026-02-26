#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public :

        Point();
        ~Point();

        Point(float const x, float const y);
        Point(const Point& point);

        Point   &operator=(const Point& point);

        Fixed   getX(void) const;
        Fixed   getY(void) const;

    private :

        Fixed const _x;
        Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif