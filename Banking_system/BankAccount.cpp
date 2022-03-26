#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
void BankAccount::enterOwner() {
	cout << "Введите имя владельца счёта:" << endl;
	getline(cin, owner);
}
void BankAccount::enterPurpose() {
	cout << "Укажите назначение счёта: " << endl;
	getline(cin, purpose);
}
void BankAccount::enterPassword() {
	cout << "Придумайте пароль для этого счёта: " << endl;
	cin >> password;
}

string BankAccount::getPassword() { return password; }

void BankAccount::idGeneration() {
	srand(time(0));

	char alphabet[26];
	char letter, number;
	int index = 0, num;

	id = "";
	//Цикл для заполнения массива английским алфавитом
	for (letter = 'A'; letter <= 'Z'; letter++) {
		alphabet[index] = letter;
		index++;
	}
	//Цикл для заполнения id
	for (int i = 1; i < 20; i++) {
		index = 1 + rand() % 26;//Генерация случайного числа для массива алфавита
		num = 1 + rand() % 10;  //Генерация случайного числа для id

		number = num + '0';
		//Проверка на непонятный знак вместо цифры
		if (number == ':') {
			num = 1 + rand() % 10;
			number = num + '0';
		}
		//Запись символа в id
		if (i % 5 == 0)
			id += '-';
		else if (i % 3 == 0)
			id += number;
		else
			id += alphabet[index];
	}
}
void BankAccount::numberGeneration() {
	string tempStr;
	int tempInt;

	for (int i = 1; i < 20; i++) {
		tempInt = 1 + rand() % 9;
		tempStr = to_string(tempInt);

		if (i % 5 == 0)
			AccNumber += ' ';
		else
			AccNumber += tempStr;
	}
}
void BankAccount::bankAccountInfo() {
	cout << "Денег на счету: " << money << endl;
	cout << "Номер счёта: " << AccNumber << endl;
	cout << "Id счёта: " << id << endl;
	cout << "Владелец счёта:\n" << owner << endl;
	cout << "Назначение счёта:\n" << purpose << endl;
}

ostream& operator<< (ostream& out, BankAccount& acc) {
	out << acc.number << ". " << acc.purpose;
	return out;
}
//----------------------------------------------------------------------------------------------