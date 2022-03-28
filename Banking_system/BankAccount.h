#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class BankAccount
{
private:
	string id, purpose, password;
public:
	string AccNumber, owner;
	double money;
	int number;

	void enterPurpose();
	void enterPassword();
	void enterMoney();

	string getPassword();

	void idGeneration();     //Метод для генерации айди счёта
	void numberGeneration(); //Метод для генерации номера счёта
	void bankAccountInfo();  //Метод для вывода информации про счёт
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------