#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::cout << easyfind(v, 3) << std::endl;
}