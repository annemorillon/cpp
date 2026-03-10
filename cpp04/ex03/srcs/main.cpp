#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

int	main()
{
	std::cout << UNDERLINE "Note" RESET << " : check the main with valgrind" << std::endl;
	std::cout << PINK "\n=== Mandatory part ===" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);

	Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << PINK "\n=== Testing max inventory ===" RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	std::cout << DARKPINK "-> No segfault even when trying to add or display 4 materials" RESET << std::endl;

	std::cout << PINK "\n=== Testing leave materia ===" RESET << std::endl;
	AMateria* lost = me->getMateria(3);
	me->unequip(3);
	delete lost;
	me->use(3, *bob);
	std::cout << DARKPINK "-> No segfault or no leaks" RESET << std::endl;

	std::cout << PINK "\n=== Testing Deep Copy ===" RESET << std::endl;
	tmp = src->createMateria("cure");
	Character* original = new Character("original");
	original->equip(tmp);
	Character* copy = new Character(*original);
	std::cout << "Original use: ";
	original->use(0, *bob);
	std::cout << "Copy use:     ";
	copy->use(0, *bob);

	tmp = src->createMateria("ice");
	copy->equip(tmp);
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original use: ";
	original->use(0, *bob);
	std::cout << "Copy use:     ";
	copy->use(0, *bob);
	std::cout << DARKPINK "-> must be different" RESET << std::endl;

	std::cout << PINK "\n=== Testing Deep Copy with assignment ===" RESET << std::endl;
	tmp = src->createMateria("cure");
	Character* Original = new Character("original");
	Original->equip(tmp);
	Character* Copy = new Character("copy_empty");
	*Copy = *Original;
	std::cout << "Original use: ";
	Original->use(0, *bob);
	std::cout << "Copy use:     ";
	Copy->use(0, *bob);

	tmp = src->createMateria("ice");
	Copy->equip(tmp);
	std::cout << "\nAfter modifying Copy:" << std::endl;
	std::cout << "Original use: ";
	Original->use(1, *bob);
	std::cout << "Copy use:     ";
	Copy->use(1, *bob);
	std::cout << DARKPINK "-> must be different" RESET << std::endl;

	std::cout << PINK "\n=== Deleting pointeurs ===" RESET << std::endl;
	delete bob;
	delete me;
	delete src;
	delete original;
	delete copy;
	delete Copy;
	delete Original;
	std::cout << DARKPINK "-> check the order of destructors" RESET << std::endl;

	std::cout << PINK "\n=== End of main (stack objects destroyed) ===" RESET << std::endl;
	return (0);
}