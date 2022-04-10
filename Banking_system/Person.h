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
public:
	string name, surname, patronymic, nik, password;
	int age, number, count;

	vector<BankAccount> personAccs; //������ ��� �������� ������ ������������

	Person();              //����������� �� ���������

	void enterName();      //����� ��� ����� �����
	void enterSurname();   //����� ��� ����� �������
	void enterPatronymic();//����� ��� ����� ��������
	void enterAge();       //����� ��� ����� ��������
	void enterNik();       //����� ��� ����� ��������
	void enterPassword();  //����� ��� ����� ������

	int getNumber();       //����� ��� ��������� ������ ������������
	string getNik();       //����� ��� ��������� ���� ������������
	string getPassword();  //����� ��� ��������� ������

	void personInfo();     //����� ��� ������ ���� ���������� ��� ������������
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------