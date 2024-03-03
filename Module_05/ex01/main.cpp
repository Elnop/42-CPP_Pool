#include "Form.hpp"

int main() {
	std::cout << std::endl << "----- Constructors -----" << std::endl;
	Form f1("f1", 1, 1);
	Form f2("f2", 150, 150);
	std::cout << f1 << f2;

	std::cout << std::endl << "----- Copy -----" << std::endl;
	Form f3(f1);
	std::cout << f3;

	std::cout << std::endl << "----- Assignation -----" << std::endl;
	f3 = f2;
	std::cout << f3;

	std::cout << std::endl << "----- Exceptions -----" << std::endl;
	try {
		Form f4("f4", 0, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f5("f5", 151, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f6("f6", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form f7("f7", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "----- Be signed -----" << std::endl;
	Bureaucrat b1("b1", 2);
	Bureaucrat b2("b2", 1);
	b1.signForm(f1);
	b2.signForm(f1);
	std::cout << std::endl << "----- Destructors -----" << std::endl;
	return 0;
}