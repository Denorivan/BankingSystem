#include "Payment.h"
//----------------------------------------------------------------------------------------------
Payment::Payment() {
	firstAcc = secondAcc = recipient = sender = paymentName = "";
	money = number = balance = 0;
}

void Payment::enterPaymentName() {
	cout << "Укажите название перевода: ";
	cin.ignore(32767, '\n'); //Игнорируем символы перевода строки "\n" во входящем потоке
	getline(cin, paymentName);
	system("cls");
}

void Payment::printInfo1() {
	cout << "Перевод на персональный счёт" << endl;
	cout << "Название перевода: " << paymentName << endl << endl;
	cout << "С счёта: " << firstAcc << endl;
	cout << "На счёт: " << secondAcc << endl << endl;
	cout << "Сумма перевода: " << money << " USD" << endl;
	cout << "Остаток средств на счету: " << balance << " USD" << endl;
}

void Payment::printInfo2() {
	cout << "Перевод на счёт другого пользователя" << endl;
	cout << "Название перевода: " << paymentName << endl << endl;
	cout << "Отправитель: " << sender << endl;
	cout << "Получатель: " << recipient << endl << endl;
	cout << "Сумма перевода: " << money << " USD" << endl;
	cout << "Остаток средств на счету: " << balance << " USD" << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.paymentName;
	return out;
}
//----------------------------------------------------------------------------------------------