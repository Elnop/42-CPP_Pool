#include "AForm.h"

AForm::AForm() : name("noname"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(AForm &rhs) {
	std::cout << "Form assignation operator called" << std::endl;
	this->isSigned = rhs.isSigned;
	return *this;
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::string AForm::getTarget() const {
	return this->target;
}

std::ostream& operator<<( std::ostream& o, const AForm& rhs) {
	o << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExecute() << ", is signed " << rhs.getIsSigned() << std::endl;
	return o;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}