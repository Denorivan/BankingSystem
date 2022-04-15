#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <vector>

#include "Payment.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class BankAccount {
public:
	string AccNumber, owner, id, purpose, password;
	double money;
	int number;

	vector<Payment> transactions1; //Вектор для хранения транзакций между своими счетами
	vector<Payment> transactions2; //Вектор для хранения транзакций между счетами других пользователей

	BankAccount();           //Конструктор по умолчанию

	void setOwner(string n); //Сеттер для владельца счёта
	void enterPurpose();     //Метод для ввода назначения счёта
	void enterPassword();    //Метод для ввода пароля счёта
	void enterMoney();       //Метод для указания денег на счету 

	string getPassword();    //Геттер для пароля счёта

	void idGeneration();     //Метод для генерации айди счёта
	void numberGeneration(); //Метод для генерации номера счёта
	void bankAccountInfo();  //Метод для вывода информации про счёт
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------