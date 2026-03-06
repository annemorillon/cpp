#include "../includes/Character.hpp"


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
	std::cout << PINK "\n=== Mandatory part ===" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	return (0);
}