#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	recipient = sender = paymentName = "";
	money = 0;
}

void Payment::enterPaymentName() {
	cout << "������� �������� ��������: ";
	cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
	getline(cin, paymentName);
}

void Payment::printInfo() {
	cout << "�������� ��������: " << paymentName << endl << endl;
	cout << "�����������: " << sender << endl;
	cout << "����������: " << recipient << endl << endl;
	cout << "����� ��������: " << money << endl;
}
//----------------------------------------------------------------------------------------------