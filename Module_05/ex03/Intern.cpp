#include "Intern.h"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}
Intern::Intern(const Intern& other) { 
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}
Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}
Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignation operator called" << std::endl;
	(void)other;
	return *this;
}
AForm* Intern::makeForm(std::string formName, std::string target) {
	std::cout << "Intern creates " + formName << std::endl;
	if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	else if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else
		throw Intern::InvalidFormNameException();
}

const char* Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name";
}