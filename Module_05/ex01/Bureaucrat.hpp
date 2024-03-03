#pragma once

#include <string>
#include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat &rhs);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		int signForm(Form &form);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs);

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
		std::string			target;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
		AForm(const AForm& rhs);
		~AForm();
		AForm &operator=(AForm &rhs);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& rhs);
		std::string getTarget() const;
		virtual void execute(const Bureaucrat& executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};
