#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "AForm.h"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);
		AForm* makeRobotomyRequestForm(std::string target);
		AForm* makePresidentialPardonForm(std::string target);
		AForm* makeShrubberyCreationForm(std::string target);
		AForm* makeForm(std::string formName, std::string target);
		class InvalidFormNameException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};