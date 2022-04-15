#pragma once

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include <vector>

#include "Payment.h"
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class BankAccount {
public:
	string AccNumber, owner, id, purpose, password;
	double money;
	int number;

	vector<Payment> transactions1; //������ ��� �������� ���������� ����� ������ �������
	vector<Payment> transactions2; //������ ��� �������� ���������� ����� ������� ������ �������������

	BankAccount();           //����������� �� ���������

	void setOwner(string n); //������ ��� ��������� �����
	void enterPurpose();     //����� ��� ����� ���������� �����
	void enterPassword();    //����� ��� ����� ������ �����
	void enterMoney();       //����� ��� �������� ����� �� ����� 

	string getPassword();    //������ ��� ������ �����

	void idGeneration();     //����� ��� ��������� ���� �����
	void numberGeneration(); //����� ��� ��������� ������ �����
	void bankAccountInfo();  //����� ��� ������ ���������� ��� ����
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------