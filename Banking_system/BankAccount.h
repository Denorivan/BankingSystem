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
private:

	string AccNumber, owner, id, purpose, password;
	double money;

public:
	int number;

	vector<Payment> transactions1; //������ ��� �������� ���������� ����� ������ �������
	vector<Payment> transactions2; //������ ��� �������� ���������� ����� ������� ������ �������������

	BankAccount();           //����������� �� ���������

	void setOwner(string n); //������ ��� ��������� �����
	void enterPurpose();     //����� ��� ����� ���������� �����
	void enterPassword();    //����� ��� ����� ������ �����
	void enterMoney();       //����� ��� �������� ����� �� ����� 

	int getNumber();         //������ ��� ������ �����
	double getMoney();       //������ ��� ����� �� �����
	string getAccNumber();   //������ ��� ����������� ������ �����
	string getOwner();       //������ ��� ��������� �����
	string getPurpose();     //������ ��� ���������� �����
	string getPassword();    //������ ��� ������ �����

	void sumMoney(double n); //����� ��� ���������� ����� �� �����
	void subMoney(double n); //����� ��� ���������� ����� �� �����

	void idGeneration();     //����� ��� ��������� ���� �����
	void numberGeneration(); //����� ��� ��������� ������ �����
	void bankAccountInfo();  //����� ��� ������ ���������� ��� ����
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, BankAccount& acc);
};
//----------------------------------------------------------------------------------------------