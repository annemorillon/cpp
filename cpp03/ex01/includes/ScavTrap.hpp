#include "../includes/ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:

		ScavTrap();
		~ScavTrap();

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& copy);

		ScavTrap	&operator=(ScavTrap const& old);

		void		guardGate();

	private:

};