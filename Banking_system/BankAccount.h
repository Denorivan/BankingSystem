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

	void idGeneration();     //����� ��� ��������� ���� �����
	void numberGeneration(); //����� ��� ��������� ������ �����
	void bankAccountInfo();  //����� ��� ������ ���������� ��� ����
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------