#pragma once
//----------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <Windows.h>
//----------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------
class Payment
{
public:
	string firstAcc, secondAcc; //���������� ���� ������������ ��������� �� ���� ����
	string recipient, sender;   //���������� ���� ������������� ��������� �� ����� ����
	string paymentName;         //���������� ��� �������� ��������
	double money;               //���������� ��� �������� ����� ��������
	int number;                 //���������� ��� ������ ����������

	Payment();                  //����������� �� ���������

	void enterPaymentName();    //����� ��� ����� ����� �������
	void printInfo1();          //����� ��� ������ ���������� � �������� �� ���� ����
	void printInfo2();          //����� ��� ������ ���������� � �������� �� ������ ���� 
	//------ ��������� ����� ��� ���������� ��������� ������ ------
	friend ostream& operator<< (ostream& out, Payment& pay);
};
//----------------------------------------------------------------------------------------------