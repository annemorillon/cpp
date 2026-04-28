#include "iter.hpp"
 
int main(void) {
	int intArr[] = {1, 2, 3, 4, 5};
	const size_t len = 5;

	std::cout << "-- int[] before --" << std::endl;
	iter(intArr, len, print<int>);

	iter(intArr, len, increment<int>);
	std::cout << "-- int[] after ++ --" << std::endl;
	iter(intArr, len, print<int>);

	std::string strArr[] = {"hello", "world", "42"};
	const size_t strLen = 3;

	std::cout << "-- string[] --" << std::endl;
	iter(strArr, strLen, print<std::string>);

	return 0;
}
 
