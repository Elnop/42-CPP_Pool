#ifndef PRESIDENTIAL_FORM_H
#define PRESIDENTIAL_FORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm &rhs);
		void execute(const Bureaucrat& executor) const;
};

#endif