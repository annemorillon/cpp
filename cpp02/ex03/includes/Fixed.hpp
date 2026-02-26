#ifndef	FIXED_HPP
# define FIXED_HPP

# include "iostream"
# include "cmath"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Fixed
{
	public:

		Fixed(void);
		~Fixed();

		Fixed(const Fixed& fixed);
		Fixed(float value);
		Fixed(int value);

		Fixed	&operator=(const Fixed& fixed);
		
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);

		static Fixed	max(const Fixed& f1, const Fixed& f2);
		static Fixed	min(const Fixed& f1, const Fixed& f2);
		static Fixed	max(Fixed& f1, Fixed& f2);
		static Fixed	min(Fixed& f1, Fixed& f2);

		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					_value;
		static const int	_fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
