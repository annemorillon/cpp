#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "../includes/FragTrap.hpp"
# include "../includes/ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:

		DiamondTrap();
		~DiamondTrap();

		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& copy);

		DiamondTrap	&operator=(DiamondTrap const& old);

		// void		ScavTrap::attack(std::string const& target);
		void		whoAmI();

	protected:
		std::string	_name;

};

#endif