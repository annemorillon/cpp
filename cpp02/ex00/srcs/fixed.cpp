#include "fixed.hpp"

// static const int _fractionalBits = 0;

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << GREY << "Default constructor called " << RESET << std::endl;
}

Fixed::~Fixed()
{
	std::cout << GREY << "Destructor called " << RESET << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	_value = fixed._value;
	std::cout << GREY << "Copy constructor called " << RESET << std::endl;
}

Fixed	Fixed::operator=(Fixed& fixed)
{
	std::cout << GREY << "Copy assignment operator called " << RESET << std::endl;
	return (fixed);
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREY << "getRawBits member function called " << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw / _fractionalBits;
	std::cout << GREY << "setRawBits member function called " << RESET << std::endl;
}