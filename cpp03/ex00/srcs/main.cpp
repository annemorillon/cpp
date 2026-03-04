#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Creation of ClapTrap ===" << std::endl;
	ClapTrap clap("Jack");

	std::cout << "\n=== Attack ===" << std::endl;
	clap.attack("Paul");

	std::cout << "\n=== Repair ===" << std::endl;
	clap.beRepaired(1);

	std::cout << "\n=== Damage ===" << std::endl;
	clap.takeDamage(2);

	std::cout << "\n=== Energy out ===" << std::endl;
	for (int i = 0; i < 9; i++)
		clap.attack("Jean");

	std::cout << "\n=== Action after energy out ===" << std::endl;
	clap.beRepaired(3);
	clap.takeDamage(1);
	clap.attack("Nobody");

	std::cout << "\n=== Death ClapTrap ===" << std::endl;
	clap.takeDamage(100);

	std::cout << "\n=== Action after death ===" << std::endl;
	clap.attack("Ghost");
	clap.beRepaired(10);
	clap.takeDamage(10);

	// std::cout << "\n=== Copy ClapTrap ===" << std::endl;
	// ClapTrap clap2 = clap;
	// clap2.attack("Ghost");
	// ClapTrap clap3(clap);
	// clap3.beRepaired(10);

	return (0);
}