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
	string id, number, owner, purpose;
	double money;
public:
	void enterOwner();
	void enterPurpose();

	void idGeneration();     //����� ��� ��������� ���� �����
	void numberGeneration(); //����� ��� ��������� ������ �����
	void bankAccountInfo();  //����� ��� ������ ���������� ��� ����
};
//----------------------------------------------------------------------------------------------