#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "iostream"
# include "string"

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Weapon
{
	public:

		Weapon(std::string value);
		~Weapon();

		std::string	getType();
		void		setType(std::string value);

	private:

		std::string	_type;

};

#endif