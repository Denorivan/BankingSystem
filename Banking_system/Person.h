#pragma once

#include <string>

#include "BankAccount.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class Person {
private:
	string name, surname;
	int age, count = 0;
public:
	int number;

	void enterName();
	void enterSurname();
	void enterAge();

	void personInfo();
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------