#include "Contact.hpp"
#include <cstdlib>
#include <string>

bool strIsPrint(std::string str)
{
	for(std::string::iterator it = str.begin(); it != str.end();)
	{
		if(!std::isprint(*it))
			return (false);
		else
			it++;
	}
	return (true);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool    Contact::init() {
   	std::cout << "First Name: " << std::flush;
	if (!std::getline(std::cin, _firstName) || !strIsPrint(_firstName) || _firstName.empty())
		return (false);
	std::cout << "Last Name: " << std::flush;
	if (!std::getline(std::cin, _lastName) || !strIsPrint(_lastName) || _lastName.empty())
		return (false);
	std::cout << "Nickname: " << std::flush;
	if (!std::getline(std::cin, _nickname) || !strIsPrint(_nickname) || _nickname.empty())
		return (false);
	std::cout << "Phone Number: " << std::flush;
	if (!std::getline(std::cin, _phoneNumber) || !strIsPrint(_phoneNumber) || _phoneNumber.empty())
		return (false);
	std::cout << "Darkest Secret: " << std::flush;
	if (!std::getline(std::cin, _darkestSecret) || !strIsPrint(_darkestSecret) || _darkestSecret.empty())
		return (false);
	return (true);
}

std::string Contact::_truncten(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::view(int index) const {
    if (_firstName.empty() || _lastName.empty() || _nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << _truncten(_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << _truncten(_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << _truncten(_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const {
    if (_firstName.empty() || _lastName.empty() || _nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
