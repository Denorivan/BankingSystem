#pragma once

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

	void idGeneration();     //Метод для генерации айди счёта
	void numberGeneration(); //Метод для генерации номера счёта
	void bankAccountInfo();  //Метод для вывода информации про счёт
};
//----------------------------------------------------------------------------------------------