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

	vector<BankAccount> personAccs; //������ ��� �������� ������ ������������

	Person();              //����������� �� ���������

	void enterName();      //����� ��� ����� �����
	void enterSurname();   //����� ��� ����� �������
	void enterPatronymic();//����� ��� ����� ��������
	void enterAge();       //����� ��� ����� ��������
	void enterNik();       //����� ��� ����� ��������
	void enterPassword();  //����� ��� ����� ������

	int getNumber();       //������ ��� ������ ������������
	int getCount();        //������ ��� �������� ������ ������������
	string getNik();       //������ ��� �������� ������������
	string getFullName();  //������ ��� ������� ����� ������������
	string getPassword();  //������ ��� ������ ������������

	void countIncrement(); //����� ��� ��������� �������� ��������� ������������
	void countDicrement(); //����� ��� ���������� �������� ��������� ������������
	void clearBankAccs();  //����� ��� ������� ������ ������������

	void personInfo();     //����� ��� ������ ���� ���������� ��� ������������
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------