#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void executeForm(AForm const & form);
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		Bureaucrat &operator=(Bureaucrat &rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// surcharge ostream to print bureaucrat
std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs);

#endif