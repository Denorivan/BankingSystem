#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	firstAcc = secondAcc = recipient = sender = name = "";
	money = number = balance = 0;
}

void Payment::getPaymentTime() { GetLocalTime(&time); }

void Payment::setFirstAcc(string n)  { firstAcc = n; }
void Payment::setSecondAcc(string n) { secondAcc = n; }
void Payment::setResipient(string n) { recipient = n; }
void Payment::setSender(string n)    { sender = n; }
void Payment::setMoney(double n)     { money = n; }
void Payment::setBalance(double n)   { balance = n; }

void Payment::enterPaymentName() {
	cout << "������� �������� ��������: ";
	cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
	getline(cin, name);
	system("cls");
}

void Payment::printInfo1() {
	cout << "\t\t    ������� �� ������������ ����" << endl << endl;
	cout << "�������� ��������: " << name << endl;
	cout << "���� � ����� ��������: " << time.wDay << '-' << time.wMonth << '-' << time.wYear <<
		"  " << time.wHour << ':' << time.wMinute << endl << endl;
	cout << "� �����: " << firstAcc << endl;
	cout << "�� ����: " << secondAcc << endl << endl;
	cout << "����� ��������: " << money << " USD" << endl;
	cout << "������� ������� �� �����: " << balance << " USD" << endl;
}
void Payment::printInfo2() {
	cout << "\t\t ������� �� ���� ������� ������������" << endl << endl;
	cout << "�������� ��������: " << name << endl;
	cout << "���� � ����� ��������: " << time.wDay << '-' << time.wMonth << '-' << time.wYear <<
		"  " << time.wHour << ':' << time.wMinute << endl << endl;
	cout << "�����������: " << sender << endl;
	cout << "����������: " << recipient << endl << endl;
	cout << "����� ��������: " << money << " USD" << endl;
	cout << "������� ������� �� �����: " << balance << " USD" << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.name;
	return out;
}
//----------------------------------------------------------------------------------------------