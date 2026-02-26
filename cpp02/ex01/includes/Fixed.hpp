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