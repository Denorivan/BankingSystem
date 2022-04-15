#include "Funcs.h"
//----------------------------------------------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------------------------------------------
vector<Person> people;
Person person;
vector<BankAccount> accounts;
BankAccount bankAcc;
Payment payment;
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
	line(70);
	cout << "\t\t\t������ ������ ���!" << endl;
	cout << "\t\t ��������� � ���������� ��� ���" << endl;
	line(70);
	Sleep(3000);  //�������� 3 �������
	system("cls");//������� ���������
}
//----------------------------------------------------------------------------------------------------------------
void fileForRead() {
	ifstream fin;
	string pathToPeople = "People.txt";

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
}

void startMenu() {
	for (;;) {
		int choice;

		line(70);
		cout << "1 - ����� ��� �������������" << endl;
		cout << "2 - ����� ��� ������������" << endl;
		cout << "0 - �����" << endl;
		line(70);
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

			line(70);
			cout << "\t\t\t������, �� ��������!" << endl;
			break;
		}
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void fileForWrite() {
	ofstream fout;
	string pathToPeople = "People.txt";

	//������� ������, ������� �������� ������ ������������
	for (auto& p : people) {
		p.clearBankAccs();
	}

	//�������� ����� � ������� �������� ������������, ��� ������� ������
	fout.open(pathToPeople, ofstream::trunc);
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
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	string password;

	line(70);
	cout << "������� ������: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
		line(70);
		cout << "\t\t\t ������ �� ����������!" << endl;
		cout << "\t\t\t   ������ ��������!" << endl;
		line(70);
		Sleep(3000);
		system("cls");
	}
}

