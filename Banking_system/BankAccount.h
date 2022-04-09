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

	void enterPurpose();     //����� ��� ����� ���������� �����
	void enterPassword();    //����� ��� ����� ������ �����
	void enterMoney();       //����� ��� �������� ����� �� ����� 

	string getPassword();    //����� ��� ��������� ������

	void idGeneration();     //����� ��� ��������� ���� �����
	void numberGeneration(); //����� ��� ��������� ������ �����
	void bankAccountInfo();  //����� ��� ������ ���������� ��� ����
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------