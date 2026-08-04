#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::run()
{
	std::string s;
	std::getline(std::cin, s);
	if (s == "ADD")
		add();
}

void PhoneBook::add()
{
	int		i;
	Contact	contact;

	std::string first_name;
	std::getline(std::cin, first_name);
	contact.set_first_name(first_name);
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
}
