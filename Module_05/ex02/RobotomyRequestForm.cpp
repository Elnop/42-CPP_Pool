#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs) {
	this->AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	if (rand() % 2)
		std::cout << "*drilling noises* " << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "robotomize " << this->getTarget() << " failed" << std::endl;
}
