#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

// equiper un personnage jusqu'a 4
// checker l'ordre d'equipement
// tester au dela : rien ne doit se passer
// desequiper un materiel -> attention leaks
// tester que le materiel n'a pas ete supprimer
// comportement au choix pour les equipements au sol
// checker fonction use du Character
// tester different type d'équipements
// copy deep : copy -> delete materias & new one before add
// materias must be deleted when Character is destroyed

int	main()
{
	std::cout << UNDERLINE "Note" RESET << " : check the main with valgrind" << std::endl;
	std::cout << PINK "\n=== Mandatory part ===" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << PINK "\n=== Testing max inventory ===" RESET << std::endl;
	delete tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp); // doesn't no fonctionnal
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // doesn't no fonctionnal
	std::cout << DARKPINK "-> No segfault even when trying to add or display 4 materials" RESET << std::endl;

	std::cout << PINK "\n=== Testing leave materia ===" RESET << std::endl;
	me->unequip(3);
	me->use(3, *bob); // doesn't no fonctionnal
	std::cout << DARKPINK "-> No segfault or no leaks" RESET << std::endl;

	std::cout << PINK "\n=== Testing Deep Copy ===" RESET << std::endl;
	Character	original("original");
	original.equip(tmp);
	Character	copy(original);
	std::cout << "Original use: ";
	original.use(0, *bob);
	std::cout << "Copy use:     ";
	copy.use(0, *bob);

	original.equip(tmp);
	delete tmp;
	tmp = src->createMateria("ice");
	copy.equip(tmp);
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original use: ";
	original.use(1, *bob);
	std::cout << "Copy use:     ";
	copy.use(1, *bob);
	std::cout << DARKPINK "-> Idea[0] must be different" RESET << std::endl;

	std::cout << PINK "\n=== Testing Deep Copy with assignment ===" RESET << std::endl;
	Character	Original("original");
	Original.equip(tmp);
	Character	Copy = Original;
	std::cout << "Original use: ";
	Original.use(0, *bob);
	std::cout << "Copy use:     ";
	Copy.use(0, *bob);

	Original.equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	Copy.equip(tmp);
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original use: ";
	Original.use(1, *bob);
	std::cout << "Copy use:     ";
	Copy.use(1, *bob);
	std::cout << DARKPINK "-> Idea[0] must be different" RESET << std::endl;

	std::cout << PINK "\n=== Deleting pointeurs ===" RESET << std::endl;
	delete bob;
	delete me;
	delete src;
	delete tmp;
	std::cout << DARKPINK "-> mandatory part : check the order of destructors as called" RESET << std::endl;

	std::cout << PINK "\n=== End of main (stack objects destroyed) ===" RESET << std::endl;
	return (0);
}