void admin_menu() {
	for (;;) {
		int answer;

		int a = 0; //������� ��� ���������
		//������� ������� � ������������ ������� �������������
		for (auto& temp : people) {
			temp.number = a + 1;

			a++;
		}

		line(70);
		cout << "1 - ������ �������������" << endl;
		cout << "2 - ������� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
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
		int answer;

		if (people.empty()) { //���� ������ ����
			line(70);
			cout << "\t\t\t������ ������������� ����!" << endl;
			line(70);
			Sleep(2500);   //�������� � 2 �������
			system("cls"); //������� ���������

			break;
		}

		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ���� �������������
		for (auto& temp : people) {
			temp.number = a + 1;  //������������ ������������� ������
			cout << temp << endl; //����� ������, ����� � ������� ������������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "1 - ���������� ��������� ����������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1) {
			int who;

			line(70);
			a = 0; //������� ��� ���������
			//������� ������� � ����� ������ ���� �������������
			for (auto& temp : people) {
				temp.number = a + 1;  //������������ ������������� ������
				cout << temp << endl; //����� ������, ����� � ������� ������������

				a++; //���������� �������� ���������
			}
			line(70);
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
		int answer;
		//�������� �� ������������ ����� ������� ������������
		if (aboutWho < 1 || aboutWho > people.size()) {
			line(70);
			cout << "\t\t\t  �� ����� ������������ �����!" << endl;
			cout << "\t\t\t ��������� � ���������� ��� ���!" << endl;
			line(70);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		person = Person();
		//���� ��� ������ ������� ������������
		for (auto& p : people) {
			if (aboutWho == p.number) {
				line(70);
				p.personInfo();

				person = p;
			}
		}
		line(70);
		cout << "1 - ���������� ���������� �� ������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");

		if (answer == 1)
			admin_infoAboutBankAccount();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_infoAboutBankAccount() {
	for (;;) {
		int answer, aboutWhich;

		if (person.personAccs.empty()) {
			line(70);
			cout << "\t\t� ����� ������������ ��� ��� ������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ����, ��� �������\n������ ���������� ����������: ";
		cin >> aboutWhich;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		bankAcc = BankAccount();
		//������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//����� ������� ����� �� ������
			if (temp.number == aboutWhich) {
				//������� ������� ������
				for (auto& accs : accounts) {
					//����� ������� ����� � ����� ����������
					if (accs.AccNumber == temp.AccNumber) {
						accs.bankAccountInfo();
						bankAcc = accs;
					}
				}
			}
		}
		line(70);
		cout << "1 - ���������� ���������� �����" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");//������� ��������

		if (answer == 1) {
			user_infoAboutTransaction();
			break;
		}
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_delUser() {
	for (;;) {
		int answer, whoDelete, index;

		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ���� �������������
		for (auto& temp : people) {
			temp.number = a + 1;  //������������ ������������� ������
			cout << temp << endl; //����� ������, ����� � ������� ������������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "������� ����� ���� ����� �������: ";
		cin >> whoDelete;
		system("cls"); //������� ���������
		//�������� �� ������������ ����� ������� ������������
		if (whoDelete < 1 || whoDelete > people.size()) {
			line(70);
			cout << "\t\t\t �� ����� ������������ �����!" << endl;
			cout << "\t\t\t��������� � ���������� ��� ���!" << endl;
			line(70);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		line(70);
		cout << "�� ������������� ������ ������� ����� ������������?\n(1 - ��, 0 - ���)" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������
		if (answer == 1) { //���� ������������ ���������� ��������				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(70);
			cout << "\t\t\t������������ ��� ������� �����!" << endl;
			line(70);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		else if (answer == 0) { //���� ������������ ������� ��������
			line(70);
			cout << "\t\t\t  �������� ��������!" << endl;
			line(70);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
		else { //���� ������������ ��� ������������ �����
			line(70);
			cout << "\t\t\t ������ ������ ����!\n\t\t\t�������� ��������!" << endl;
			line(70);
			Sleep(2000);  //�������� � 2 �������
			system("cls");//������� ���������
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------
bool addCheck = true;  //���������� ��� �������� ��������� �� ������������ � ����� ������
bool sendCheck = false;//���������� ��� �������� �� ������ ������ �������� ����������
int selection;         //��������� ��� �������� ����� �� ������������ ��� ��� ������������
string Nik;            //��������� ��� ����� � �������� ��� ���������� ������

void user_accSelection() {
	for (;;) {
		addCheck = true;

		int a = 0; //������� ��� ���������
		//������� ������� � ������������ ������� �������������
		for (auto& temp : people) {
			temp.number = a + 1;

			a++;
		}

		line(70);
		cout << "1 - ������������ ������������" << endl;
		cout << "2 - ����� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> selection;

		system("cls");

		if (selection == 1)
			user_existingAcc();
		else if (selection == 2)
			user_newAcc();
		else if (selection == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_existingAcc() {
	int check = 0; //������� ��� ���������� ������� ����� ������

	for (;;) {
		string password;
		bool checkNik = false;

		if (people.empty()) { //���� ������ ����
			line(70);
			cout << "\t\t\t������ ������������� ����!" << endl;
			line(70);
			Sleep(2500);   //�������� � 2.5 �������
			system("cls"); //������� ���������

			break;
		}

		if (check == 3) {
			line(70);
			cout << "�� ��� ������������ �������\n����� ������� �� ����!" << endl;
			line(70);
			Sleep(3000);  //�������� � 3 �������
			system("cls");//������� ���������
			break;
		}
		
		line(70);
		cout << "������� ������� ������������:" << endl;;
		cin >> Nik;
		//������� ������� � �������� �� ������������� ������ ����
		for (auto& temp : people) {
			if (Nik == temp.getNik())
				checkNik = true;
		}
		//���� ������������ � ����� ����� ���
		if (checkNik == false) {
			line(70);
			cout << "������������ � �����\n��������� �� ����������!" << endl;
			line(70);
			check++;      //���������� ��������
			Sleep(3000);  //�������� � 3 �������
			system("cls");//������� ���������
			break;
		}

		cout << "������� ������ ������������:" << endl;
		cin >> password;

		system("cls");

		for (auto p : people) {
			if (Nik == p.getNik()) {
				if (password == p.getPassword()) {
					person = p;

					user_menu();
				}
				else {
					line(70);
					cout << "������ �� ������!" << endl;
					line(70);
					check++;      //���������� ��������
					Sleep(3000);  //�������� � 3 �������
					system("cls");//������� ���������
				}
			}
		}

		break;
	}
}

void user_newAcc() {
	person = Person();  //������� ��������� ������ 

	line(70);
	person.enterName();
	person.enterSurname();
	person.enterPatronymic();
	person.enterAge();
	system("cls"); //������� ���������
	line(70);
	person.enterNik();
	//�������� �� ���������� ��������
	for (auto& temp : people) {
		if (temp.getNik() == person.getNik()) {
			line(70);
			cout << "\t\t ������������ � ����� ��������� ��� ����������!" << endl;
			line(70);
			Sleep(3000);  //�������� � 3 �������
			system("cls");//������� ���������
			line(70);
			person.enterNik();
		}
	}
	person.enterPassword();

	system("cls"); //������� ���������

	user_menu();
}

void user_menu() {
	for (;;) {
		int answer;

		if (!addCheck) 
			break;

		int a = 0; //������� ��� ���������
		//������� ������� � ������������ ������ ������������
		for (auto& temp : people) {
			temp.number = a + 1;  //������������ ������������� ������

			a++; //���������� �������� ���������
		}

		line(70);
		cout << "1 - ������ �������" << endl;
		cout << "2 - �������� ����" << endl;
		cout << "3 - ������� ����" << endl;
		cout << "4 - ��������� ������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
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
			//���� ���� ��� ������ ������������
			if (selection == 2 && addCheck) {
				//���������� ������������ � ����� ������
				people.push_back(person);
			}
			//���� ���� ��� ������������� ������������
			if (selection == 1 && addCheck) {
				//���� ��� �������� ������� �������������
				for (auto& p : people) {
					//���� ���������� �� ���� - ���������� ������ ��� ������������
					if (Nik == p.getNik()) {
						p = person;
					}
				}
			}
			break;
		}
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_privateOffice() {
	for (;;) {
		int answer;

		if (!addCheck)
			break;

		line(70);
		cout << "1 - ���������� ������������ ����������" << endl;
		cout << "2 - ���������� ���������� �� ������" << endl;
		cout << "3 - ������� ���� ������ �������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
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
		int answer;

		line(70);
		person.personInfo();
		line(70);
		cout << "1 - �������� ������������ ����������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
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
	int answer;

	line(70);
	cout << "��� �� ������ ��������?" << endl;
	line(70);
	cout << "1 - ���" << endl;
	cout << "2 - �������" << endl;
	cout << "3 - ��������" << endl;
	cout << "4 - �������" << endl;
	cout << "5 - �������" << endl;
	cout << "6 - ������" << endl;
	line(70);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ��������� 
	line(70);
	
	switch (answer) {
	case 1: person.enterName(); 
		break;
	case 2: person.enterSurname();
		break;
	case 3: person.enterPatronymic();
		break;
	case 4: person.enterAge();
		break;
	case 5: person.enterNik();
		break;
	case 6: person.enterPassword();
		break;
	default: thereIsNoSuchTipeOfAnswer();
	}
	system("cls"); //������� ��������� 
}

void user_infoAboutBankAccount() {
	for (;;) {
		int answer, aboutWhich;

		if (person.personAccs.empty()) {
			line(70);
			cout << "\t\t\t � ��� ��� ��� ������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}
		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ����, ��� �������\n������ ���������� ����������: ";
		cin >> aboutWhich;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		bankAcc = BankAccount();  
		//������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//����� ������� ����� �� ������
			if (temp.number == aboutWhich) {
				//������� ������� ������
				for (auto& accs : accounts) {
					//����� ������� ����� � ����� ����������
					if (accs.AccNumber == temp.AccNumber) {
						accs.bankAccountInfo();
						bankAcc = accs;
					}
				}
			}
		}
		line(70);
		cout << "1 - �������� ����������" << endl;
		cout << "2 - ���������� ���������� �����" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;

		system("cls");//������� ��������

		if (answer == 1) {
			user_chengeInfoAboutBankAccount(aboutWhich);
			break;
		}
		else if (answer == 2) {
			if (bankAcc.transactions1.empty() && bankAcc.transactions2.empty()) {
				line(70);
				cout << "\t\t ������ ���������� � ����� ����� ����!" << endl;
				line(70);
				Sleep(3000);  //�������� 3 �������
				system("cls");//������� ���������
				break;
			}
			else {
				user_infoAboutTransaction();
				break;
			}
		}
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_infoAboutTransaction() {
	for (;;) {
		int answer, choise;

		line(70);
		cout << "1 - ���������� ����� ������ �������" << endl;
		cout << "2 - ���������� ����� ������� �������" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> choise;
		system("cls"); //������� ���������

		if (choise == 1) {
			//���� ������ ��� ������
			if (bankAcc.transactions1.empty()) {
				line(70);
				cout << "\t ������ ����������� ����� ������������� ������� ����!" << endl;
				line(70);
				Sleep(3000);  //�������� 3 �������
				system("cls");//������� ���������
				break;
			}

			line(70);
			int a = 0; //������� ��� ���������
			//������� ������� � ����� ������ ����������
			for (auto& temp : bankAcc.transactions1) {
				temp.number = a + 1;  //������������ ���������� ������
				cout << temp << endl; //����� �������� ����������

				a++; //���������� �������� ���������
			}
			line(70);
			cout << "�������� ����� ����������\n��� ������� ������ ������� ����������: ";
			cin >> answer;
			system("cls"); //������� ���������

			//�������� �� ������������ ������
			if (answer < 1 || answer > bankAcc.transactions1.size()) {
				thereIsNoSuchTipeOfAnswer();
				break;
			}

			line(70);
			for (auto& temp : bankAcc.transactions1) {
				//����� ������ ����������
				if (temp.number == answer)
					temp.printInfo1();
			}
		}
		else if (choise == 2) {
			//���� ������ ��� ������
			if (bankAcc.transactions2.empty()) {
				line(70);
				cout << "\t ������ ����������� ����� ������� ������ ������������� ����!" << endl;
				line(70);
				Sleep(3000);  //�������� 3 �������
				system("cls");//������� ���������
				break;
			}

			line(70);
			int a = 0; //������� ��� ���������
			//������� ������� � ����� ������ ����������
			for (auto& temp : bankAcc.transactions2) {
				temp.number = a + 1;  //������������ ���������� ������
				cout << temp << endl; //����� �������� ����������

				a++; //���������� �������� ���������
			}
			line(70);
			cout << "�������� ����� ����������\n��� ������� ������ ������� ����������: ";
			cin >> answer;
			system("cls"); //������� ���������

			//�������� �� ������������ ������
			if (answer < 1 || answer > bankAcc.transactions2.size()) {
				thereIsNoSuchTipeOfAnswer();
				break;
			}

			line(70);
			for (auto& temp : bankAcc.transactions2) {
				//����� ������ ����������
				if (temp.number == answer)
					temp.printInfo2();
			}
		}
		else {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		cout << "0 - ��������� �����" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������

		if (answer == 0)
			break;
		else {
			thereIsNoSuchTipeOfAnswer();
			line(70);
			cout << "\t\t\t������� �����!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}
	}
}

void user_chengeInfoAboutBankAccount(int aboutWhich) {
	int answer;

	line(70);
	cout << "��� �� ������ ��������?" << endl;
	line(70);
	cout << "1 - ����� �����" << endl;
	cout << "2 - id �����" << endl;
	cout << "3 - ���������� �����" << endl;
	cout << "4 - ������ �����" << endl;
	line(70);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ���������
	line(70);

	switch (answer) {
	case 1: bankAcc.numberGeneration();
		break;
	case 2: bankAcc.idGeneration();
		break;
	case 3: bankAcc.enterPurpose();
		break;
	case 4: bankAcc.enterPassword();
		break;
	default: thereIsNoSuchTipeOfAnswer();
	}

	//������� ������� ������ ������������
	for (auto temp : person.personAccs) {
		//����� ������� �����
		if (temp.number == aboutWhich) {
			int index = aboutWhich - 1;
			auto iter = person.personAccs.begin() + index;
			person.personAccs.erase(iter);

			person.personAccs.push_back(bankAcc);
			//�������� ������� ������
			for (auto& accs : accounts) {
				if (accs.AccNumber == temp.AccNumber)
					accs = bankAcc;
			}
		}
	}

	Sleep(2000);   //�������� 2 �������
	system("cls"); //������� ���������
}

void user_delPrivateOffice() {
	int answer;

	line(70);
	cout << "�� ������������� ������ ������� ���� �������?\n(1 - ��, 0 - ���)" << endl;
	line(70);
	cout << "��� �����: ";
	cin >> answer;
	system("cls"); //������� ���������

	if (answer == 1) { //���� ������������ ���������� ��������
		line(70);
		cout << "\t\t ������������ ��� ������� �����!" << endl;
		line(70);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
		addCheck = false;
	}
	else if (answer == 0) { //���� ������������ ������� ��������
		line(70);
		cout << "\t\t\t �������� ��������!" << endl;
		line(70);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
	else { //���� ������������ ��� ������������ �����
		line(70);
		cout << "\t\t\t������ ������ ����!\n\t\t\t�������� ��������!" << endl;
		line(70);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
}

void user_addBankAccount() {
	bankAcc = BankAccount(); //������� ��������� ������ �� �����

	if (person.getCount() == 3) {
		line(70);
		cout << "\t� ��� ��� ���� 3 �����, ��� ������������ ���������� ������!" << endl;
		line(70);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������
	}
	else {
		person.countIncrement(); //����������� ������� ���������� ������ ������������
		line(70);
		bankAcc.setOwner(person.getFullName());
		bankAcc.enterPurpose();
		bankAcc.enterMoney();
		bankAcc.enterPassword();
		bankAcc.idGeneration();
		bankAcc.numberGeneration();
		line(70);
		Sleep(2000);  //�������� 2 �������
		system("cls");//������� ���������

		person.personAccs.push_back(bankAcc);//���������� ����� � ������ ������ ������������
		accounts.push_back(bankAcc);         //���������� ����� � ������ ������
	}
}

void user_delBankAccount() {
	for (;;) {
		int whoDelete, answer;

		if (person.personAccs.empty()) {
			line(70);
			cout << "\t\t\t � ��� ��� ��� ������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}
		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ����, ������� ������ �������: ";
		cin >> whoDelete;
		system("cls");//������� ��������
		//�������� �� ������������ ����� ������� �����
		if (whoDelete < 1 || whoDelete > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		cout << "�� ������������� ������ ������� ���� ����?\n(1 - ��, 0 - ���)" << endl;
		line(70);
		cout << "��� �����: ";
		cin >> answer;
		system("cls"); //������� ���������
		if (answer == 1) { //���� ������������ ���������� ��������
			person.countDicrement(); //�������� ������� ���������� ������ ������������
			
			int index = whoDelete - 1;
			auto iter = person.personAccs.begin() + index;

			person.personAccs.erase(iter); //�������� ����� �� ������ ������ ������������

			line(70);
			cout << "\t\t\t���� ���� ��� ������� �����!" << endl;
			line(70);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
		else if (answer == 0) { //���� ������������ ������� ��������
			system("mode con cols=20 lines=4"); //������������� ������ ����

			line(70);
			cout << "\t\t\t �������� ��������!" << endl;
			line(70);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
		else { //���� ������������ ��� ������������ �����
			system("mode con cols=20 lines=4"); //������������� ������ ����

			line(70);
			cout << "\t\t\t ������ ������ ����!\n\t\t\t�������� ��������!" << endl;
			line(70);

			Sleep(2000);   //�������� 2 �������
			system("cls"); //������� ���������
			break;
		}
	}
}

void user_sendMoney() {
	for (;;) {
		int answer;

		if (person.personAccs.empty()) {
			line(70);
			cout << "\t\t\t � ��� ��� ��� ������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(70);
		cout << "1 - ��������� ������ �� ���� ����" << endl;
		cout << "2 - ��������� ������ �� ���� ������� ������������" << endl;
		cout << "0 - ��������� �����" << endl;
		line(70);
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
		int firstAcc, secondAcc;
		double sum;
		bool checkMoney = true;

		if (person.personAccs.size() == 1) {
			line(70);
			cout << "\t\t\t� ��� ��� ��� ������� �����!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ���������
			break;
		}

		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ���� � �������� ������ ��������� ������: ";
		cin >> firstAcc;
		system("cls");//������� ��������
		//�������� �� ������� ������ ������ ����� � ������������
		if (firstAcc < 1 || firstAcc > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}

		line(70);
		a = 0; //������� �������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ���� �� ������� ������ ��������� ������: ";
		cin >> secondAcc;
		system("cls");//������� ��������
		//�������� �� ������� ������ ������ ����� � ������������
		if (secondAcc < 1 || secondAcc > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		//�������� �� ���������� ������� ����� 
		if (firstAcc == secondAcc) {
			line(70);
			cout << "\t\t\t   ������! �������� ��������!" << endl;
			cout << "\t\t\t�� ������� ��� ���������� �����!" << endl;
			line(70);
			Sleep(5000);  //�������� 5 �������
			system("cls");//������� ���������
			break;
		}
		line(70);
		cout << "������� ����� ��������: ";
		cin >> sum;
		system("cls");//������� ��������
		//���� ��� �������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//�������� �� ������� �����, �������� ����
			if (temp.number == firstAcc) {
				if (sum > temp.money) {
					checkMoney = false;
					line(70);
					cout << "\t\t\t\t ������! �������� ��������!" << endl;
					cout << "�����, ������� �� �����, ��������� �����, ������� ���� �� ����� �����!" << endl;
					line(70);
					Sleep(5000);  //�������� 5 ������
					system("cls");//������� ���������
					break;
				}
			}
			//����� ������ � �������� ���������� � �� ������� ����������
			if (temp.number == firstAcc || temp.number == secondAcc) {
				if (temp.number == firstAcc) { //������ ����
					temp.money -= sum;

					payment.firstAcc = temp.purpose;
					payment.money = sum;
					payment.balance = temp.money;
					line(70);
					payment.enterPaymentName();
					payment.getPaymentTime();
					//������� ������ ������
					for (auto& accs : accounts) {
						//����� ������� �����
						if (accs.AccNumber == temp.AccNumber)
							accs.money -= sum;
					}
				}
				else { //������ ����
					temp.money += sum;

					payment.secondAcc = temp.purpose;
					//������� ������ ������
					for (auto& accs : accounts) {
						//����� ������� �����
						if (accs.AccNumber == temp.AccNumber)
							accs.money += sum;
					}
				}
			}
		}
		//���������� �������� �� ��� �����
		for (auto& temp : person.personAccs) {
			if (temp.number == firstAcc || temp.number == secondAcc) {
				//������� ������� ������
				for (auto& accs : accounts) {
					//����� ������� ����� � ���������� ����������
					if (accs.AccNumber == temp.AccNumber) {
						accs.transactions1.push_back(payment);
					}
				}
			}
		}

		if (checkMoney == false)
			break;
		else {
			line(70);
			cout << "\t\t\t ����� ������� ����������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ��������
			break;
		}
	}
}

void user_sendMoneyToOtherAcc() {
	for (;;) {
		int firstAcc;
		string secondAcc;
		double sum;
		bool checkMoney = true;

		line(70);
		int a = 0; //������� ��� ���������
		//������� ������� � ����� ������ ������
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //������������ ����� ������
			cout << temp << endl; //����� ������ ����� � ����������

			a++; //���������� �������� ���������
		}
		line(70);
		cout << "�������� ���� � �������� ������ ��������� ������: ";
		cin >> firstAcc;
		system("cls");//������� ��������
		//�������� �� ������� ������ ������ ����� � ������������
		if (firstAcc < 1 || firstAcc > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}

		line(70);
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
			line(70);
			cout << "\t\t\t������! �������� ��������!" << endl;
			cout << "\t\t\t����� � ����� ������� ���!" << endl;
			line(70);
			Sleep(3000);  //�������� 3 �������
			system("cls");//������� ���������
			break;
		}

		line(70);
		cout << "������� ����� ��������: ";
		cin >> sum;
		system("cls");//������� ��������
		//���� ��� �������� ������� ������ ������������
		for (auto& temp : person.personAccs) {
			//�������� �� ������� �����, �������� ����
			if (temp.number == firstAcc)
				if (sum > temp.money) {
					checkMoney = false;
					line(70);
					cout << "\t\t\t\t ������! �������� ��������!" << endl;
					cout << "�����, ������� �� �����, ��������� �����, ������� ���� �� ����� �����!" << endl;
					line(70);
					Sleep(3000);  //�������� 3 �������
					system("cls");//������� ���������
					break;
				}
			//����� ����� � �������� ����������
			if (temp.number == firstAcc) {
				temp.money -= sum;

				payment.sender = temp.owner;
				payment.money = sum;
				payment.balance = temp.money;
				line(70);
				payment.enterPaymentName();
				payment.getPaymentTime();
				//������� ������ ������
				for (auto& accs : accounts) {
					//����� ������� �����
					if (accs.AccNumber == temp.AccNumber)
						accs.money -= sum;
				}
			}
		}
		//������� ������� ������ 
		for (auto& temp : accounts) {
			//����� ����� �� ������ ����������
			if (temp.AccNumber == secondAcc) {
				temp.money += sum;
				payment.recipient = temp.owner;
			}
		}
		//���������� ������� � ������ ����
		for (auto& temp : person.personAccs) {
			//����� ������� �����
			if (temp.number == firstAcc) {
				//������� ������� ������
				for (auto& accs : accounts) {
					//����� ������� ����� � ���������� ����������
					if (accs.AccNumber == temp.AccNumber) {
						accs.transactions2.push_back(payment);
					}
				}
			}
		}
		//���������� ������� �� ������� ����
		for (auto& temp : accounts) {
			if (temp.AccNumber == secondAcc)
				temp.transactions2.push_back(payment);
		}

		if (checkMoney == false)
			break;
		else {
			line(70);
			cout << "\t\t\t ����� ������� ����������!" << endl;
			line(70);
			Sleep(2000);  //�������� 2 �������
			system("cls");//������� ��������
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------