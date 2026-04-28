#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

int main(void) {
    // Test vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
 
    try {
        std::cout << "vector - find 3 : " << *easyfind(vec, 3) << std::endl;
        std::cout << "vector - find 9 : " << *easyfind(vec, 9) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
 
    // Test list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
 
    try {
        std::cout << "list - find 20 : " << *easyfind(lst, 20) << std::endl;
        std::cout << "list - find 99 : " << *easyfind(lst, 99) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
 
    // Test deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
 
    try {
        std::cout << "deque - find 100 : " << *easyfind(deq, 100) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
 
    return 0;
}