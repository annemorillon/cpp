#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	const WrongAnimal*	h = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	h->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete h;
}