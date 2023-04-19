#include "Phone_book.h"
#include "Contact.h"

void Phone_book::add_contact(Contact contact)
{
	Contact* temp = new Contact[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = arr_contacts[i];
	}
	temp[size] = contact;
	delete[] arr_contacts;
	arr_contacts = temp;
	size++;
}

void Phone_book::delete_contact(int num)
{
	Contact* temp = new Contact[size - 1];
	for (int i = 0; i < num - 1; i++) {
		temp[i] = arr_contacts[i];
	}
	for (int i = num; i < size; i++) {
		temp[i - 1] = arr_contacts[i];
	}
	delete[] arr_contacts;
	arr_contacts = temp;
	size--;
}

string Phone_book::search_contact(string str, Contact& pers)
{
	for (int i = 0; i < size; i++) {
		if (pers.set_name() == str || pers.set_lastname() == str) {
			return pers.to_string();
		}
		else {
			string s = "Совпадений нет...";
			return s;
		}
	}
}

string Phone_book::to_string_contacts()
{
	string s = "";
	for (int i = 0; i < size; i++) {
		s.append(arr_contacts[i].to_string());
		s.append("\n");
	}
	return s;
}

