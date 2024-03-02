#include "Harl.h"

int main( int ac, char **av ) {

    if (ac != 2) {
        return (std::cout << "Usage: ./harlFilter \"level\"\n", 1);
    }
    std::string input = av[1];
    Harl        harl;

    harl.complain(input);

    return 0;
}