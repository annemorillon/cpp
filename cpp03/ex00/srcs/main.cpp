# include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Création du ClapTrap ===" << std::endl;
    ClapTrap clap("Jack");

    std::cout << "\n=== Test attaque ===" << std::endl;
    clap.attack("Bandit");

    std::cout << "\n=== Test réparation ===" << std::endl;
    clap.beRepaired(10);

    std::cout << "\n=== Test dégâts ===" << std::endl;
    clap.takeDamage(2);

    std::cout << "\n=== Test épuisement énergie ===" << std::endl;
    for (int i = 0; i < 6; i++)
        clap.attack("Dummy");

    std::cout << "\n=== Test mort du ClapTrap ===" << std::endl;
    clap.takeDamage(100);

    std::cout << "\n=== Tentative d'action après mort ===" << std::endl;
    clap.attack("Ghost");
    clap.beRepaired(10);

    std::cout << "\n=== Tentative d'action sans énergie ===" << std::endl;
    ClapTrap clap2("Jean");
    clap2.beRepaired(3);
    clap2.takeDamage(1);
    for (int i = 0; i < 9; i++)
        clap2.attack("Dummy");
    clap2.attack("Nobody");
    clap2.beRepaired(3);


    std::cout << "\n=== Fin du programme ===" << std::endl;

    return (0);
}