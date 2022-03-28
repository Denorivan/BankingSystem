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
	vector<BankAccount> personAccs; //������ ��� �������� ������ ������������
	vector<string> vecForNums;      //������ ��� �������� ������� ������ ������������

	Person();            //����������� �� ���������

	void enterName();    //����� ��� ����� �����
	void enterSurname(); //����� ��� ����� �������
	void enterAge();     //����� ��� ����� ��������
	void enterNik();     //����� ��� ����� ��������
	void enterPassword();//����� ��� ����� ������

	int getNumber();     //����� ��� ��������� ������ ������������
	string getNik();     //����� ��� ��������� ���� ������������
	string getPassword();//����� ��� ��������� ������

	void personInfo();   //����� ��� ������ ���� ���������� ��� ������������
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, Person& person);
};
//----------------------------------------------------------------------------------------------