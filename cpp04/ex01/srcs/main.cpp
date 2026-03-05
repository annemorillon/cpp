#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main(void)
{
	std::cout << UNDERLINE "Note" RESET << " : check the main with valgrind" << std::endl;
	std::cout << PINK "\n=== Testing Deep Copy ===" RESET << std::endl;
	Dog	original;
	original.getBrain()->setIdea("Original idea", 0);
	Dog	copy(original);
	std::cout << "Original dog idea[0]: " << original.getBrain()->getIdea(0) << std::endl;

	std::cout << "Copy dog idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;

	copy.getBrain()->setIdea("Modified copy idea", 0);
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original dog idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << DARKPINK "-> Idea[0] must be different" RESET << std::endl;

	std::cout << PINK "\n=== Testing Deep Copy with assignment ===" RESET << std::endl;
	Cat	catOriginal;
	catOriginal.getBrain()->setIdea("Original cat idea", 0);
	Cat	catCopy = catOriginal;
	std::cout << "Original cat idea[0]: " << catOriginal.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy cat idea[0]:     " << catCopy.getBrain()->getIdea(0) << std::endl;

	catCopy.getBrain()->setIdea("Modified cat copy idea", 0);
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "\nOriginal cat idea[0]: " << catOriginal.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy cat idea[0]:     " << catCopy.getBrain()->getIdea(0) << std::endl;
	std::cout << DARKPINK "-> Idea[0] must be different" RESET << std::endl;

	std::cout << PINK "\n=== Creating array of 10 Animals ===" RESET << std::endl;
	const int	SIZE = 2;
	Animal*		animals[SIZE];

	for (int i = 0; i < SIZE / 2; i++)
	{
			animals[i] = new Dog();
			animals[i]->getBrain()->setIdea("Original idea", 0);
	}
	for (int i = SIZE / 2; i < SIZE; i++)
	{
			animals[i] = new Cat();
			animals[i]->getBrain()->setIdea("Original idea", 0);
	}
	catCopy = catOriginal; // just for check if there's any leaks when reassigning an existing animal
	std::cout << PINK "\n=== Deleting array of Animals ===" RESET << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete animals[i];
	std::cout << DARKPINK "-> mandatory part : check the order of destructors as called" RESET << std::endl;

	std::cout << PINK "\n=== End of main (stack objects destroyed) ===" RESET << std::endl;
	return (0);
}