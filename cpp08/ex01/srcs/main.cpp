#include <span.hpp>
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int main()
{
	// --- Test 1: Sujet Officiel ---
	std::cout << YELLOW "--- Test 1: Subject ---" RESET << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		int shortest = sp.shortestSpan();
		int longest = sp.longestSpan();

		std::cout << "Shortest: " << shortest << (shortest == 2 ? GREEN " [OK (Expected: 2)]" : RED " [KO]") << RESET << std::endl;
		std::cout << "Longest:  " << longest << (longest == 14 ? GREEN " [OK (Expected: 14)]" : RED " [KO]") << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}

	// --- Test 2: Limites et Exceptions ---
	std::cout << YELLOW "\n--- Test 2: Full Capacity Error ---" RESET << std::endl;
	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		std::cout << "Adding 3rd element..." << std::endl;
		sp.addNumber(3); 
		std::cout << RED "[KO] No exception thrown!" RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN "[OK] Caught expected error: " << RESET << e.what() << std::endl;
	}

	// --- Test 3: Pas assez de nombres ---
	std::cout << YELLOW "\n--- Test 3: No Span Error (1 element) ---" RESET << std::endl;
	try {
		Span sp(1);
		sp.addNumber(42);
		sp.shortestSpan();
		std::cout << RED "[KO] No exception thrown!" RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN "[OK] Caught expected error: " << RESET << e.what() << std::endl;
	}

	// --- Test 4: Remplissage de masse (Arithmétique) ---
	std::cout << YELLOW "\n--- Test 4: Massive Span (20,000 numbers) ---" RESET << std::endl;
	try {
		unsigned int limit = 20000;
		Span bigSp(limit);
		for (unsigned int i = 0; i < limit; i++)
			bigSp.addNumber(i * 10); // 0, 10, 20, 30...

		int sSpan = bigSp.shortestSpan();
		int lSpan = bigSp.longestSpan();

		std::cout << "Shortest: " << sSpan << (sSpan == 10 ? GREEN " [OK]" : RED " [KO]") << RESET << std::endl;
		std::cout << "Longest:  " << lSpan << (lSpan == 199990 ? GREEN " [OK]" : RED " [KO]") << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}

	// --- Test 5: Range of Iterators ---
	std::cout << YELLOW "\n--- Test 5: Range of Iterators (10,000 randoms) ---" RESET << std::endl;
	try {
		std::srand(std::time(NULL));
		Span sp(10000);
		std::vector<int> source;
		for (int i = 0; i < 10000; i++)
			source.push_back(std::rand());

		sp.addNumbers(source.begin(), source.end());
		std::cout << GREEN "[OK] 10,000 numbers added via range." RESET << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
		
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
	}

	// --- Test 6: Range Overflow Verification ---
	std::cout << YELLOW "\n--- Test 6: Range Overflow (Expected Failure) ---" RESET << std::endl;
	try {
		Span sp(5); // Capacité de 5
		std::vector<int> v(10, 42); // Un vecteur de 10 éléments

		std::cout << "Attempting to add 10 elements to a Span of 5..." << std::endl;
		sp.addNumbers(v.begin(), v.end());
		
		std::cout << RED "[KO] No exception thrown!" RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << GREEN "[OK] Caught expected error: " << RESET << e.what() << std::endl;
	}

	return 0;
}