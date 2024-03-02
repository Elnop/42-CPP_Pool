#include "Intern.h"

int main() {
	Intern tiananas;
	AForm* idable;
	idable = tiananas.makeForm("robotomy request", "Bender");
	std::cout << *idable << std::endl;
	delete idable;
	return 0;
}
