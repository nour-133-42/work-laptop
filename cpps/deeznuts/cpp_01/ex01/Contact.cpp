#include "Contact.hpp"

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}
std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}
std::string Contact::get_index()
{
	return (std::string(this->index));
}

void Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

int Contact::set_phone_number(std::string phone_number)
{
	for (std::size_t i = 0; i < phone_number.length(); i++)
		if (!isdigit(static_cast<unsigned char>(phone_number[i])))
			return (1);
	this->phone_number = phone_number;
	return (0);
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

void Contact::set_index(std::string index)
{
	this->index = index;
}
