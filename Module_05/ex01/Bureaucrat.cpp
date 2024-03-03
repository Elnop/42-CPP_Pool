#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

Bureaucrat::Bureaucrat() : name("noname"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	this->grade = rhs.grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

void Bureaucrat::decrementGrade() {
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

int Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
		return 1;
	}
	catch (std::exception &e) {
		std::cout << this->name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		return 0;
	}
}