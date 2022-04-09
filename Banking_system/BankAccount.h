#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class BankAccount {
public:
	string AccNumber, owner, id, purpose, password;
	double money;
	int number;

	void enterPurpose();     //Метод для ввода назначения счёта
	void enterPassword();    //Метод для ввода пароля счёта
	void enterMoney();       //Метод для указания денег на счету 

	string getPassword();    //Метод для получения пароля

	void idGeneration();     //Метод для генерации айди счёта
	void numberGeneration(); //Метод для генерации номера счёта
	void bankAccountInfo();  //Метод для вывода информации про счёт
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------