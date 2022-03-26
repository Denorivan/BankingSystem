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
protected:
	string id, AccNumber, owner, purpose, password;
	double money;
public:
	int number;

	void enterOwner();
	void enterPurpose();
	void enterPassword();

	string getPassword();

	void idGeneration();     //Метод для генерации айди счёта
	void numberGeneration(); //Метод для генерации номера счёта
	void bankAccountInfo();  //Метод для вывода информации про счёт
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------