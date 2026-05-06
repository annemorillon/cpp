#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main(void) {
	// --- Test 1: Vector (Succès) ---
	std::cout << YELLOW "--- Test 1: Vector (Success) ---" RESET << std::endl;
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
		vec.push_back(i);

	try {
		int target = 5;
		std::vector<int>::iterator it = easyfind(vec, target);
		std::cout << "Find " << target << ": " << *it;
		std::cout << (*it == target ? GREEN " [OK]" : RED " [KO]") << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED "[KO] Unexpected exception: " << e.what() << RESET << std::endl;
	}

	// --- Test 2: Vector (Échec attendu) ---
	std::cout << YELLOW "\n--- Test 2: Vector (Fail) ---" RESET << std::endl;
	try {
		easyfind(vec, 9);
		std::cout << RED "[KO] No exception thrown for missing value!" RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN "[OK] Caught expected error: " << RESET << e.what() << std::endl;
	}

	// --- Test 3: List (Succès) ---
	std::cout << YELLOW "\n--- Test 3: List (Success) ---" RESET << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		int target = 20;
		std::list<int>::iterator it = easyfind(lst, target);
		std::cout << "Find " << target << ": " << *it;
		std::cout << (*it == target ? GREEN " [OK]" : RED " [KO]") << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED "[KO] Error: " << e.what() << RESET << std::endl;
	}

	// --- Test 4: Deque (Success & Fail) ---
	std::cout << YELLOW "\n--- Test 4: Deque (Mixed) ---" RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(100); deq.push_back(200);

	try {
		// Test OK
		easyfind(deq, 100);
		std::cout << "Find 100: " GREEN "[OK]" RESET << std::endl;
		
		// Test KO
		std::cout << "Find 400: ";
		easyfind(deq, 400);
		std::cout << RED "[KO] No exception!" RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN "[OK] Caught expected error: " << RESET << e.what() << std::endl;
	}

	return 0;
}