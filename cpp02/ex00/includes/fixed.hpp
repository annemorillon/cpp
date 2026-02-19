#ifndef	FIXED_HPP
# define FIXED_HPP

# include "iostream"
# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Fixed
{
	public:

		Fixed(void);
		~Fixed();

		void	copyConstructor(const Fixed& fixed);
		Fixed	operator=(Fixed& fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					_value;
		static const int	_fractionalBits = 256;

};

#endif