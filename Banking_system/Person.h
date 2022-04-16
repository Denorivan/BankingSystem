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

	string name, surname, patronymic, nik, password, fullName;
	int age, count;

public:
	int number;

	vector<BankAccount> personAccs; //Вектор для хранения счетов пользователя

	Person();              //Конструктор по умолчанию

	void enterName();      //Метод для ввода имени
	void enterSurname();   //Метод для ввода фамилии
	void enterPatronymic();//Метод для ввода отчества
	void enterAge();       //Метод для ввода возраста
	void enterNik();       //Метод для ввода никнейма
	void enterPassword();  //Метод для ввода пароля

	int getNumber();       //Геттер для номера пользователя
	int getCount();        //Геттер для счётчика счетов пользователя
	string getNik();       //Геттер для никнейма пользователя
	string getFullName();  //Геттер для полного имени пользователя
	string getPassword();  //Геттер для пароля пользователя

	void countIncrement(); //Метод для увелечния счётчика аккаунтов пользователя
	void countDicrement(); //Метод для уменьшения счётчика аккаунтов пользователя
	void clearBankAccs();  //Метод для очистки счетов пользователя

	void personInfo();     //Метод для вывода всей информации про пользователя
	//------ Дружеский метод для перегрузки опертаора вывода ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------