#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <vector>

#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class Person {
private:
	string name, surname, nik, password;
	int age, count = 0;
public:
	int number;
	vector<BankAccount> personAccs;

	void enterName();
	void enterSurname();
	void enterAge();
	void enterNik();
	void enterPassword();

	string getNik();
	string getPassword();

	void personInfo();
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------