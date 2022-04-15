#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
BankAccount::BankAccount() {
	AccNumber = owner = id = purpose = password = "";
	money = number = 0;
	transactions1.clear();
	transactions2.clear();
}

void BankAccount::setOwner(string n) {
	owner = n;
}
void BankAccount::enterPurpose() {
	cout << "������� ���������� �����: ";
	cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
	getline(cin, purpose);
}
void BankAccount::enterPassword() {
	cout << "���������� ������ ��� ����� �����: ";
	cin >> password;
}
void BankAccount::enterMoney() {
	cout << "������� �����, ������� ������ �������� �� ����: ";
	cin >> money;
}

string BankAccount::getPassword() { return password; }

void BankAccount::idGeneration() {
	srand(time(0));

	char alphabet[26];
	char letter, number;
	int index = 0, num;

	id = "";
	//���� ��� ���������� ������� ���������� ���������
	for (letter = 'A'; letter <= 'Z'; letter++) {
		alphabet[index] = letter;
		index++;
	}
	//���� ��� ���������� id
	for (int i = 1; i < 20; i++) {
		index = 1 + rand() % 26;//��������� ���������� ����� ��� ������� ��������
		num = 1 + rand() % 10;  //��������� ���������� ����� ��� id

		number = num + '0';
		//�������� �� ���������� ���� ������ �����
		if (number == ':') {
			num = 1 + rand() % 10;
			number = num + '0';
		}
		//������ ������� � id
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

	AccNumber = "";

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
	cout << "����� �� �����: " << money << " USD" << endl;
	cout << "����� �����: " << AccNumber << endl;
	cout << "Id �����: " << id << endl;
	cout << "�������� �����: " << owner << endl;
	cout << "���������� �����: " << purpose << endl;
}

ostream& operator<< (ostream& out, BankAccount& acc) {
	out << acc.number << ". " << acc.purpose;
	return out;
}
//----------------------------------------------------------------------------------------------