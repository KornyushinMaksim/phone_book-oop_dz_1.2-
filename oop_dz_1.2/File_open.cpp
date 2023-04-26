#include "File_open.h"

Phone_book File_open::open_file(string _path)
{
	Phone_book cont;
	in.open(_path);
	if (in.is_open()) {
		while (!in.eof()) {
			string pole_class[6];
			for (int i = 0; i < 6; i++) {
				string str;
				getline(in, str);
				pole_class[i] = str;
			}
			Contact pers(pole_class[0].c_str(), pole_class[1].c_str(), pole_class[2].c_str(), pole_class[3].c_str(), pole_class[4].c_str(), pole_class[5].c_str());
			cont.add_contact(pers);
			//pers.get_name((char*)pole_class[0].c_str());
			//pers.get_lastname((char*)pole_class[1].c_str());
			//pers.get_homephone((char*)pole_class[2].c_str());
			//pers.get_workphone((char*)pole_class[3].c_str());
			//pers.get_mobilephone((char*)pole_class[4].c_str());
			//pers.get_info((char*)pole_class[5].c_str());
		}
	}
	in.close();
	return cont;
}
