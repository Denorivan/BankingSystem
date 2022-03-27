#include "Funcs.h"
//----------------------------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------------------------
vector<Person> people;
Person person;
vector<BankAccount> accounts;
BankAccount bankAcc;
//----------------------------------------------------------------------------------------------------------------
void line(int a) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 3); //��������� ����� � �������: 3 (�����)
	for (int i = 0; i < a; i++)
		cout << "~";
	cout << endl;
	SetConsoleTextAttribute(color, 7); //��������� ����� � �������: 7 (�����)
}

void thereIsNoSuchTipeOfAnswer() {
	system("mode con cols=30 lines=5"); //������������� ������ ����

	line(30);
	cout << "������ ������ ���!" << endl;
	cout << "��������� � ���������� ��� ���" << endl;
	line(30);
	Sleep(3000);
	system("cls");
}
//----------------------------------------------------------------------------------------------------------------
void fileForRead() {
	ifstream fin;
	string pathToPeople = "People.txt";
	string pathToAccounts = "Accounts.txt";

	//������ ����� � ������� �������� ������������ - ������
	fin.open(pathToPeople);

	if (fin.is_open()) {
		while (fin.read((char*)&person, sizeof(Person))) {
			people.push_back(person);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//������ ����� � ������� �������� ������������ - �����

	//������ ����� � ������� �������� ����� - ������
	fin.open(pathToAccounts);

	if (fin.is_open()) {
		while (fin.read((char*)&bankAcc, sizeof(BankAccount))) {
			accounts.push_back(bankAcc);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//������ ����� � ������� �������� ����� - �����
	
	//��� ���������� ������ ������, ��������� �� �����, � ������� ������� ������������
	for (auto& accs : accounts) { //���� ��� �������� ������ ������
		for (auto& pers : people) { //���� ��� �������� ������ �������������
			for (auto& nums : pers.vecForNums) { //���� ��� �������� ������ ������� ������ ������������
				//���� ����� ����� ������ � ������� ����� ������������ - ���������� ����� ����� � ���
				if (accs.AccNumber == nums) 
					pers.personAccs.push_back(accs);
			}
		}
	}
}

void startMenu() {
	for (;;) {
		system("mode con cols=30 lines=7"); //������������� ������ ����

		int choice;

		line(30);
		cout << "1 - ����� ��� �������������" << endl;
		cout << "2 - ����� ��� ������������" << endl;
		cout << "0 - �����" << endl;
		line(30);
		cout << "��� �����: ";
		cin >> choice;

		system("cls"); //������� ��������� 

		if (choice == 1 || choice == 2) {
			fileForRead();

			if (choice == 1)
				admin_passwordCheck();
			else if (choice == 2)
				user_accSelection();
		}
		else if (choice == 0) {
			fileForWrite();

			line(30);
			cout << "������, �� ��������!" << endl;
			break;
		}
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void fileForWrite() {
	ofstream fout;
	string pathToPeople = "People.txt";
	string pathToAccounts = "Accounts.txt";

	//�������� ����� � ������� �������� ������������, ��� ������� ������
	fout.open(pathToPeople, ofstream::trunc);
	fout.close();
	//�������� ����� � ������� �������� �����, ��� ������� ������
	fout.open(pathToAccounts, ofstream::trunc);
	fout.close();

	//������ � ���� � ������� �������� ������������ - ������
	fout.open(pathToPeople, ofstream::app);

	if (fout.is_open()) {
		for (auto& temp : people) {
			person = temp;
			fout.write((char*)&person, sizeof(Person));
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fout.close();
	//������ � ���� � ������� �������� ������������ - �����

	//������ � ���� � ������� �������� ����� - ������
	fout.open(pathToAccounts, ofstream::app);

	if (fout.is_open()) {
		for (auto& temp : accounts) {
			bankAcc = temp;
			fout.write((char*)&bankAcc, sizeof(BankAccount));
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fout.close();
	//������ � ���� � ������� �������� ����� - �����
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	system("mode con cols=30 lines=3"); //������������� ������ ����

	string password;

	line(30);
	cout << "������� ������: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
		system("mode con cols=30 lines=5"); //������������� ������ ����
		line(30);
		cout << "������ �� ����������!" << endl;
		cout << "������ ��������!" << endl;
		line(30);
		Sleep(3000);
		system("cls");
	}
}

void admin_menu() {
	for (;;) {
		system("mode con cols=25 lines=7"); //������������� ������ ����

		int answer;

		line(25);
		cout << "1 - ������ �������������" << endl;
		cout << "2 - ������� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(25);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1)
			admin_listOfUsers();
		else if (answer == 2)
			admin_delUser();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_listOfUsers() {
	for (;;) {
		system("mode con cols=35 lines=15"); //������������� ������ ����

		int answer;

		if (people.empty()) { //���� ������ ����
			system("mode con cols=30 lines=4"); //������������� ������ ����
			line(30);
			cout << "������ ������������� ����!" << endl;
			line(30);
			Sleep(2500);   //�������� � 2 �������
			system("cls"); //������� ���������

			break;
		}

		line(35);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ���� �������������
		for (auto& temp : people) {
			temp.number = a + 1;  //������������ ������������� ������
			cout << temp << endl; //����� ������, ����� � ������� ������������

			a++; //���������� �������� ���������
		}
		line(35);
		cout << "1 - ���������� ��������� ����������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(35);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1) {
			system("mode con cols=40 lines=10"); //������������� ������ ����

			int who;

			line(40);
			a = 0; //������� ��� ���������
			//������� ������� � ����� ������ ���� �������������
			for (auto& temp : people) {
				temp.number = a + 1;  //������������ ������������� ������
				cout << temp << endl; //����� ������, ����� � ������� ������������

				a++; //���������� �������� ���������
			}
			line(40);
			cout << "��� ���� �� ������ ������� ����������?" << endl;
			cout << "������� �����: ";
			cin >> who;
			system("cls"); //������� ���������
			admin_infoAboutUser(who); //����� ������� ������� ��� ��������� ����������
		}
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_infoAboutUser(int aboutWho) {
	for (;;) {
		system("mode con cols=35 lines=11"); //������������� ������ ����

		int answer;
		//�������� �� ������������ ����� ������� ������������
		if (aboutWho < 1 || aboutWho > people.size()) {
			system("mode con cols=40 lines=10"); //������������� ������ ����
			line(40);
			cout << "�� ����� ������������ �����!" << endl;
			cout << "��������� � ���������� ��� ���!" << endl;
			line(40);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		//������� ����������� ���������� STL ��� ������
		auto res = find_if(people.begin(), people.end(), [&aboutWho](Person& p)
		{
			//���� ������������ ������
			if (aboutWho == p.number) {
				line(35);
				p.personInfo(); //����� ��������� ���������� ��� ������������
			}

			return 0;
		});

		line(35);
		cout << "1 - ���������� ���������� �� ������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(35);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1)
			admin_infoAboutBankAccount(aboutWho);
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_infoAboutBankAccount(int aboutWhich) {
	for (;;) {
		system("mode con cols=40 lines=11"); //������������� ������ ����

		int answer;

		if (person.personAccs.empty()) {
			system("mode con cols=40 lines=4"); //������������� ������ ����
			line(40);
			cout << "� ����� ������������ ��� ��� ������!" << endl;
			line(40);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(40);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(40);
		cout << "�������� ����, ��� �������\n������ ���������� ����������: ";
		cin >> aboutWhich;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(40);
		//������� ������� � ����� ������� �����
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich)
				temp.bankAccountInfo();
		}
		line(40);
		cout << "0 - ��������� �����" << endl;
		line(40);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");//������� ��������

		if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_delUser() {
	for (;;) {
		system("mode con cols=35 lines=10"); //������������� ������ ����

		int answer, whoDelete, index;

		line(35);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ���� �������������
		for (auto& temp : people) {
			temp.number = a + 1;  //������������ ������������� ������
			cout << temp << endl; //����� ������, ����� � ������� ������������

			a++; //���������� �������� ���������
		}
		line(35);
		cout << "������� ����� ���� ����� �������: ";
		cin >> whoDelete;
		system("cls"); //������� ���������
		//�������� �� ������������ ����� ������� ������������
		if (whoDelete < 1 || whoDelete > people.size()) {
			system("mode con cols=40 lines=10"); //������������� ������ ����
			line(40);
			cout << "�� ����� ������������ �����!" << endl;
			cout << "��������� � ���������� ��� ���!" << endl;
			line(40);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		line(35);
		cout << "�� ������������� ������ �������\n����� ������������?\n(1 - ��, 0 - ���)" << endl;
		line(35);
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������
		if (answer == 1) { //���� ������������ ���������� ��������				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(35);
			cout << "������� ��� ������� �����!" << endl;
			line(35);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		else if (answer == 0) { //���� ������������ ������� ��������
			line(35);
			cout << "�������� ��������!" << endl;
			line(35);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		else { //���� ������������ ��� ������������ �����
			line(35);
			cout << "������ ������ ����!\n�������� ��������!" << endl;
			line(35);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------
bool addCheck = true; //���������� ��� �������� ��������� �� ������������ � ����� ������

void user_accSelection() {
	for (;;) {
		system("mode con cols=30 lines=7"); //������������� ������ ����

		int answer;

		line(30);
		cout << "1 - ������������ ������������" << endl;
		cout << "2 - ����� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(30);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1)
			user_existingAcc();
		else if (answer == 2)
			user_newAcc();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_existingAcc() {
	int check = 0; //������� ��� ���������� ������� ����� ������

	for (;;) {
		system("mode con cols=30 lines=7"); //������������� ������ ����

		string nik, password;

		if (people.empty()) { //���� ������ ����
			system("mode con cols=30 lines=4"); //������������� ������ ����]

			line(30);
			cout << "������ ������������� ����!" << endl;
			line(30);
			Sleep(2500);   //�������� � 2.5 �������
			system("cls"); //������� ���������

			break;
		}

		if (check == 3) {
			system("mode con cols=30 lines=4"); //������������� ������ ����
			line(30);
			cout << "�� ��� ������������ �������\n����� ������� �� ����!" << endl;
			line(30);     
			Sleep(3000);  //�������� � 3 �������
			system("cls");//������� ���������
			break;
		}
		
		line(30);
		cout << "������� ������� ������������:" << endl;;
		cin >> nik;
		cout << "������� ������ ������������:" << endl;
		cin >> password;

		system("cls");

		find_if(people.begin(), people.end(), [&nik, &password, &check](Person& p)
		{
			if (nik == p.getNik()) {
				if (password == p.getPassword()) {
					person = p;
					auto iter = people.begin() + (p.getNumber() - 1);
					people.erase(iter);

					user_menu();
				}
				else {
					system("mode con cols=20 lines=4"); //������������� ������ ����
					line(20);
					cout << "������ �� ������!" << endl;
					line(20);
					check++;      //���������� ��������
					Sleep(3000);  //�������� � 3 �������
					system("cls");//������� ���������
				}
			}
			else {
				system("mode con cols=30 lines=4"); //������������� ������ ����
				line(30);
				cout << "������������ � �����\n��������� �� ����������!" << endl;
				line(30);
				check++;      //���������� ��������
				Sleep(3000);  //�������� � 3 �������
				system("cls");//������� ���������
			}

			return 0;
		});
	}
}

void user_newAcc() {
	system("mode con cols=40 lines=7"); //������������� ������ ����

	line(40);
	person.enterName();
	person.enterSurname();
	person.enterAge();
	system("cls"); //������� ���������
	line(40);
	person.enterNik();
	//�������� �� ���������� ��������
	for (auto& temp : people) {
		if (temp.getNik() == person.getNik()) {
			line(40);
			cout << "������������ � ����� ���������\n��� ����������!" << endl;
			line(40);
			Sleep(3000);  //�������� � 3 �������
			system("cls");//������� ���������
			line(40);
			person.enterNik();
		}
	}
	person.enterPassword();

	system("cls"); //������� ���������

	user_menu();
}

void user_menu() {
	for (;;) {
		system("mode con cols=20 lines=9"); //������������� ������ ����

		int answer;

		if (!addCheck) 
			break;

		line(20);
		cout << "1 - ������ �������" << endl;
		cout << "2 - �������� ����" << endl;
		cout << "3 - ������� ����" << endl;
		cout << "4 - ��������� ������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(20);
		cout << "��� �����: ";
		cin >> answer;

		system("cls"); //������� ���������

		if (answer == 1)
			user_privateOffice();
		else if (answer == 2)
			user_addBankAccount();
		else if (answer == 3)
			user_delBankAccount();
		else if (answer == 4)
			user_sendMoney();
		else if (answer == 0) {
			if (addCheck)
				people.push_back(person);

			addCheck = true;

			break;
		}
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_privateOffice() {
	for (;;) {
		system("mode con cols=40 lines=8"); //������������� ������ ����

		int answer;

		if (!addCheck)
			break;

		line(40);
		cout << "1 - ���������� ������������ ����������" << endl;
		cout << "2 - ���������� ���������� �� ������" << endl;
		cout << "3 - ������� ���� ������ �������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(40);
		cout << "��� �����: ";
		cin >> answer;

		system("cls"); //������� ���������

		if (answer == 1)
			user_infoAboutUser();
		else if (answer == 2)
			user_infoAboutBankAccount();
		else if (answer == 3)
			user_delPrivateOffice();
		else if (answer == 0) 
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_infoAboutUser() {
	for (;;) {
		system("mode con cols=40 lines=12"); //������������� ������ ����

		int answer;

		line(40);
		person.personInfo();
		line(40);
		cout << "1 - �������� ������������ ����������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(40);
		cout << "��� �����: ";
		cin >> answer;

		system("cls"); //������� ���������

		if (answer == 1)
			user_chengeInfoAboutUser();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_chengeInfoAboutUser() {
	system("mode con cols=25 lines=10"); //������������� ������ ����

	int answer;

	line(25);
	cout << "��� �� ������ ��������?" << endl;
	line(25);
	cout << "1 - ���" << endl;
	cout << "2 - �������" << endl;
	cout << "3 - �������" << endl;
	cout << "4 - �������" << endl;
	cout << "5 - ������" << endl;
	line(25);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ��������� 
	line(25);
	
	switch (answer) {
	case 1: person.enterName(); 
		break;
	case 2: person.enterSurname();
		break;
	case 3: person.enterAge();
		break;
	case 4: person.enterNik();
		break;
	case 5: person.enterPassword();
		break;
	default: thereIsNoSuchTipeOfAnswer();
	}
	system("cls"); //������� ��������� 
}

void user_infoAboutBankAccount() {
	for (;;) {
		system("mode con cols=40 lines=14"); //������������� ������ ����

		int answer, aboutWhich;

		if (person.personAccs.empty()) {
			system("mode con cols=25 lines=4"); //������������� ������ ����
			line(25);
			cout << "� ��� ��� ��� ������!" << endl;
			line(25);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}
		line(40);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(40);
		cout << "�������� ����, ��� �������\n������ ���������� ����������: ";
		cin >> aboutWhich;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(40);
		//������� ������� � ����� ������� �����
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich)
				temp.bankAccountInfo();
		}
		line(40);
		cout << "1 - �������� ����������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(40);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");//������� ��������

		if (answer == 1)
			user_chengeInfoAboutBankAccount(aboutWhich);
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_chengeInfoAboutBankAccount(int aboutWhich) {
	system("mode con cols=25 lines=11"); //������������� ������ ����

	int answer;

	//������� ������� � ����� ������� ����� � �������� ������������
	for (auto& temp : person.personAccs) {
		if (temp.number == aboutWhich) {
			bankAcc = temp;
			auto iter = person.personAccs.begin() + (temp.number - 1);
			person.personAccs.erase(iter);
		}
	}

	//������� ������� � ����� ������� ����� � ����� ������ ������
	int a = 0; //������� ��� ���������
	for (auto& temp : accounts) {
		temp.number = a + 1; //������������ ������ ������ ������ ������
		if (temp.number == aboutWhich) {
			bankAcc = temp;
			auto iter = accounts.begin() + (temp.number - 1);
			accounts.erase(iter);
		}
		a++; //���������� ��������
	}

	line(25);
	cout << "��� �� ������ ��������?" << endl;
	line(25);
	cout << "1 - ����� �����" << endl;
	cout << "2 - id �����" << endl;
	cout << "3 - ��������� �����" << endl;
	cout << "4 - ���������� �����" << endl;
	cout << "5 - ������ �����" << endl;
	line(25);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ���������
	line(25);

	switch (answer) {
	case 1: bankAcc.numberGeneration();
		break;
	case 2: bankAcc.idGeneration();
		break;
	case 3: bankAcc.enterOwner();
		break;
	case 4: bankAcc.enterPurpose();
		break;
	case 5: bankAcc.enterPassword();
		break;
	default: thereIsNoSuchTipeOfAnswer();
	}

	Sleep(2000);   //�������� 2 �������
	system("cls"); //������� ���������

	person.personAccs.push_back(bankAcc); //��������������� ����� � ������� ������������
	accounts.push_back(bankAcc);          //��������������� ����� � ����� ������ ������
}

void user_delPrivateOffice() {
	system("mode con cols=45 lines=6"); //������������� ������ ����

	int answer;

	line(45);
	cout << "�� ������������� ������ ������� ���� �������?\n(1 - ��, 0 - ���)" << endl;
	line(45);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ���������

	if (answer == 1) { //���� ������������ ���������� ��������
		system("mode con cols=32 lines=4"); //������������� ������ ����

		line(32);
		cout << "������������ ��� ������� �����!" << endl;
		line(32);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
		addCheck = false;
	}
	else if (answer == 0) { //���� ������������ ������� ��������
		system("mode con cols=20 lines=4"); //������������� ������ ����

		line(20);
		cout << "�������� ��������!" << endl;
		line(20);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
	else { //���� ������������ ��� ������������ �����
		system("mode con cols=20 lines=4"); //������������� ������ ����

		line(20);
		cout << "������ ������ ����!\n�������� ��������!" << endl;
		line(20);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
}

void user_addBankAccount() {
	system("mode con cols=40 lines=9"); //������������� ������ ����

	if (person.count == 3) {
		system("mode con cols=60 lines=4"); //������������� ������ ����
		line(60);
		cout << "� ��� ��� ���� 3 �����, ��� ������������ ���������� ������!" << endl;
		line(60);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
	else {
		person.count += 1;
		line(40);
		bankAcc.enterOwner();
		bankAcc.enterPurpose();
		bankAcc.enterPassword();
		bankAcc.idGeneration();
		bankAcc.numberGeneration();
		line(40);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������

		person.vecForNums.push_back(bankAcc.AccNumber); //���������� ������ � ������ ��� �������
		person.personAccs.push_back(bankAcc);           //���������� ����� � ������ ������ ������������
		accounts.push_back(bankAcc);                    //���������� ����� � ���� ������ ������
	}
}

void user_delBankAccount() {
	for (;;) {
		system("mode con cols=40 lines=9"); //������������� ������ ����

		int whoDelete, answer;

		if (person.personAccs.empty()) {
			system("mode con cols=15 lines=4"); //������������� ������ ����
			line(15);
			cout << "� ��� ��� ��� ������!" << endl;
			line(15);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}
		line(40);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(40);
		cout << "�������� ����, ������� ������ �������: ";
		cin >> whoDelete;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (whoDelete < 1 || whoDelete > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		system("mode con cols=42 lines=5"); //������������� ������ ����
		line(42);
		cout << "�� ������������� ������ ������� ���� ����?\n(1 - ��, 0 - ���)" << endl;
		line(42);
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������
		if (answer == 1) { //���� ������������ ���������� ��������	
			system("mode con cols=30 lines=4"); //������������� ������ ����
			person.count -= 1;
			
			int index = whoDelete - 1;
			auto iter1 = person.vecForNums.begin() + index;
			auto iter2 = person.personAccs.begin() + index;

			person.vecForNums.erase(iter1); //�������� ������������ ������ ����� �� ������ �������
			person.personAccs.erase(iter2); //�������� ����� �� ������ ������ ������������

			line(30);
			cout << "���� ���� ��� ������� �����!" << endl;
			line(30);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
		else if (answer == 0) { //���� ������������ ������� ��������
			system("mode con cols=20 lines=4"); //������������� ������ ����

			line(20);
			cout << "�������� ��������!" << endl;
			line(20);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
		else { //���� ������������ ��� ������������ �����
			system("mode con cols=20 lines=4"); //������������� ������ ����

			line(20);
			cout << "������ ������ ����!\n�������� ��������!" << endl;
			line(20);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
	}
}

void user_sendMoney() {
	for (;;) {
		system("mode con cols=50 lines=7"); //������������� ������ ����

		int answer;

		if (person.personAccs.empty()) {
			system("mode con cols=15 lines=4"); //������������� ������ ����
			line(15);
			cout << "� ��� ��� ��� ������!" << endl;
			line(15);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(50);
		cout << "1 - ��������� ������ �� ���� ����" << endl;
		cout << "2 - ��������� ������ �� ���� ������� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(50);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");//������� ���������

		if (answer == 1)
			user_sendMoneyToOwnAcc();
		else if (answer == 2)
			user_sendMoneyToOtherAcc();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_sendMoneyToOwnAcc() {
	for (;;) {
		system("mode con cols=55 lines=10"); //������������� ������ ����

		int firstAcc, secondAcc;
		double sum;

		if (person.personAccs.size() == 1) {
			system("mode con cols=30 lines=4"); //������������� ������ ����
			line(30);
			cout << "� ��� ��� ��� ������� �����!" << endl;
			line(30);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(55);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(55);
		cout << "�������� ���� � �������� ������ ��������� ������: ";
		cin >> firstAcc;
		system("cls");//������� ��������

		line(55);
		a = 0; //������� �������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(55);
		cout << "�������� ���� �� ������� ������ ��������� ������: ";
		cin >> secondAcc;
		system("cls");//������� ��������

		if (firstAcc == secondAcc) {
			system("mode con cols=35 lines=5"); //������������� ������ ����
			line(35);
			cout << "������! �������� ��������!" << endl;
			cout << "�� ������� ��� ���������� �����!" << endl;
			line(35);
			Sleep(3000);  //�������� 3 �������
			system("cls");//������� ���������
			break;
		}
		system("mode con cols=30 lines=4"); //������������� ������ ����
		line(30);
		cout << "������� ����� ��������: ";
		cin >> sum;
		system("cls");//������� ��������
		//���� ��� �������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//����� ����� � �������� ����������
			if (temp.number == firstAcc)
				temp.money -= sum;
			//����� ����� �� ������� ����������
			if (temp.number == secondAcc)
				temp.money += sum;
		}

		line(30);
		cout << "����� ������� ����������!";
		line(30);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ��������
		break;
	}
}

void user_sendMoneyToOtherAcc() {
	for (;;) {
		system("mode con cols=55 lines=10"); //������������� ������ ����

		int firstAcc;
		string secondAcc;
		double sum;

		line(55);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(55);
		cout << "�������� ���� � �������� ������ ��������� ������: ";
		cin >> firstAcc;
		system("cls");//������� ��������

		line(55);
		cout << "������� ����� ����� �� ������� ������ ��������� ������:" << endl;
		cin.ignore(32767, '\n'); //���������� ������� �������� ������ "\n" �� �������� ������
		getline(cin, secondAcc);
		system("cls");//������� ��������

		//�������� �� ������� ������ ������ ����� � ������ �������������
		bool check = true;
		for (auto& temp : accounts) {
			if (temp.AccNumber == secondAcc)
				check = false;
		}
		if (check) {
			system("mode con cols=30 lines=5"); //������������� ������ ����
			line(30);
			cout << "������! �������� ��������!" << endl;
			cout << "����� � ����� ������� ���!" << endl;
			line(30);
			Sleep(3000);  //�������� 3 �������
			system("cls");//������� ���������
			break;
		}

		system("mode con cols=30 lines=4"); //������������� ������ ����

		line(30);
		cout << "������� ����� ��������: ";
		cin >> sum;
		system("cls");//������� ��������
		//���� ��� �������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//����� ����� � �������� ����������
			if (temp.number == firstAcc)
				temp.money -= sum;
		}
		//���� ��� �������� ������� ������
		for (auto& temp : accounts) {
			//����� ����� �� ������� ����������
			if (temp.AccNumber == secondAcc)
				temp.money += sum;
		}

		line(30);
		cout << "����� ������� ����������!";
		line(30);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ��������
		break;
	}
}
//----------------------------------------------------------------------------------------------------------------