#include "Phone_book.h"
#include "Contact.h"
#include "File_open.h"


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

//void Phone_book::add_contact(File_open open)
//{
//	Contact* temp = new Contact[size + 1];
//	for (int i = 0; i < size; i++) {
//		temp[i] = arr_contacts[i];
//	}
//	temp[size] = contact;
//	delete[] arr_contacts;
//	arr_contacts = temp;
//	size++;
//}

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

string Phone_book::search_contact(char* str)
{
	for (int i = 0; i < size; i++) {
		if (arr_contacts[i].set_name() == str || arr_contacts[i].set_lastname() == str) {
			string s = "���������� ���...";
			return s;
		}
		else {
			return arr_contacts[i].to_string();
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

void Phone_book::save_to_file(string _path)
{
	path = _path;
	fstream fout;
	fout.open(path);
	if (fout.is_open()) {
		for (int i = 0; i < size; i++) {
			fout << arr_contacts[i].to_string();
		}
		cout << "file saved" << endl;
	}
	fout.close();
	system("pause");
}

Phone_book::~Phone_book()
{
	cout << "delete phone_book: " << this << endl;
	if (arr_contacts) {
		delete[] arr_contacts;
	}
}

