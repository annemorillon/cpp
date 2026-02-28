#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "=== Création du ScavTrap ===" << std::endl;
	ScavTrap clap("Jack");

	clap.guardGate();

	std::cout << "\n=== Test attaque ===" << std::endl;
	clap.attack("Paul");

	std::cout << "\n=== Test réparation ===" << std::endl;
	clap.beRepaired(1);

	std::cout << "\n=== Test dégâts ===" << std::endl;
	clap.takeDamage(2);

	std::cout << "\n=== Test épuisement énergie ===" << std::endl;
	for (int i = 0; i < 9; i++)
		clap.attack("Jean");

	std::cout << "\n=== Tentative d'action sans énergie ===" << std::endl;
	clap.beRepaired(3);
	clap.takeDamage(1);
	clap.attack("Nobody");

	std::cout << "\n=== Test mort du ClapTrap ===" << std::endl;
	clap.takeDamage(100);

	std::cout << "\n=== Tentative d'action après mort ===" << std::endl;
	clap.attack("Ghost");
	clap.beRepaired(10);

	return (0);
}