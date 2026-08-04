#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <bits/stdc++.h>
class Contact
{
  public:
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	std::string get_index();
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	int set_phone_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);
	void set_index(std::string index);

  private:
	std::string index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};
#endif