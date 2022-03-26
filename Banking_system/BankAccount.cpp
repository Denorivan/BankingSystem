#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
void BankAccount::enterOwner() {
	cout << "������� ��� ��������� �����:" << endl;
	getline(cin, owner);
}
void BankAccount::enterPurpose() {
	cout << "������� ���������� �����: " << endl;
	getline(cin, purpose);
}
void BankAccount::enterPassword() {
	cout << "���������� ������ ��� ����� �����: " << endl;
	cin >> password;
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
	cout << "����� �� �����: " << money << endl;
	cout << "����� �����: " << AccNumber << endl;
	cout << "Id �����: " << id << endl;
	cout << "�������� �����:\n" << owner << endl;
	cout << "���������� �����:\n" << purpose << endl;
}

ostream& operator<< (ostream& out, BankAccount& acc) {
	out << acc.number << ". " << acc.purpose;
	return out;
}
//----------------------------------------------------------------------------------------------