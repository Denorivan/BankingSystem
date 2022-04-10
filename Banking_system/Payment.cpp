#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	recipient = sender = paymentName = "";
	money = 0;
}

void Payment::enterPaymentName() {
	cout << "Укажите название перевода: ";
	cin.ignore(32767, '\n'); //Игнорируем символы перевода строки "\n" во входящем потоке
	getline(cin, paymentName);
}

void Payment::printInfo() {
	cout << "Название перевода: " << paymentName << endl << endl;
	cout << "Отправитель: " << sender << endl;
	cout << "Получатель: " << recipient << endl << endl;
	cout << "Сумма перевода: " << money << endl;
}
//----------------------------------------------------------------------------------------------