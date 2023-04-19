#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Contact.h"
class Phone_book
{
private:
	Contact* arr_contacts;
	int size = 0;
	string path;
public:
	void add_contact(Contact contact);
	void delete_contact(int num);
	string search_contact(char* str/*, Phone_book& pers*/);
	string to_string_contacts();
	void save_to_file();
};

