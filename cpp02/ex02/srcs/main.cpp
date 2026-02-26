#include "../includes/Fixed.hpp"

int	main(void)
{
	Fixed a(6);
	Fixed b(2);
	
	std::cout << "\033[1m\033[38;2;11;102;35m*********************************" << std::endl;
	std::cout << "*	Comparaison operators	*" << std::endl;
	std::cout << "*********************************\033[0m" << std::endl;
	std::cout << "\033[1m* Bigger *\033[0m" << std::endl;
	if (a > b)
		std::cout << a << " est plus grand que " << b << std::endl;
	else
		std::cout << b << "est plus grand que" << a << std::endl;
	std::cout << "\033[1m* Smaller *\033[0m" << std::endl;
	if (a < b)
		std::cout << a << " est plus petit que " << b << std::endl;
	else
		std::cout << b << " est plus petit que " << a << std::endl;
	std::cout << "\033[1m* Bigger or egal *\033[0m" << std::endl;
	if (a >= b)
		std::cout << a << " est plus grand ou egal a " << b << std::endl;
	else
		std::cout << b << "est plus grand ou egal a " << a << std::endl;
	std::cout << "\033[1m* Smaller or egal *\033[0m" << std::endl;
	if (a <= b)
		std::cout << a << " est plus petit ou egal a " << b << std::endl;
	else
		std::cout << b << " est plus petit ou egal a " << a << std::endl;
	std::cout << "\033[1m* Egal *\033[0m" << std::endl;
	if (a == b)
		std::cout << a << " est egal a " << b << std::endl;
	else
		std::cout << a << " est different de " << b << std::endl;
	std::cout << "\033[1m* Different *\033[0m" << std::endl;
	if (a != b)
		std::cout << a << " est different de " << b << std::endl;
	else
		std::cout << a << " est egal a " << b << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1m\033[38;2;11;102;35m*********************************" << std::endl;
	std::cout << "*	Arithmetic operators	*" << std::endl;
	std::cout << "*********************************\033[0m" << std::endl;
	std::cout << a << " + " << b << " donne "<< a + b << std::endl;
	std::cout << a << " - " << b << " donne "<< a - b << std::endl;
	std::cout << a << " * " << b << " donne "<< a * b << std::endl;
	std::cout << a << " / " << b << " donne "<< a / b << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1m\033[38;2;11;102;35m*********************************" << std::endl;
	std::cout << "*	Increment/Decrement	*" << std::endl;
	std::cout << "*********************************\033[0m" << std::endl;
	std::cout << "Valeur de depart: " << a << std::endl;
	std::cout << "Pre-incrementation " << ++a << std::endl;
	std::cout << "Post-incrementation " << a++ << std::endl;
	std::cout << "Nouvelle valeur " << a << std::endl;
	std::cout << std::endl;
	std::cout << "Nouvelle valeur " << a << std::endl;
	std::cout << "Pre-incrementation " << --a << std::endl;
	std::cout << "Post-incrementation " << a-- << std::endl;
	std::cout << "Nouvelle valeur " << a << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1m\033[38;2;11;102;35m*********************************" << std::endl;
	std::cout << "*	Minimum / Maxium	*" << std::endl;
	std::cout << "*********************************\033[0m" << std::endl;
	std::cout << "Le minimun entre " << a << " et " << b << " est " << Fixed::min(a,b) << std::endl;
	std::cout << "Le maximun entre " << a << " et " << b << " est " << Fixed::max(a,b) << std::endl;
	std::cout << std::endl;

	return (0);
}