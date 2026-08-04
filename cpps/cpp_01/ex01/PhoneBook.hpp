#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <bits/stdc++.h>

class PhoneBook
{
  private:
	Contact contact[8];
	int count;

  public:
	void run();
	void add();
	void search();
};
#endif