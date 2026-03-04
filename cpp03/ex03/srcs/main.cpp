#include "../includes/DiamondTrap.hpp"

int main(void)
{
	std::cout << "=== Creation of DiamondTrap ===" << std::endl;
	DiamondTrap clap("Jack");

	std::cout << "=== DiamondTrap : whoAmI ===" << std::endl;
	clap.whoAmI();

	std::cout << "\n=== Attack ===" << std::endl;
	clap.attack("Paul");

	std::cout << "\n=== Repair ===" << std::endl;
	clap.beRepaired(1);

	std::cout << "\n=== Damage ===" << std::endl;
	clap.takeDamage(2);

	std::cout << "\n=== Energy out ===" << std::endl;
	for (int i = 0; i < 50; i++)
		clap.attack("Jean");

	std::cout << "\n=== Action after energy out ===" << std::endl;
	clap.beRepaired(3);
	clap.takeDamage(1);
	clap.attack("Nobody");

	std::cout << "\n=== Death DiamondTrap ===" << std::endl;
	clap.takeDamage(100);

	std::cout << "\n=== Action after death ===" << std::endl;
	clap.attack("Ghost");
	clap.beRepaired(10);
	clap.takeDamage(10);

	std::cout << "\n=== Copy DiamondTrap ===" << std::endl;
	DiamondTrap clap2 = clap;
	clap2.whoAmI();
	clap2.attack("Ghost");
	DiamondTrap clap3(clap);
	clap3.beRepaired(10);

	return (0);
}