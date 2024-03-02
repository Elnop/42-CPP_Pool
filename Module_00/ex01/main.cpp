#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void    addContact(Contact contacts[8]) {
    static int  i = 0;
    if (!contacts[i].init())
		return ;
	if (i < 7)
    	i++;
	else
		i = 0;
}

void	search(Contact contacts[8])
{
	std::string	index;

	std::cout << "============= PHONBOOK CONTACTS =============" << std::endl;
    for (size_t i = 0; i < 8; i++)
        contacts[i].view(i + 1);
    std::cout << "index to display > " << std::flush;
	getline(std::cin, index);
	if (index[0] - '0' < 1 || index[0] - '0' > 8)
	{
		std::cout << "\033[1;91mInvalid index\033[0m" << std::endl;
		return ;
	}
	contacts[index[0] - '0' - 1].display(index[0] - '0');
}

void	welcome()
{
    std::cout << "\033[0;32m Welcome to Your Awesome PhoneBook" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: Add a contact." << std::endl;
    std::cout << "SEARCH\t: Search for a contact." << std::endl;
    std::cout << "EXIT\t: Quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------\033[0m" << std::endl;
}

int main() {
	std::string	cmd;
	PhoneBook	phonebook;

	welcome();
	std::cout << "> " << std::flush;
	while (getline(std::cin,cmd) && cmd.compare("EXIT"))
	{
		if (!cmd.compare("ADD"))
			addContact(phonebook.contacts);
		if (!cmd.compare("SEARCH"))
			search(phonebook.contacts);
		std::cout << "> " << std::flush;
	}
	return 0;
}
