#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	firstAcc = secondAcc = recipient = sender = paymentName = "";
	money = number = 0;
}

void Payment::enterPaymentName() {
	cout << "Укажите название перевода: ";
	cin.ignore(32767, '\n'); //Игнорируем символы перевода строки "\n" во входящем потоке
	getline(cin, paymentName);
	system("cls");
}

void Payment::printInfo1() {
	cout << "Название перевода: " << paymentName << endl << endl;
	cout << "С счёта: " << firstAcc << endl;
	cout << "На счёт: " << secondAcc << endl << endl;
	cout << "Сумма перевода: " << money << endl;
}

void Payment::printInfo2() {
	cout << "Название перевода: " << paymentName << endl << endl;
	cout << "Отправитель: " << sender << endl;
	cout << "Получатель: " << recipient << endl << endl;
	cout << "Сумма перевода: " << money << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.paymentName;
	return out;
}
//----------------------------------------------------------------------------------------------