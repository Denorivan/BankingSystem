#include "Person.h"

#include <iostream>
#include <Windows.h>
#include <ctime>
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
void Person::enterName() {
	cout << "������� ���: ";
	cin >> name;
}
void Person::enterSurname() {
	cout << "������� �������: ";
	cin >> surname;
}
void Person::enterAge() {
	cout << "������� �������: ";
	cin >> age;
}

void Person::personInfo() {
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
	cout << "����������� ������: " << count << endl;
}

ostream& operator<< (ostream& out, Person& person) {
	out << person.number << ". " << person.surname << " " << person.name;
	return out;
}
//----------------------------------------------------------------------------------------------