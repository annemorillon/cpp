#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "../includes/ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:

		FragTrap();
		~FragTrap();

		FragTrap(std::string name);
		FragTrap(FragTrap const& copy);

		FragTrap	&operator=(FragTrap const& old);

		void		attack(std::string const& target);
		void		highFivesGuys();

	protected:

};

#endif