#pragma once
#include <iostream>
#include <string>
#include "Phone_book.h"
using namespace std;

class File_open
{
private:
	//ofstream fout;
	ifstream in;
public:
	Phone_book open_file(string _path);
};

