#include "Person.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
Person::Person() {
	name = surname = nik = password = "";
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
void Person::enterAge() {
	cout << "������� �������: ";
	cin >> age;
}
void Person::enterNik() {
	cout << "���������� �������: ";
	cin >> nik;
}
void Person::enterPassword() {
	cout << "���������� ������ ��� ������ ��������: " << endl;
	cin >> password;
}

int Person::getNumber()      { return number; }
string Person::getNik()      { return nik; }
string Person::getPassword() { return password; }

void Person::personInfo() {
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "�������: " << age << endl;
	cout << "�������: " << nik << endl;
	cout << "����������� ������: " << count << endl;
}

ostream& operator<< (ostream& out, Person& person) {
	out << person.number << ". " << person.surname << " " << person.name;
	return out;
}
//----------------------------------------------------------------------------------------------