#include "Harl.h"

int main( void ) {

    std::string input;
    Harl        harl;

    std::cout << "Enter a level: " << std::flush;
	while (getline(std::cin, input) && input.compare("EXIT"))
    {
        harl.complain(input);
   		std::cout << "Enter a level: " << std::flush;
    };

    return 0;
}