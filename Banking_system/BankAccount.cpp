#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
void BankAccount::enterOwner() {
	cout << "������� ��� ��������� �����: ";
	getline(cin, owner);
}

void BankAccount::enterPurpose() {
	cout << "������� ���������� �����: " << endl;
	getline(cin, purpose);
}

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
			number += ' ';
		else
			number += tempStr;
	}
}

void BankAccount::bankAccountInfo() {
	cout << "����� �� �����: " << money << endl;
	cout << "����� �����: " << number << endl;
	cout << "Id �����: " << id << endl;
	cout << "�������� �����: " << owner << endl;
	cout << "���������� �����: " << purpose << endl;
}
//----------------------------------------------------------------------------------------------