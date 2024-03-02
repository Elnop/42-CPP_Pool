#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

		std::string _truncten(std::string str) const;

	public:
		Contact();
		~Contact();
		bool    init();
		void    view(int index) const;
		void    display(int index) const;
};

#endif