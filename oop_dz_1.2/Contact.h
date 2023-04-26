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
		cout << "����������� �������: " << this << endl;
	}

	Contact() {};

	Contact(const Contact& other) {
		if (other.name) {
			strcpy_s(name, strlen(other.name) + 1, other.name);
		}
		if (other.lastname) {
			strcpy_s(lastname, strlen(other.lastname) + 1, other.lastname);
		}
		if (other.homephone) {
			strcpy_s(homephone, strlen(other.homephone) + 1, other.homephone);
		}
		if (other.workphone) {
			strcpy_s(workphone, strlen(other.workphone) + 1, other.workphone);
		}
		if (other.mobilephone) {
			strcpy_s(mobilephone, strlen(other.mobilephone) + 1, other.mobilephone);
		}
		if (other.info) {
			strcpy_s(info, strlen(other.info) + 1, other.info);
		}
	}
		 
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