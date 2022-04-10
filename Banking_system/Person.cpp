#include "Person.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
Person::Person() {
	name = surname = nik = password = "";
	number = age = count = 0;
}

void Person::enterName() {
	cout << "Введите имя: ";
	cin >> name;
}
void Person::enterSurname() {
	cout << "Введите фамилию: ";
	cin >> surname;
}
void Person::enterPatronymic() {
	cout << "Введите отчество: ";
	cin >> patronymic;
}
void Person::enterAge() {
	cout << "Укажите возраст: ";
	cin >> age;
}
void Person::enterNik() {
	cout << "Придумайте никнейм: ";
	cin >> nik;
}
void Person::enterPassword() {
	cout << "Придумайте пароль для своего аккаунта: ";
	cin >> password;
}

int Person::getNumber()      { return number; }
string Person::getNik()      { return nik; }
string Person::getPassword() { return password; }

void Person::personInfo() {
	cout << "Имя: " << name << endl;
	cout << "Фамилия: " << surname << endl;
	cout << "Отчество: " << patronymic << endl;
	cout << "Возраст: " << age << endl;
	cout << "Никнейм: " << nik << endl;
	cout << "Количество счетов: " << count << endl;
}

ostream& operator<< (ostream& out, Person& person) {
	out << person.number << ". " << person.surname << " " << person.name << " " << person.patronymic;
	return out;
}
//----------------------------------------------------------------------------------------------