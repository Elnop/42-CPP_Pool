#include "Intern.h"
#include "Bureaucrat.h"

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

AForm*	Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

typedef AForm* (*t_makeForm)(std::string);

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formRequests[3] = {"robotomy request",
		"presidential pardon",
		"shrubbery creation"};
	AForm* (Intern::*makeList[3])(std::string) = {&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm};
	for (int i = 0; i < 3; i++) {
		if (formName == formRequests[i]) {
			std::cout << "Intern creates " + formName << std::endl;
			return (this->*makeList[i])(target);
		}
	}
	throw Intern::InvalidFormNameException();
}

const char* Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name";
}