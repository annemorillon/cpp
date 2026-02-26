#include "../includes/Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(2, 2);
	Point c(0, 2);
	Point point(0, 0);
	Point point2(5, 5);
	Point point3(0.5, 1);

	if (!bsp(a, b, c, point))
		std::cout << "the point is inside of the triangle" << std::endl;
	else
		std::cout << "the point is outside of the triangle" << std::endl;
	if (!bsp(a, b, c, point2))
		std::cout << "the point is inside of the triangle" << std::endl;
	else
		std::cout << "the point is outside of the triangle" << std::endl;
	if (!bsp(a, b, c, point3))
		std::cout << "the point is inside of the triangle" << std::endl;
	else
		std::cout << "the point is outside of the triangle" << std::endl;

	return (0);
}