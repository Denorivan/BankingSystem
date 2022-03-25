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
		Person copy;

		while (fin.read((char*)&copy, sizeof(Person))) {
			people.push_back(copy);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//������ ����� � ������� �������� ������������ - �����

	//������ ����� � ������� �������� ����� - ������
	fin.open(pathToAccounts);

	if (fin.is_open()) {
		BankAccount copy;

		while (fin.read((char*)&copy, sizeof(BankAccount))) {
			accounts.push_back(copy);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//������ ����� � ������� �������� ����� - �����
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
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
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
			fout.write((char*)&temp, sizeof(Person));
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
			fout.write((char*)&temp, sizeof(BankAccount));
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fout.close();
	//������ � ���� � ������� �������� ����� - �����
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	system("mode con cols=30 lines=10"); //������������� ������ ����

	string password;

	line(30);
	cout << "������� ������: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
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
			line(35);
			cout << "������ ������������� ����!" << endl;
			line(35);
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
			system("mode con cols=40 lines=4"); //������������� ������ ����

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
		system("mode con cols=35 lines=10"); //������������� ������ ����

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
		auto res = find_if(people.begin(), people.end(), [&aboutWho](Person& person)
		{
			//���� ������������ ������
			if (aboutWho == person.number) {
				line(35);
				person.personInfo(); //����� ��������� ���������� ��� ������������
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
			int a; //����� ��� ��������� ������� ��� ��������� ���� �� ������
		else if (answer == 0)
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
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������
		if (answer == 1) { //���� ������������ ���������� ��������				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(35);
			cout << "������� ��� ������� �����!" << endl;
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
		system("mode con cols=40 lines=7"); //������������� ������ ����

		string nik, password;

		if (people.empty()) { //���� ������ ����
			system("mode con cols=35 lines=4"); //������������� ������ ����]

			line(35);
			cout << "������ ������������� ����!" << endl;
			line(35);
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
				if (password == p.getPassword())
					user_menu();
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
	}
}
//----------------------------------------------------------------------------------------------------------------