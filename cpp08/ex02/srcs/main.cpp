#include <MutantStack.hpp>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"


int main()
{
	// --- Test 1: Sujet Officiel ---
	std::cout << YELLOW "--- Test 1: Subject (Basic Operations) ---" RESET << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << (mstack.top() == 17 ? GREEN " [OK]" : RED " [KO (Expected: 17)]") << RESET << std::endl;
	
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << (mstack.size() == 1 ? GREEN " [OK]" : RED " [KO (Expected: 1)]") << RESET << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << CYAN "Iterating through MutantStack:" RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << GREEN "\n[OK] Expected: 5 3 5 737 0" RESET << std::endl;

	// --- Test 2: Comparaison avec std::list (Requis par le sujet) ---
	std::cout << YELLOW "\n--- Test 2: Comparison with std::list ---" RESET << std::endl;
	
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator lit = mlist.begin();
	MutantStack<int>::iterator it2 = mstack.begin();

	std::list<int>::iterator lite = mlist.end();

	std::cout << CYAN "Iterating through std::list:" RESET << std::endl;
	while (lit != lite)
	{
		if (*it2 != *lit)
			break;
		std::cout << *lit << " ";
		++it2;
		++lit;
	}
	if (*it2 != *lit && lit != lite)
		std::cout << "\n" RED "[KO] Behavior is different to std::list" RESET << std::endl;
	else
		std::cout << "\n" GREEN "[OK] Behavior is identical to std::list" RESET << std::endl;

	// --- Test 3: Reverse Iterators & Const Iterators ---
	std::cout << YELLOW "\n--- Test 3: Const and Reverse Iterators ---" RESET << std::endl;
	try {
		const MutantStack<int> const_stack(mstack);
		std::cout << "Const Begin: " << *const_stack.begin() << (*const_stack.begin() == 5 ? GREEN " [OK]" : RED " [KO (Expected: 5)]") << RESET << std::endl;

		std::cout << "Reverse Iterator: ";
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		for (; rit != mstack.rend(); ++rit)
			std::cout << *rit << " ";
		std::cout << GREEN "\n[OK] Expected: 0 737 5 3 5" RESET << std::endl;
	} 
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// --- Test 4: Copy Constructor & Assignment ---
	std::cout << YELLOW "\n--- Test 4: Copy & Assignment ---" RESET << std::endl;
	{
		const MutantStack<int> const_stack(mstack);
		std::stack<int> s(mstack); // Test de la compatibilité avec std::stack
		std::cout << "Mstack size: " << mstack.size() << RESET << std::endl;
		std::cout << "Copy to std::stack size: " << s.size() << (s.size() == 5 ? GREEN " [OK]" : RED " [KO (Expected: 5)]") << "\n" << RESET << std::endl;

		MutantStack<int> assigned_stack;
		assigned_stack = mstack;
		std::cout << "Mstack top: " << mstack.top() << std::endl;
		std::cout << "Assigned stack top: " << assigned_stack.top() << (assigned_stack.top() == 0 ? GREEN " [OK]" : RED " [KO (Expected: 0)]") << std::endl;
		
		if (assigned_stack.top() == mstack.top())
			std::cout << GREEN "[OK] Copy and Assignment work perfectly" RESET << std::endl;
		else
			std::cout << RED "[KO] Copy and Assignment doesn't work perfectly" RESET << std::endl;
	}

	return 0;
}