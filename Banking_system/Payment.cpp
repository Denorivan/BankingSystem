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
	cout << "Укажите название перевода: ";
	cin.ignore(32767, '\n'); //Игнорируем символы перевода строки "\n" во входящем потоке
	getline(cin, name);
	system("cls");
}

void Payment::printInfo1() {
	cout << "\t\t    Перевод на персональный счёт" << endl << endl;
	cout << "Название перевода: " << name << endl;
	cout << "Дата и время перевода: " << time.wDay << '-' << time.wMonth << '-' << time.wYear <<
		"  " << time.wHour << ':' << time.wMinute << endl << endl;
	cout << "С счёта: " << firstAcc << endl;
	cout << "На счёт: " << secondAcc << endl << endl;
	cout << "Сумма перевода: " << money << " USD" << endl;
	cout << "Остаток средств на счету: " << balance << " USD" << endl;
}
void Payment::printInfo2() {
	cout << "\t\t Перевод на счёт другого пользователя" << endl << endl;
	cout << "Название перевода: " << name << endl;
	cout << "Дата и время перевода: " << time.wDay << '-' << time.wMonth << '-' << time.wYear <<
		"  " << time.wHour << ':' << time.wMinute << endl << endl;
	cout << "Отправитель: " << sender << endl;
	cout << "Получатель: " << recipient << endl << endl;
	cout << "Сумма перевода: " << money << " USD" << endl;
	cout << "Остаток средств на счету: " << balance << " USD" << endl;
}

ostream& operator<< (ostream& out, Payment& pay) {
	out << pay.number << ". " << pay.name;
	return out;
}
//----------------------------------------------------------------------------------------------