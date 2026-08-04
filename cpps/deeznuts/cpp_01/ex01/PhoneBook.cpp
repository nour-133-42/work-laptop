#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::run()
{
	std::string s;
	this->count = 0;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, s);
		if (s == "ADD")
			this->add();
		else if (s == "SEARCH")
			this->search();
		else if (s == "EXIT")
			break ;
		// else
		// std::cout << "Invalid command. Please enter a valid command." << std::endl
	}
}

void PhoneBook::add()
{
	contact_info();
}

void PhoneBook::search()
{
	display_contacts();
	ask_for_index();
}

void PhoneBook::display_contacts()
{
	int	len;

	if (this->count == 0)
	{
		std::cout << "there is no contact in the phonebook" << std::endl;
		return ;
	}
	if (this->count > 8)
		len = 8;
	else
		len = this->count;
	std::cout << std::setw(10) << "index"
				<< " | " << std::setw(10) << "first name"
				<< " | " << std::setw(10) << "last name"
				<< " | " << std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < len; i++)
	{
		this->print_contact_info(this->contact[i]);
	}
}

void PhoneBook::contact_info()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	if (this->contact[this->count % 8].set_phone_number(phone_number) == 1)
	{
		std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
		return ;
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	this->contact[this->count % 8].set_first_name(first_name);
	this->contact[this->count % 8].set_last_name(last_name);
	this->contact[this->count % 8].set_nickname(nickname);
	this->contact[this->count % 8].set_darkest_secret(darkest_secret);
	this->contact[this->count % 8].set_index(std::string(1, (this->count % 8)
			+ '1'));
	this->count++;
}
void PhoneBook::print_contact_info(Contact contact)
{
	std::cout << std::setw(10) << contact.get_index() << " | ";
	std::cout << std::setw(10) << formatField(contact.get_first_name()) << " | ";
	std::cout << std::setw(10) << formatField(contact.get_last_name()) << " | ";
	std::cout << std::setw(10) << formatField(contact.get_nickname()) << " | ";
	std::cout << '\n';
}

std::string PhoneBook::formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
void PhoneBook::ask_for_index()
{
	std::string s;
	std::cout << "write an endex to display user : ";
	std::getline(std::cin, s);
	this->print_contact_info(this->contact[(s[0] - '0') - 1]);
}
// void PhoneBook::set_count()
// {
// 	this->count = 0;
// }