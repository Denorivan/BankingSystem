#include "Person.h"

#include <iostream>
#include <Windows.h>
#include <ctime>
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
void Person::enterName() {
	cout << "Введите имя: ";
	cin >> name;
}
void Person::enterSurname() {
	cout << "Введите фамилию: ";
	cin >> surname;
}
void Person::enterAge() {
	cout << "Укажите возраст: ";
	cin >> age;
}

void Person::personInfo() {
	cout << "Имя: " << name << endl;
	cout << "Фамилия: " << surname << endl;
	cout << "Возраст: " << age << endl;
	cout << "Количетство счетов: " << count << endl;
}

ostream& operator<< (ostream& out, Person& person) {
	out << person.number << ". " << person.surname << " " << person.name;
	return out;
}
//----------------------------------------------------------------------------------------------