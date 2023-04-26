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
	string path = ("Save.txt");
public:
	Phone_book() {
		cout << "����������� �� �������� �����: " << this << endl;
	}

	Phone_book(Phone_book& other) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			arr_contacts[i] = other.arr_contacts[i];
		}
		cout << "����������� ����� �����: " << this << endl;
	}


	void add_contact(Contact contact);
	void delete_contact(int num);
	string search_contact(char* str);
	string to_string_contacts();
	void save_to_file(string _path);

	~Phone_book();
};

