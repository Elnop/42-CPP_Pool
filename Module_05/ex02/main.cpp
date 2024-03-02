#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main() {
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm presidential("Zaphod Beeblebrox");

	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << presidential;

	Bureaucrat bureaucrat("Boss", 1);
	Bureaucrat kevin("kevin", 150);
	std::cout << bureaucrat;

	bureaucrat.signForm(shrubbery);
	std::cout << shrubbery;
	bureaucrat.signForm(robotomy);
	bureaucrat.signForm(presidential);
	kevin.signForm(shrubbery);
	kevin.signForm(robotomy);
	kevin.signForm(presidential);

	bureaucrat.executeForm(shrubbery);
	bureaucrat.executeForm(robotomy);
	bureaucrat.executeForm(presidential);
	kevin.executeForm(shrubbery);
	kevin.executeForm(robotomy);
	kevin.executeForm(presidential);

	return 0;
}
