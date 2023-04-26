#pragma once
#include <string>
#include <iostream>
using namespace std;

class Contact
{
private:
	char* name;
	char* lastname;
	char* homephone;
	char* workphone;
	char* mobilephone;
	char* info;
public:

	inline void _if_for_construstot(char* name, const char* _name) {
		if (name) {
			strcpy_s(name, strlen(_name) + 1, _name);
		}
	}

	Contact(const char* _name, const char* _lastname, const char* _homephone, const char* _workphone, const char* _mobilephone, const char* _info) :
		name{ _name ? new char[strlen(_name) + 1] : nullptr },
		lastname{ _lastname ? new char[strlen(_lastname) + 1] : nullptr },
		homephone{ _homephone ? new char[strlen(_homephone) + 1] : nullptr },
		workphone{ _workphone ? new char[strlen(_workphone) + 1] : nullptr },
		mobilephone{ _mobilephone ? new char[strlen(_mobilephone) + 1] : nullptr },
		info{ _info ? new char[strlen(_info) + 1] : nullptr }
	{
		_if_for_construstot(name, _name);
		_if_for_construstot(lastname, _lastname);
		_if_for_construstot(homephone, _homephone);
		_if_for_construstot(workphone, _workphone);
		_if_for_construstot(mobilephone, _mobilephone);
		_if_for_construstot(info, _info);
		cout << "конструктор контакт: " << this << endl;
	}

	Contact() : Contact{ NULL, NULL,  NULL,  NULL, NULL,  NULL } {
		cout << "конструктор по умолчанию контакт: " << this << endl;
	};
		 
	char* set_name();
	void get_name(char* _name);

	char* set_lastname();
	void get_lastname(char* _lastname);

	char* set_homephone();
	void get_homephone(char* _homephone);

	char* set_workphone();
	void get_workphone(char* _workphone);

	char* set_mobilephone();
	void get_mobilephone(char* _mobilephone);

	char* set_info();
	void get_info(char* _info);

	string to_string();

	~Contact();
};