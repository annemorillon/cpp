#include <iostream>
#include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#define MAX_VAL 750

int main(void)
{
	// --- Test 1 : constructeur par défaut ---
	std::cout << "=== Test constructeur par défaut ===" << std::endl;
	Array<int> empty;
	std::cout << "Taille : " << empty.size() << std::endl;

	// --- Test 2 : constructeur avec n ---
	std::cout << "\n=== Test constructeur Array<int>(5) ===" << std::endl;
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = (int)i * 10;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	// --- Test 3 : copie profonde (constructeur de copie) ---
	std::cout << "\n=== Test copie profonde ===" << std::endl;
	Array<int> copy(numbers);
	copy[0] = 999;
	std::cout << "numbers[0] après modif de copy[0] : " << numbers[0] << " (doit rester 0)" << std::endl;
	std::cout << "copy[0] : " << copy[0] << " (doit être 999)" << std::endl;

	// --- Test 4 : opérateur d'affectation ---
	std::cout << "\n=== Test opérateur d'affectation ===" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 42;
	std::cout << "numbers[1] après modif de assigned[1] : " << numbers[1] << " (doit rester 10)" << std::endl;
	std::cout << "assigned[1] : " << assigned[1] << " (doit être 42)" << std::endl;

	// --- Test 5 : exception hors limites ---
	std::cout << "\n=== Test exception hors limites ===" << std::endl;
	try {
		numbers[999] = 0;
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}
	try {
		empty[0] = 0;
	} catch (std::exception &e) {
		std::cout << "Exception attrapée sur tableau vide : " << e.what() << std::endl;
	}

	// --- Test 6 : types différents ---
	std::cout << "\n=== Test avec double ===" << std::endl;
	Array<double> doubles(3);
	doubles[0] = 3.14;
	doubles[1] = 2.71;
	doubles[2] = 1.41;
	for (unsigned int i = 0; i < doubles.size(); i++)
		std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;

	std::cout << "\n=== Test avec std::string ===" << std::endl;
	Array<std::string> words(3);
	words[0] = "bonjour";
	words[1] = "monde";
	words[2] = "42";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;

	return 0;
}