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
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat &rhs);
		std::string getName() const;
		int getGrade() const;
		void executeForm(AForm const & form);
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};
};

// surcharge ostream to print bureaucrat
std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs);

#endif