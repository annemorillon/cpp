#include "../includes/Fixed.hpp"

Fixed	&Fixed::operator=(const Fixed& fixed)
{
	std::cout << GREY << "Copy assignment operator called " << RESET << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(void)
{
	_value = 0;
	// std::cout << GREY << "Default constructor called " << RESET << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << GREY << "Destructor called " << RESET << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << GREY << "Copy constructor called " << RESET << std::endl;
	_value = fixed.getRawBits();
}

Fixed::Fixed(float value)
{
	// std::cout << GREY << "Float constructor called " << RESET << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(int value)
{
	// std::cout << GREY << "Int constructor called " << RESET << std::endl;
	_value = value << _fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << GREY << "getRawBits member function called " << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	// std::cout << GREY << "setRawBits member function called " << RESET << std::endl;
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._value = _value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._value = _value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result._value = _value * other._value >> _fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result._value = _value / other._value << _fractionalBits;
	return (result);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (_value != other._value);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (_value > other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (_value < other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other._value);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed&	Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}

Fixed Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

Fixed	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return(f2);
}

Fixed	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return(f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
