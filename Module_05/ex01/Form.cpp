#include "Form.h"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form &rhs) {
	std::cout << "Form assignation operator called" << std::endl;
	this->isSigned = rhs.isSigned;
	return *this;
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& rhs) {
	if (rhs.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<( std::ostream& o, const Form& rhs) {
	o << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() << ", form grade to execute " << rhs.getGradeToExecute() << ", is signed " << rhs.getIsSigned() << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}