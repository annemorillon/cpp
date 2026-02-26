#include "../includes/Fixed.hpp"

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
	std::cout << GREY << "Copy constructor called " << RESET << std::endl;
	_value = fixed.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& fixed)
{
	std::cout << GREY << "Copy assignment operator called " << RESET << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << GREY << "getRawBits member function called " << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	std::cout << GREY << "setRawBits member function called " << RESET << std::endl;
}