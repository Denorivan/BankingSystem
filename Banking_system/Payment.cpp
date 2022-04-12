#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	firstAcc = secondAcc = recipient = sender = paymentName = "";
	money = number = balance = 0;
}

void Payment::enterPaymentName() {
	cout << "������� �������� ��������: ";
	cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
	getline(cin, paymentName);
	system("cls");
}

void Payment::printInfo1() {
	cout << "������� �� ������������ ����" << endl;
	cout << "�������� ��������: " << paymentName << endl << endl;
	cout << "� �����: " << firstAcc << endl;
	cout << "�� ����: " << secondAcc << endl << endl;
	cout << "����� ��������: " << money << " USD" << endl;
	cout << "������� ������� �� �����: " << balance << " USD" << endl;
}

void Payment::printInfo2() {
	cout << "������� �� ���� ������� ������������" << endl;
	cout << "�������� ��������: " << paymentName << endl << endl;
	cout << "�����������: " << sender << endl;
	cout << "����������: " << recipient << endl << endl;
	cout << "����� ��������: " << money << " USD" << endl;
	cout << "������� ������� �� �����: " << balance << " USD" << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.paymentName;
	return out;
}
//----------------------------------------------------------------------------------------------