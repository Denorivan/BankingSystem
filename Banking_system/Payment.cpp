#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	firstAcc = secondAcc = recipient = sender = paymentName = "";
	money = number = 0;
}

void Payment::enterPaymentName() {
	cout << "������� �������� ��������: ";
	cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
	getline(cin, paymentName);
	system("cls");
}

void Payment::printInfo1() {
	cout << "�������� ��������: " << paymentName << endl << endl;
	cout << "� �����: " << firstAcc << endl;
	cout << "�� ����: " << secondAcc << endl << endl;
	cout << "����� ��������: " << money << endl;
}

void Payment::printInfo2() {
	cout << "�������� ��������: " << paymentName << endl << endl;
	cout << "�����������: " << sender << endl;
	cout << "����������: " << recipient << endl << endl;
	cout << "����� ��������: " << money << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.paymentName;
	return out;
}
//----------------------------------------------------------------------------------------------