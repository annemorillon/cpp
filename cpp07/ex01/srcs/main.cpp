#include "iter.hpp"

template <typename T>
void print(T const &x) {
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
	x++;
}

int main(void) {
	int intArr[] = {1, 2, 3, 4, 5};
	const int len = 5;

	std::cout << "-- int[] before --" << std::endl;
	iter(intArr, len, print<const int>);

	iter(intArr, len, increment<int>);
	std::cout << "-- int[] after ++ --" << std::endl;
	iter(intArr, len, print<int>);

	std::string strArr[] = {"hello", "world", "42"};
	const int strLen = 3;

	std::cout << "-- string[] --" << std::endl;
	iter(strArr, strLen, print<std::string>);

	return 0;
}