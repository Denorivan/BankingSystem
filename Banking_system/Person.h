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
	int age;
public:
	int number, count;
	vector<BankAccount> personAccs; //Вектор для хранения счетов пользователя
	vector<string> vecForNums;      //Вектор для хранения номеров счетов пользователя

	Person();            //Конструктор по умолчанию

	void enterName();    //Метод для ввода имени
	void enterSurname(); //Метод для ввода фамилии
	void enterAge();     //Метод для ввода возраста
	void enterNik();     //Метод для ввода никнейма
	void enterPassword();//Метод для ввода пароля

	int getNumber();     //Метод для получения номера пользователя
	string getNik();     //Метод для получения ника пользователя
	string getPassword();//Метод для получения пароля

	void personInfo();   //Метод для вывода всей информации про пользователя
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------