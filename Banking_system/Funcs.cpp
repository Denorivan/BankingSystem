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
	SetConsoleTextAttribute(color, 3); //Установка цвета в консоли: 3 (синий)
	for (int i = 0; i < a; i++)
		cout << "~";
	cout << endl;
	SetConsoleTextAttribute(color, 7); //Установка цвета в консоли: 7 (белый)
}

void thereIsNoSuchTipeOfAnswer() {
	system("mode con cols=30 lines=5"); //Устанавливает размер окна

	line(30);
	cout << "Такого ответа нет!" << endl;
	cout << "Проверьте и попробуйте ещё раз" << endl;
	line(30);
	Sleep(3000);
	system("cls");
}
//----------------------------------------------------------------------------------------------------------------
void fileForRead() {
	ifstream fin;
	string pathToPeople = "People.txt";
	string pathToAccounts = "Accounts.txt";

	//Чтение файла в котором хранятся пользователи - начало
	fin.open(pathToPeople);

	if (fin.is_open()) {
		while (fin.read((char*)&person, sizeof(Person))) {
			people.push_back(person);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//Чтение файла в котором хранятся пользователи - конец

	//Чтение файла в котором хранятся счета - начало
	fin.open(pathToAccounts);

	if (fin.is_open()) {
		while (fin.read((char*)&bankAcc, sizeof(BankAccount))) {
			accounts.push_back(bankAcc);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//Чтение файла в котором хранятся счета - конец
	
	//Для добавления нужных счетов, полученых из файла, в аккаунт нужного пользователя
	for (auto& accs : accounts) { //Цикл для перебора списка счетов
		for (auto& pers : people) { //Цикл для перебора списка пользователей
			for (auto& nums : pers.vecForNums) { //Цикл для перебора списка номеров счетов пользователя
				//Если номер счета совпал с номером счёта пользователя - добавление этого счёта в акк
				if (accs.AccNumber == nums) 
					pers.personAccs.push_back(accs);
			}
		}
	}
}

void startMenu() {
	for (;;) {
		system("mode con cols=30 lines=7"); //Устанавливает размер окна

		int choice;

		line(30);
		cout << "1 - Войти как администратор" << endl;
		cout << "2 - Войти как пользователь" << endl;
		cout << "0 - Выйти" << endl;
		line(30);
		cout << "Ваш выбор: ";
		cin >> choice;

		system("cls"); //Очистка терминала 

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
			cout << "Хорошо, до свидания!" << endl;
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

	//Открытие файла в котором хранятся пользователи, для затирки данных
	fout.open(pathToPeople, ofstream::trunc);
	fout.close();
	//Открытие файла в котором хранятся счета, для затирки данных
	fout.open(pathToAccounts, ofstream::trunc);
	fout.close();

	//Запись в файл в котором хранятся пользователи - начало
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
	//Запись в файл в котором хранятся пользователи - конец

	//Запись в файл в котором хранятся счета - начало
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
	//Запись в файл в котором хранятся счета - конец
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	system("mode con cols=30 lines=3"); //Устанавливает размер окна

	string password;

	line(30);
	cout << "Введите пароль: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
		system("mode con cols=30 lines=5"); //Устанавливает размер окна
		line(30);
		cout << "Пароль не правильный!" << endl;
		cout << "Доступ запрещён!" << endl;
		line(30);
		Sleep(3000);
		system("cls");
	}
}

void admin_menu() {
	for (;;) {
		system("mode con cols=25 lines=7"); //Устанавливает размер окна

		int answer;

		line(25);
		cout << "1 - Список пользователей" << endl;
		cout << "2 - Удалить пользователя" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(25);
		cout << "Ваш выбор: ";
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
		system("mode con cols=35 lines=15"); //Устанавливает размер окна

		int answer;

		if (people.empty()) { //Если список пуст
			system("mode con cols=30 lines=4"); //Устанавливает размер окна
			line(30);
			cout << "Список пользователей пуст!" << endl;
			line(30);
			Sleep(2500);   //Задержка в 2 секунды
			system("cls"); //Очистка терминала

			break;
		}

		line(35);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка всех пользователей
		for (auto& temp : people) {
			temp.number = a + 1;  //Присваивания пользователям номера
			cout << temp << endl; //Вывод номера, имени и фамилии пользователя

			a++; //Увиличение счётчика нумерации
		}
		line(35);
		cout << "1 - Посмотреть детальную информацию" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(35);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");

		if (answer == 1) {
			system("mode con cols=40 lines=10"); //Устанавливает размер окна

			int who;

			line(40);
			a = 0; //Счётчик для нумерации
			//Перебор массива и вывод списка всех пользователей
			for (auto& temp : people) {
				temp.number = a + 1;  //Присваивания пользователям номера
				cout << temp << endl; //Вывод номера, имени и фамилии пользователя

				a++; //Увиличение счётчика нумерации
			}
			line(40);
			cout << "Про кого вы хотите увидеть информацию?" << endl;
			cout << "Введите цифру: ";
			cin >> who;
			system("cls"); //Очистка терминала
			admin_infoAboutUser(who); //Вызов функции которая даёт детальную информацию
		}
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_infoAboutUser(int aboutWho) {
	for (;;) {
		system("mode con cols=35 lines=11"); //Устанавливает размер окна

		int answer;
		//Проверка на правильность ввода номерва пользователя
		if (aboutWho < 1 || aboutWho > people.size()) {
			system("mode con cols=40 lines=10"); //Устанавливает размер окна
			line(40);
			cout << "Вы ввели неправильный номер!" << endl;
			cout << "Проверьте и попробуйте ещё раз!" << endl;
			line(40);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		//Функция стандартной бибдиотеки STL для поиска
		auto res = find_if(people.begin(), people.end(), [&aboutWho](Person& p)
		{
			//Если пользователь найден
			if (aboutWho == p.number) {
				line(35);
				p.personInfo(); //Вывод подробной информации про пользователя
			}

			return 0;
		});

		line(35);
		cout << "1 - Посмотреть информацию по счетам" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(35);
		cout << "Ваш выбор: ";
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
		system("mode con cols=40 lines=11"); //Устанавливает размер окна

		int answer;

		if (person.personAccs.empty()) {
			system("mode con cols=40 lines=4"); //Устанавливает размер окна
			line(40);
			cout << "У этого пользователя ещё нет счетов!" << endl;
			line(40);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(40);
		int a = 0; //Счётчик для нумерации
		//Перебор вектора и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(40);
		cout << "Выберите счёт, про который\nхотите посмотреть информацию: ";
		cin >> aboutWhich;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(40);
		//Перебор вектора и поиск нужного счета
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich)
				temp.bankAccountInfo();
		}
		line(40);
		cout << "0 - Вернуться назад" << endl;
		line(40);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");//Очистка терминал

		if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void admin_delUser() {
	for (;;) {
		system("mode con cols=35 lines=10"); //Устанавливает размер окна

		int answer, whoDelete, index;

		line(35);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка всех пользователей
		for (auto& temp : people) {
			temp.number = a + 1;  //Присваивания пользователям номера
			cout << temp << endl; //Вывод номера, имени и фамилии пользователя

			a++; //Увиличение счётчика нумерации
		}
		line(35);
		cout << "Введите номер кого нужно удалить: ";
		cin >> whoDelete;
		system("cls"); //Очистка терминала
		//Проверка на правильность ввода номерва пользователя
		if (whoDelete < 1 || whoDelete > people.size()) {
			system("mode con cols=40 lines=10"); //Устанавливает размер окна
			line(40);
			cout << "Вы ввели неправильный номер!" << endl;
			cout << "Проверьте и попробуйте ещё раз!" << endl;
			line(40);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(35);
		cout << "Вы действительно хотите удалить\nэтого пользователя?\n(1 - да, 0 - нет)" << endl;
		line(35);
		cout << "Ваш ответ: ";
		cin >> answer;
		system("cls"); //Очистка терминала
		if (answer == 1) { //Если пользователь подтвердил удаление				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(35);
			cout << "Студент был успешно удалён!" << endl;
			line(35);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		else if (answer == 0) { //Если пользователь отменил удаление
			line(35);
			cout << "Операция отменена!" << endl;
			line(35);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		else { //Если пользователь ввёл неправильное число
			line(35);
			cout << "Такого ответа нету!\nОперация отменена!" << endl;
			line(35);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------
bool addCheck = true; //Переменная для проверки добавлять ли пользователя в общий список

void user_accSelection() {
	for (;;) {
		system("mode con cols=30 lines=7"); //Устанавливает размер окна

		int answer;

		line(30);
		cout << "1 - Существующий пользователь" << endl;
		cout << "2 - Новый пользователь" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(30);
		cout << "Ваш выбор: ";
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
	int check = 0; //Счётчик для количества попыток ввода пароля

	for (;;) {
		system("mode con cols=30 lines=7"); //Устанавливает размер окна

		string nik, password;

		if (people.empty()) { //Если список пуст
			system("mode con cols=30 lines=4"); //Устанавливает размер окна]

			line(30);
			cout << "Список пользователей пуст!" << endl;
			line(30);
			Sleep(2500);   //Задержка в 2.5 секунды
			system("cls"); //Очистка терминала

			break;
		}

		if (check == 3) {
			system("mode con cols=30 lines=4"); //Устанавливает размер окна
			line(30);
			cout << "Вы уже использовали слишком\nмного попыток на вход!" << endl;
			line(30);     
			Sleep(3000);  //Задержка в 3 секунды
			system("cls");//Очистка терминала
			break;
		}
		
		line(30);
		cout << "Введите никнейм пользователя:" << endl;;
		cin >> nik;
		cout << "Введите пароль пользователя:" << endl;
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
					system("mode con cols=20 lines=4"); //Устанавливает размер окна
					line(20);
					cout << "Пароль не верный!" << endl;
					line(20);
					check++;      //Увеличение счётчика
					Sleep(3000);  //Задержка в 3 секунды
					system("cls");//Очистка терминала
				}
			}
			else {
				system("mode con cols=30 lines=4"); //Устанавливает размер окна
				line(30);
				cout << "Пользователя с таким\nникнеймом не существует!" << endl;
				line(30);
				check++;      //Увеличение счётчика
				Sleep(3000);  //Задержка в 3 секунды
				system("cls");//Очистка терминала
			}

			return 0;
		});
	}
}

void user_newAcc() {
	system("mode con cols=40 lines=7"); //Устанавливает размер окна

	line(40);
	person.enterName();
	person.enterSurname();
	person.enterAge();
	system("cls"); //Очистка терминала
	line(40);
	person.enterNik();
	//Проверка на совпадение никнейма
	for (auto& temp : people) {
		if (temp.getNik() == person.getNik()) {
			line(40);
			cout << "Пользователь с таким никнеймом\nуже существует!" << endl;
			line(40);
			Sleep(3000);  //Задержка в 3 секунды
			system("cls");//Очистка терминала
			line(40);
			person.enterNik();
		}
	}
	person.enterPassword();

	system("cls"); //Очистка терминала

	user_menu();
}

void user_menu() {
	for (;;) {
		system("mode con cols=20 lines=9"); //Устанавливает размер окна

		int answer;

		if (!addCheck) 
			break;

		line(20);
		cout << "1 - Личный кабинет" << endl;
		cout << "2 - Добавить счёт" << endl;
		cout << "3 - Удалить счёт" << endl;
		cout << "4 - Перевести деньги" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(20);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls"); //Очистка терминала

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
		system("mode con cols=40 lines=8"); //Устанавливает размер окна

		int answer;

		if (!addCheck)
			break;

		line(40);
		cout << "1 - Посмотреть персональную информацию" << endl;
		cout << "2 - Посмотреть информацию по счетам" << endl;
		cout << "3 - Удалить этот личный кабинет" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(40);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls"); //Очистка терминала

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
		system("mode con cols=40 lines=12"); //Устанавливает размер окна

		int answer;

		line(40);
		person.personInfo();
		line(40);
		cout << "1 - Изменить персональную информацию" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(40);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls"); //Очистка терминала

		if (answer == 1)
			user_chengeInfoAboutUser();
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_chengeInfoAboutUser() {
	system("mode con cols=25 lines=10"); //Устанавливает размер окна

	int answer;

	line(25);
	cout << "Что вы хотите поменять?" << endl;
	line(25);
	cout << "1 - Имя" << endl;
	cout << "2 - Фамилия" << endl;
	cout << "3 - Возраст" << endl;
	cout << "4 - Никнейм" << endl;
	cout << "5 - Пароль" << endl;
	line(25);
	cout << "Ваш выбор: ";
	cin >> answer;
	system("cls"); //Очистка терминала 
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
	system("cls"); //Очистка терминала 
}

void user_infoAboutBankAccount() {
	for (;;) {
		system("mode con cols=40 lines=14"); //Устанавливает размер окна

		int answer, aboutWhich;

		if (person.personAccs.empty()) {
			system("mode con cols=25 lines=4"); //Устанавливает размер окна
			line(25);
			cout << "У вас ещё нет счетов!" << endl;
			line(25);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(40);
		int a = 0; //Счётчик для нумерации
		//Перебор вектора и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(40);
		cout << "Выберите счёт, про который\nхотите посмотреть информацию: ";
		cin >> aboutWhich;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(40);
		//Перебор вектора и поиск нужного счета
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich)
				temp.bankAccountInfo();
		}
		line(40);
		cout << "1 - Изменить информацию" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(40);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");//Очистка терминал

		if (answer == 1)
			user_chengeInfoAboutBankAccount(aboutWhich);
		else if (answer == 0)
			break;
		else
			thereIsNoSuchTipeOfAnswer();
	}
}

void user_chengeInfoAboutBankAccount(int aboutWhich) {
	system("mode con cols=25 lines=11"); //Устанавливает размер окна

	int answer;

	//Перебор вектора и поиск нужного счета в аккаунте пользователя
	for (auto& temp : person.personAccs) {
		if (temp.number == aboutWhich) {
			bankAcc = temp;
			auto iter = person.personAccs.begin() + (temp.number - 1);
			person.personAccs.erase(iter);
		}
	}

	//Перебор вектора и поиск нужного счета в общем списке счетов
	int a = 0; //Счётчик для нумерации
	for (auto& temp : accounts) {
		temp.number = a + 1; //Присваивание счетам общего списка номера
		if (temp.number == aboutWhich) {
			bankAcc = temp;
			auto iter = accounts.begin() + (temp.number - 1);
			accounts.erase(iter);
		}
		a++; //Увеличение счётчика
	}

	line(25);
	cout << "Что вы хотите поменять?" << endl;
	line(25);
	cout << "1 - Номер счёта" << endl;
	cout << "2 - id счёта" << endl;
	cout << "3 - Владельца счёта" << endl;
	cout << "4 - Назначение счёта" << endl;
	cout << "5 - Пароль счёта" << endl;
	line(25);
	cout << "Ваш выбор: ";
	cin >> answer;
	system("cls"); //Очистка терминала
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

	Sleep(2000);   //Задержка 2 секунды
	system("cls"); //Очистка терминала

	person.personAccs.push_back(bankAcc); //Перезаписывание счёта в аккаунт пользователя
	accounts.push_back(bankAcc);          //Перезаписывание счёта в общий список счетов
}

void user_delPrivateOffice() {
	system("mode con cols=45 lines=6"); //Устанавливает размер окна

	int answer;

	line(45);
	cout << "Вы действительно хотите удалить этот аккаунт?\n(1 - да, 0 - нет)" << endl;
	line(45);
	cout << "Ваш ответ: ";
	cin >> answer;
	system("cls"); //Очистка терминала

	if (answer == 1) { //Если пользователь подтвердил удаление
		system("mode con cols=32 lines=4"); //Устанавливает размер окна

		line(32);
		cout << "Пользователь был успешно удалён!" << endl;
		line(32);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
		addCheck = false;
	}
	else if (answer == 0) { //Если пользователь отменил удаление
		system("mode con cols=20 lines=4"); //Устанавливает размер окна

		line(20);
		cout << "Операция отменена!" << endl;
		line(20);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
	}
	else { //Если пользователь ввёл неправильное число
		system("mode con cols=20 lines=4"); //Устанавливает размер окна

		line(20);
		cout << "Такого ответа нету!\nОперация отменена!" << endl;
		line(20);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
	}
}

void user_addBankAccount() {
	system("mode con cols=40 lines=9"); //Устанавливает размер окна

	if (person.count == 3) {
		system("mode con cols=60 lines=4"); //Устанавливает размер окна
		line(60);
		cout << "У вас уже есть 3 счета, это максимальное количество счетов!" << endl;
		line(60);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
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
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала

		person.vecForNums.push_back(bankAcc.AccNumber); //Добавление номера в вектор для номеров
		person.personAccs.push_back(bankAcc);           //Добавление счёта в список счетов пользователя
		accounts.push_back(bankAcc);                    //Добавление счёта в ощий список счетов
	}
}

void user_delBankAccount() {
	for (;;) {
		system("mode con cols=40 lines=9"); //Устанавливает размер окна

		int whoDelete, answer;

		if (person.personAccs.empty()) {
			system("mode con cols=15 lines=4"); //Устанавливает размер окна
			line(15);
			cout << "У вас ещё нет счетов!" << endl;
			line(15);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(40);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(40);
		cout << "Выберите счёт, который хотите удалить: ";
		cin >> whoDelete;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (whoDelete < 1 || whoDelete > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		system("mode con cols=42 lines=5"); //Устанавливает размер окна
		line(42);
		cout << "Вы действительно хотите удалить этот счёт?\n(1 - да, 0 - нет)" << endl;
		line(42);
		cout << "Ваш ответ: ";
		cin >> answer;
		system("cls"); //Очистка терминала
		if (answer == 1) { //Если пользователь подтвердил удаление	
			system("mode con cols=30 lines=4"); //Устанавливает размер окна
			person.count -= 1;
			
			int index = whoDelete - 1;
			auto iter1 = person.vecForNums.begin() + index;
			auto iter2 = person.personAccs.begin() + index;

			person.vecForNums.erase(iter1); //Удаление определённого номера счёта из списка номеров
			person.personAccs.erase(iter2); //Удаление счёта из списка счетов пользователя

			line(30);
			cout << "Этот счёт был успешно удалён!" << endl;
			line(30);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
		else if (answer == 0) { //Если пользователь отменил удаление
			system("mode con cols=20 lines=4"); //Устанавливает размер окна

			line(20);
			cout << "Операция отменена!" << endl;
			line(20);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
		else { //Если пользователь ввёл неправильное число
			system("mode con cols=20 lines=4"); //Устанавливает размер окна

			line(20);
			cout << "Такого ответа нету!\nОперация отменена!" << endl;
			line(20);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
	}
}

void user_sendMoney() {
	for (;;) {
		system("mode con cols=50 lines=7"); //Устанавливает размер окна

		int answer;

		if (person.personAccs.empty()) {
			system("mode con cols=15 lines=4"); //Устанавливает размер окна
			line(15);
			cout << "У вас ещё нет счетов!" << endl;
			line(15);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(50);
		cout << "1 - Перевести деньги на свой счёт" << endl;
		cout << "2 - Перевести деньги на счёт другого пользователя" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(50);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");//Очистка терминала

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
		system("mode con cols=55 lines=10"); //Устанавливает размер окна

		int firstAcc, secondAcc;
		double sum;

		if (person.personAccs.size() == 1) {
			system("mode con cols=30 lines=4"); //Устанавливает размер окна
			line(30);
			cout << "У вас ещё нет другого счёта!" << endl;
			line(30);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(55);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(55);
		cout << "Выберите счёт с которого хотите перевести деньги: ";
		cin >> firstAcc;
		system("cls");//Очистка терминал

		line(55);
		a = 0; //Онуляем счётчик
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(55);
		cout << "Выберите счёт на который хотите перевести деньги: ";
		cin >> secondAcc;
		system("cls");//Очистка терминал

		if (firstAcc == secondAcc) {
			system("mode con cols=35 lines=5"); //Устанавливает размер окна
			line(35);
			cout << "Ошибка! Операция отменена!" << endl;
			cout << "Вы выбрали два одинаковых счёта!" << endl;
			line(35);
			Sleep(3000);  //Задержка 3 секунды
			system("cls");//Очистка терминала
			break;
		}
		system("mode con cols=30 lines=4"); //Устанавливает размер окна
		line(30);
		cout << "Введите сумму перевода: ";
		cin >> sum;
		system("cls");//Очистка терминал
		//Цикл для перебора вектора счетов пользователя
		for (auto& temp : person.personAccs) {
			//Поиск счёта с которого переводить
			if (temp.number == firstAcc)
				temp.money -= sum;
			//Поиск счёта на который переводить
			if (temp.number == secondAcc)
				temp.money += sum;
		}

		line(30);
		cout << "Сумма успешно отправлена!";
		line(30);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминал
		break;
	}
}

void user_sendMoneyToOtherAcc() {
	for (;;) {
		system("mode con cols=55 lines=10"); //Устанавливает размер окна

		int firstAcc;
		string secondAcc;
		double sum;

		line(55);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(55);
		cout << "Выберите счёт с которого хотите перевести деньги: ";
		cin >> firstAcc;
		system("cls");//Очистка терминал

		line(55);
		cout << "Введите номер счёта на который хотите перевести деньги:" << endl;
		cin.ignore(32767, '\n'); //Игнорируем символы перевода строки "\n" во входящем потоке
		getline(cin, secondAcc);
		system("cls");//Очистка терминал

		//Проверка на наличие такого номера счёта у других пользователей
		bool check = true;
		for (auto& temp : accounts) {
			if (temp.AccNumber == secondAcc)
				check = false;
		}
		if (check) {
			system("mode con cols=30 lines=5"); //Устанавливает размер окна
			line(30);
			cout << "Ошибка! Операция отменена!" << endl;
			cout << "Счёта с таким номером нет!" << endl;
			line(30);
			Sleep(3000);  //Задержка 3 секунды
			system("cls");//Очистка терминала
			break;
		}

		system("mode con cols=30 lines=4"); //Устанавливает размер окна

		line(30);
		cout << "Введите сумму перевода: ";
		cin >> sum;
		system("cls");//Очистка терминал
		//Цикл для перебора вектора счетов пользователя
		for (auto& temp : person.personAccs) {
			//Поиск счёта с которого переводить
			if (temp.number == firstAcc)
				temp.money -= sum;
		}
		//Цикл для перебора вектора счетов
		for (auto& temp : accounts) {
			//Поиск счёта на который переводить
			if (temp.AccNumber == secondAcc)
				temp.money += sum;
		}

		line(30);
		cout << "Сумма успешно отправлена!";
		line(30);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминал
		break;
	}
}
//----------------------------------------------------------------------------------------------------------------