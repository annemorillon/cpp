#include "../includes/DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Création du FragTrap ===" << std::endl;
	DiamondTrap clap("Jack");

	clap.whoAmI();

	std::cout << "\n=== Test attaque ===" << std::endl;
	clap.ScavTrap::attack("Paul");

	std::cout << "\n=== Test réparation ===" << std::endl;
	clap.ScavTrap::beRepaired(1);

	std::cout << "\n=== Test dégâts ===" << std::endl;
	clap.ScavTrap::takeDamage(2);

	std::cout << "\n=== Test épuisement énergie ===" << std::endl;
	for (int i = 0; i < 9; i++)
		clap.ScavTrap::attack("Jean");

	std::cout << "\n=== Tentative d'action sans énergie ===" << std::endl;
	clap.ScavTrap::beRepaired(3);
	clap.ScavTrap::takeDamage(1);
	clap.ScavTrap::attack("Nobody");

	std::cout << "\n=== Test mort du FragTrap ===" << std::endl;
	clap.ScavTrap::takeDamage(100);

	std::cout << "\n=== Tentative d'action après mort ===" << std::endl;
	clap.ScavTrap::attack("Ghost");
	clap.ScavTrap::beRepaired(10);

	return (0);
}