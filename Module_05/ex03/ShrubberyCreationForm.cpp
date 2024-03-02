#include "ShrubberyCreationForm.h"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs) {
	AForm::operator=(rhs);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::ofstream file;
	std::string filename = this->getTarget() + "_shrubbery";
	file.open(filename.c_str());
	if (!file.is_open())
		throw FileNotOpenException();
	file << "      /\\\n";
	file << "     /\\*\\\n";
	file << "    /\\O\\*\\\n";
	file << "   /*/\\/\\/\\\n";
	file << "  /\\O\\/\\*\\/\\\n";
	file << " /\\*\\/\\*\\/\\/\\\n";
	file << "/\\O\\/\\/*/\\/O/\\\n";
	file << "      ||\n";
	file << "      ||\n";
	file << "      ||\n";
	file << std::endl;
	file.close();
}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "File not open";
}

