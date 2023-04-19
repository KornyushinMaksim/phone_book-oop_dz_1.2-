#pragma once
#include <string>
#include "Contact.h"
class Phone_book
{
private:
	Contact* arr_contacts;
	int size = 0;
public:
	void add_contact(Contact contact);
	void delete_contact(int num);
	string search_contact(string str, Contact& pers);
	string to_string_contacts();

};

