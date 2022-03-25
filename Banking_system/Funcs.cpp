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
		Person copy;

		while (fin.read((char*)&copy, sizeof(Person))) {
			people.push_back(copy);
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fin.close();
	//Чтение файла в котором хранятся пользователи - конец

	//Чтение файла в котором хранятся счета - начало
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
	//Чтение файла в котором хранятся счета - конец
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
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
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
			fout.write((char*)&temp, sizeof(Person));
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
			fout.write((char*)&temp, sizeof(BankAccount));
		}
	}
	else
		cout << "File wasn't opened!" << endl;

	fout.close();
	//Запись в файл в котором хранятся счета - конец
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	system("mode con cols=30 lines=10"); //Устанавливает размер окна

	string password;

	line(30);
	cout << "Введите пароль: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
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
			line(35);
			cout << "Список пользователей пуст!" << endl;
			line(35);
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
			system("mode con cols=40 lines=4"); //Устанавливает размер окна

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
		system("mode con cols=35 lines=10"); //Устанавливает размер окна

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
		auto res = find_if(people.begin(), people.end(), [&aboutWho](Person& person)
		{
			//Если пользователь найден
			if (aboutWho == person.number) {
				line(35);
				person.personInfo(); //Вывод подробной информации про пользователя
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
			int a; //Место для втавления функции для просмотра инфы по счетам
		else if (answer == 0)
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
		cout << "Ваш ответ: ";
		cin >> answer;
		system("cls"); //Очистка терминала
		if (answer == 1) { //Если пользователь подтвердил удаление				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(35);
			cout << "Студент был успешно удалён!" << endl;
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
		system("mode con cols=40 lines=7"); //Устанавливает размер окна

		string nik, password;

		if (people.empty()) { //Если список пуст
			system("mode con cols=35 lines=4"); //Устанавливает размер окна]

			line(35);
			cout << "Список пользователей пуст!" << endl;
			line(35);
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
				if (password == p.getPassword())
					user_menu();
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
	}
}
//----------------------------------------------------------------------------------------------------------------