#include "ScalarConverter.h"

#include <iostream>

int main(int argc, char *argv[]) 
{
	if (argc == 1) 
	{
		std::cerr << "Error: no parameters\n" << "Usage: ./ScalarConverter <arg>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}