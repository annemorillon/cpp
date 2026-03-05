#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	std::cout << UNDERLINE "Note" RESET << " : check the main with valgrind" << std::endl;
	std::cout << PINK "\n=== Creating Animals ===" RESET << std::endl;
	const Animal*	animal = new Animal();
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();
	const WrongAnimal*	wrongcat = new WrongCat();

	std::cout << PINK "\n=== Testing type of Animals ===" RESET << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	
	std::cout << PINK "\n=== Testing sound of Animals ===" RESET << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongcat->makeSound();

	std::cout << PINK "\n=== Testing Copy ===" RESET << std::endl;
	Dog dogOriginal;
	Animal dogCopy(dogOriginal);
	std::cout << "dogCopy type : " << dogCopy.getType() << " " << std::endl;

	Cat catOriginal;
	Animal catCopy(catOriginal);
	std::cout << "catCopy type : " << catCopy.getType() << " " << std::endl;

	std::cout << PINK "\n=== Testing Copy with assignment ===" RESET << std::endl;
	Dog dogoriginal;
	Animal dogcopy = dogoriginal;
	std::cout << "dogcopy type : " << dogcopy.getType() << " " << std::endl;

	Cat catoriginal;
	Animal catcopy = catoriginal;
	std::cout << "catcopy type : " << catcopy.getType() << " " << std::endl;

	std::cout << PINK "\n=== Deleting array of Animals ===" RESET << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrongcat;

	std::cout << PINK "\n=== End of main (stack objects destroyed) ===" RESET << std::endl;
}