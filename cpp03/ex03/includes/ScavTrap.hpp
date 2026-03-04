#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "../includes/ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:

		ScavTrap();
		~ScavTrap();

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& copy);

		ScavTrap	&operator=(ScavTrap const& old);

		void		attack(std::string const& target);
		void		guardGate();

	protected:

};

#endif