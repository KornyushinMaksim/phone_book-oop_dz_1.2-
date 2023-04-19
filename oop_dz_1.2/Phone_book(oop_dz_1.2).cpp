//	Задание.
//	Создайте приложение "Телефонная книга".Необходимо
//	хранить данные об абоненте(ФИО, домашний телефон,
//	рабочий телефон, мобильный телефон, дополнительная
//	информация о контакте) внутри соответствующего клас -
//	са.Наполните класс переменными - членами, функция -
//	ми - членами, конструкторами, inline - функциями - членами,
//	используйте инициализаторы, реализуйте деструктор.
//	Обязательно необходимо выделять динамически память
//	под ФИО.Предоставьте пользователю возможность до -
//	бавлять новых абонентов, удалять абонентов, искать або -
//	нентов по ФИО, показывать всех абонентов, сохранять
//	информацию в файл и загружать из файла.


#include <iostream>
#include <string.h>
#include "Contact.h"
#include "Phone_book.h"

Contact func_add_contact() {
	char name[30];
	char lastname[30];
	char homephone[11];
	char workphone[11];
	char mobilephone[11];
	char info[100];
	cin.get();			//bag
	cout << "Добавление контакта\nИмя: ";
	cin.getline(name, 30);
	cout << "Фамилия: ";
	cin.getline(lastname, 30);
	cout << "Домашний телефон: ";
	cin.getline(homephone, 11);
	cout << "Рабочий телефон: ";
	cin.getline(workphone, 11);
	cout << "Мобильный телефон: ";
	cin.getline(mobilephone, 11);
	cout << "Инфо: ";
	cin.getline(info, 100);
	return Contact(name, lastname, homephone, workphone, mobilephone, info);
}

int func_delete_contact() {
	cout << "Выберите номер для удаления: ";
	int num;
	cin >> num;
	return num;
}

string func_search_contact() {
	bool flag = true;
	char str[] = { "выход" };
	while (flag) {
		cout << "Введите имя/фамилию для поиска или \"выход\": ";
		char search[30];
		cin.getline(search, 30);
		if (strstr(str, search)) {
			flag = false;
		}
		else {
			return search;
		}
	}
}

void _interface(Phone_book& cont, Contact& pers) {
	bool flag = true;
	while (flag) {
		cout << "1. Добавление контакта\n2. Удалить\n3. Показать всех\n4. Поиск\n5. Сохранить\n6. Завершить\n";
		int key;
		cin >> key;
		switch (key) {
		case 1:
			cont.add_contact(func_add_contact());
			break;
		case 2:
			cont.delete_contact(func_delete_contact());
			break;
		case 3:
			cout << cont.to_string_contacts();
			break;
		case 4:
			cout << cont.search_contact(func_search_contact(), pers);
			break;
		case 5:
			break;
		case 6:
			flag = false;
			break;
		}
	}
}

int main()
{
	system("chcp 1251 >nul");
	Contact pers;
	Phone_book cont;
	_interface(cont, pers);
}