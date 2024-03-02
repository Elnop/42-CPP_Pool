#include <iostream>
#include <sstream>

std::string	addrToStr(void *nb)
{
	std::stringstream ss;
	ss << nb;
	return ss.str();
}

void readinput(std::string& buff)
{
	std::cout << "\nchange value of ref => ";
	std::getline(std::cin, buff);
}

int	main (void)
{
	std::string str;
	std::cout << "\001\033[0;36m\002Say hello => ";
	std::getline(std::cin, str);

	std::string& stringREF = str;
	std::string	*stringPTR = &str;

	readinput(stringREF);
	std::cout << "\001\033[0;32m\002\n------ FIRST STRING -----\n";
	std::cout << "value: " + str + "\n";
	std::cout << "address: " + addrToStr(&str) + "\n";
	std::cout << "\n------ STRING REFERENCE -----\n";
	std::cout << "value: " + stringREF + "\n";
	std::cout << "address: " + addrToStr(&stringREF) + "\n";
	std::cout << "\n------ STRING POINTER -----\n";
	std::cout << "value: " + addrToStr(stringPTR) + "\n";
	std::cout << "dereferenced value: " + *stringPTR + "\n";
	std::cout << "\033[0;31m\002\nALL VALUES AND ADDRESSES ARE THE FUCKING SAME\n";
	std::cout << "&str == &stringREF == &stringREF\n\001\033[0m\002";
}