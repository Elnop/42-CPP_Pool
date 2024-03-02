#ifndef SHRUBBERY_FORM_H
#define SHRUBBERY_FORM_H

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
		void execute(const Bureaucrat& executor) const;
		class FileNotOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif