#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <bits/stdc++.h>

class PhoneBook
{
  private:
	Contact contact[8];
	int count;
	void contact_info();

  public:
	void run();
	void add();
	void search();
	void display_contacts();
	void print_contact_info(Contact contact);
	std::string formatField(const std::string &str);
	void ask_for_index();
	// void set_count();
};

#endif