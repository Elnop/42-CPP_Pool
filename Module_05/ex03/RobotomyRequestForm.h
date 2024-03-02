#ifndef ROBOTOMY_FORM_H
#define ROBOTOMY_FORM_H

#include "AForm.h"

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);
		void execute(const Bureaucrat& executor) const;
};

#endif