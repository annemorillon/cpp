#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "iostream"

class ClapTrap
{
	public:

		ClapTrap();
		~ClapTrap();

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& copy);

		ClapTrap		&operator=(ClapTrap const& old);

		void			attack(std::string const& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			setHitPoint(unsigned int value);
		void			setEnergyPoint(unsigned int value);
		void			setAttackDamage(unsigned int value);

		unsigned int	getHitPoint(void);
		unsigned int	getEnergyPoint(void);
		unsigned int	getAttackDamage(void);

	protected:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif