#include "Bureaucrat.h"

int main() {
	std::cout << std::endl << "----- Constructors -----" << std::endl;
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	std::cout << b1 << b2 << std::endl;

	std::cout << std::endl << "----- Copy -----" << std::endl;
	Bureaucrat b3(b1);
	std::cout << b3 << std::endl;

	std::cout << std::endl << "----- Assignation -----" << std::endl;
	b3 = b2;
	std::cout << b3 << std::endl;

	std::cout << std::endl << "----- Exceptions -----" << std::endl;
	try {
		Bureaucrat b4("b4", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat b5("b5", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "----- Increment -----" << std::endl;
	try {
		b1.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;

	std::cout << std::endl << "----- Decrement -----" << std::endl;
	try {
		b2.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;

	return 0;
}