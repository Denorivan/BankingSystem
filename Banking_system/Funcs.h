#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>

#include "Person.h"
#include "BankAccount.h"
//---------------------------------------------------------------------------------------------------------------
void line(int a);
void thereIsNoSuchTipeOfAnswer();
//---------------------------------------------------------------------------------------------------------------
void fileForRead();
void startMenu();
void fileForWrite();
//---------------------------------------------------------------------------------------------------------------
void admin_passwordCheck();
void admin_menu();
void admin_listOfUsers();
void admin_infoAboutUser(int aboutWho);
void admin_infoAboutBankAccount();
void admin_delUser();
//---------------------------------------------------------------------------------------------------------------
void user_accSelection();
void user_existingAcc();
void user_newAcc();
void user_menu();
void user_privateOffice();
void user_infoAboutUser();
void user_chengeInfoAboutUser();
void user_infoAboutBankAccount();
void user_delPrivateOffice();
void user_addBankAccount();
void user_delBankAccount();
void user_sendMoney();
//---------------------------------------------------------------------------------------------------------------