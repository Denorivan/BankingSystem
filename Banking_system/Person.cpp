#include "Person.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
Person::Person() {
	name = surname = nik = password = fullName = "";
	number = age = count = 0;
}

void Person::enterName() {
	cout << "������� ���: ";
	cin >> name;
}
void Person::enterSurname() {
	cout << "������� �������: ";
	cin >> surname;
}
void Person::enterPatronymic() {
	cout << "������� ��������: ";
	cin >> patronymic;

	fullName = surname + " " + name + " " + patronymic;
}
void Person::enterAge() {
	cout << "������� �������: ";
	cin >> age;
}
void Person::enterNik() {
	cout << "���������� �������: ";
	cin >> nik;
}
void Person::enterPassword() {
	cout << "���������� ������ ��� ������ ��������: ";
	cin >> password;
}

int Person::getNumber()       { return number; }
int Person::getCount()        { return count; }
string Person::getNik()       { return nik; }
string Person::getFullName()  { return fullName; }
string Person::getPassword()  { return password; }

void Person::countIncrement() { count++; }
void Person::countDicrement() { count--; }

void Person::clearBankAccs() {
	personAccs.clear();
	count = 0;
}

void Person::personInfo() {
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "��������: " << patronymic << endl;
	cout << "�������: " << age << endl;
	cout << "�������: " << nik << endl;
	cout << "���������� ������: " << count << endl;
}

ostream& operator<< (ostream& out, Person& person) {
	out << person.number << ". " << person.surname << " " << person.name << " " << person.patronymic;
	return out;
}
//----------------------------------------------------------------------------------------------