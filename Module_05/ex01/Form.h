#ifndef FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& rhs);
		~Form();
		Form &operator=(Form &rhs);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& rhs);

		/* ---------------- Exception Classes ---------------- */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};
};

std::ostream& operator<<( std::ostream& o, const Form& rhs);

#endif