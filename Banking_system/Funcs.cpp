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
	SetConsoleTextAttribute(color, 3); //Установка цвета в консоли: 3 (синий)
	for (int i = 0; i < a; i++)
		cout << "~";
	cout << endl;
	SetConsoleTextAttribute(color, 7); //Установка цвета в консоли: 7 (белый)
}

void thereIsNoSuchTipeOfAnswer() {
	line(70);
	cout << "Такого ответа нет!" << endl;
	cout << "Проверьте и попробуйте ещё раз" << endl;
	line(70);
	Sleep(3000);  //Задержка 3 секунды
	system("cls");//Очистка терминала
}
//----------------------------------------------------------------------------------------------------------------
void fileForRead() {
	ifstream fin;
	string pathToPeople = "People.txt";

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
}

void startMenu() {
	for (;;) {
		int choice;

		line(70);
		cout << "1 - Войти как администратор" << endl;
		cout << "2 - Войти как пользователь" << endl;
		cout << "0 - Выйти" << endl;
		line(70);
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

			line(70);
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

	//Затирка данных, которые касаются счетов пользователя
	for (auto& p : people) {
		p.personAccs.clear();
		p.count = 0;
	}

	//Открытие файла в котором хранятся пользователи, для затирки данных
	fout.open(pathToPeople, ofstream::trunc);
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
}
//----------------------------------------------------------------------------------------------------------------
void admin_passwordCheck() {
	string password;

	line(70);
	cout << "Введите пароль: ";
	cin >> password;
	
	system("cls");

	if (password == "Password123")
		admin_menu();
	else {
		line(70);
		cout << "Пароль не правильный!" << endl;
		cout << "Доступ запрещён!" << endl;
		line(70);
		Sleep(3000);
		system("cls");
	}
}

void admin_menu() {
	for (;;) {
		int answer;

		int a = 0; //Счётчик для нумерации
		//Перебор вектора и присваивание номеров пользователям
		for (auto& temp : people) {
			temp.number = a + 1;

			a++;
		}

		line(70);
		cout << "1 - Список пользователей" << endl;
		cout << "2 - Удалить пользователя" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
		int answer;

		if (people.empty()) { //Если список пуст
			line(70);
			cout << "Список пользователей пуст!" << endl;
			line(70);
			Sleep(2500);   //Задержка в 2 секунды
			system("cls"); //Очистка терминала

			break;
		}

		line(70);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка всех пользователей
		for (auto& temp : people) {
			temp.number = a + 1;  //Присваивания пользователям номера
			cout << temp << endl; //Вывод номера, имени и фамилии пользователя

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "1 - Посмотреть детальную информацию" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");

		if (answer == 1) {
			int who;

			line(70);
			a = 0; //Счётчик для нумерации
			//Перебор массива и вывод списка всех пользователей
			for (auto& temp : people) {
				temp.number = a + 1;  //Присваивания пользователям номера
				cout << temp << endl; //Вывод номера, имени и фамилии пользователя

				a++; //Увиличение счётчика нумерации
			}
			line(70);
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
		int answer;
		//Проверка на правильность ввода номерва пользователя
		if (aboutWho < 1 || aboutWho > people.size()) {
			line(70);
			cout << "Вы ввели неправильный номер!" << endl;
			cout << "Проверьте и попробуйте ещё раз!" << endl;
			line(70);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		//Цикл для поиска нужного пользователя
		for (auto& p : people) {
			if (aboutWho == p.number) {
				line(70);
				p.personInfo();
			}
		}
		line(70);
		cout << "1 - Посмотреть информацию по счетам" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
		int answer;

		if (person.personAccs.empty()) {
			line(70);
			cout << "У этого пользователя ещё нет счетов!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(70);
		int a = 0; //Счётчик для нумерации
		//Перебор вектора и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт, про который\nхотите посмотреть информацию: ";
		cin >> aboutWhich;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		bankAcc = BankAccount();
		//Перебор вектора и поиск нужного счета
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich) {
				temp.bankAccountInfo();
				bankAcc = temp;
			}
		}
		line(70);
		cout << "1 - Посмотреть транзакции счёта" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");//Очистка терминал

		if (answer == 1)
			user_infoAboutTransaction();
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
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка всех пользователей
		for (auto& temp : people) {
			temp.number = a + 1;  //Присваивания пользователям номера
			cout << temp << endl; //Вывод номера, имени и фамилии пользователя

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Введите номер кого нужно удалить: ";
		cin >> whoDelete;
		system("cls"); //Очистка терминала
		//Проверка на правильность ввода номерва пользователя
		if (whoDelete < 1 || whoDelete > people.size()) {
			line(70);
			cout << "Вы ввели неправильный номер!" << endl;
			cout << "Проверьте и попробуйте ещё раз!" << endl;
			line(70);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(70);
		cout << "Вы действительно хотите удалить этого пользователя?\n(1 - да, 0 - нет)" << endl;
		line(70);
		cout << "Ваш ответ: ";
		cin >> answer;
		system("cls"); //Очистка терминала
		if (answer == 1) { //Если пользователь подтвердил удаление				
			index = whoDelete - 1;
			people.erase(people.begin() + index);

			line(70);
			cout << "Пользователь был успешно удалён!" << endl;
			line(70);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		else if (answer == 0) { //Если пользователь отменил удаление
			line(70);
			cout << "Операция отменена!" << endl;
			line(70);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		else { //Если пользователь ввёл неправильное число
			line(70);
			cout << "Такого ответа нету!\nОперация отменена!" << endl;
			line(70);
			Sleep(2000);  //Задержка в 2 секунды
			system("cls");//Очистка терминала
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------
bool addCheck = true; //Переменная для проверки добавлять ли пользователя в общий список
int selection;        //Переменая для проверки новый ли пользователь или уже существующий
string Nik;           //Переменая для входа и проверки для обновления данных

void user_accSelection() {
	for (;;) {
		addCheck = true;

		int a = 0; //Счётчик для нумерации
		//Перебор вектора и присваивание номеров пользователям
		for (auto& temp : people) {
			temp.number = a + 1;

			a++;
		}

		line(70);
		cout << "1 - Существующий пользователь" << endl;
		cout << "2 - Новый пользователь" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
		cout << "Ваш выбор: ";
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
	int check = 0; //Счётчик для количества попыток ввода пароля

	for (;;) {
		string password;
		bool checkNik = false;

		if (people.empty()) { //Если список пуст
			line(70);
			cout << "Список пользователей пуст!" << endl;
			line(70);
			Sleep(2500);   //Задержка в 2.5 секунды
			system("cls"); //Очистка терминала

			break;
		}

		if (check == 3) {
			line(70);
			cout << "Вы уже использовали слишком\nмного попыток на вход!" << endl;
			line(70);
			Sleep(3000);  //Задержка в 3 секунды
			system("cls");//Очистка терминала
			break;
		}
		
		line(70);
		cout << "Введите никнейм пользователя:" << endl;;
		cin >> Nik;
		//Перебор вектора и проверка на существование такого ника
		for (auto& temp : people) {
			if (Nik == temp.getNik())
				checkNik = true;
		}
		//Если пользователя с таким ником нет
		if (checkNik == false) {
			line(70);
			cout << "Пользователя с таким\nникнеймом не существует!" << endl;
			line(70);
			check++;      //Увеличение счётчика
			Sleep(3000);  //Задержка в 3 секунды
			system("cls");//Очистка терминала
			break;
		}

		cout << "Введите пароль пользователя:" << endl;
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
					cout << "Пароль не верный!" << endl;
					line(70);
					check++;      //Увеличение счётчика
					Sleep(3000);  //Задержка в 3 секунды
					system("cls");//Очистка терминала
				}
			}
		}

		break;
	}
}

void user_newAcc() {
	person = Person();  //Затирка возможных данных от прошлых изменений

	line(70);
	person.enterName();
	person.enterSurname();
	person.enterPatronymic();
	person.enterAge();
	system("cls"); //Очистка терминала
	line(70);
	person.enterNik();
	//Проверка на совпадение никнейма
	for (auto& temp : people) {
		if (temp.getNik() == person.getNik()) {
			line(70);
			cout << "Пользователь с таким никнеймом\nуже существует!" << endl;
			line(70);
			Sleep(3000);  //Задержка в 3 секунды
			system("cls");//Очистка терминала
			line(70);
			person.enterNik();
		}
	}
	person.enterPassword();

	system("cls"); //Очистка терминала

	user_menu();
}

void user_menu() {
	for (;;) {
		int answer;

		if (!addCheck) 
			break;

		int a = 0; //Счётчик для нумерации
		//Перебор массива и присваивание номера пользователю
		for (auto& temp : people) {
			temp.number = a + 1;  //Присваивания пользователям номера

			a++; //Увиличение счётчика нумерации
		}

		line(70);
		cout << "1 - Личный кабинет" << endl;
		cout << "2 - Добавить счёт" << endl;
		cout << "3 - Удалить счёт" << endl;
		cout << "4 - Перевести деньги" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
			//Если вход был нового пользователя
			if (selection == 2 && addCheck) {
				//Добавление пользователя в общий список
				people.push_back(person);
				//Добавление счетов пользователя в общий список
				for (auto& temp : person.personAccs) {
					accounts.push_back(temp);
				}
			}
			//Если вход был существующего пользователя
			if (selection == 1 && addCheck) {
				//Цикл для перебора вектора пользователей
				for (auto& p : people) {
					//Если совпадение по нику - обновление данных про пользователя
					if (Nik == p.nik) {
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
		cout << "1 - Посмотреть персональную информацию" << endl;
		cout << "2 - Посмотреть информацию по счетам" << endl;
		cout << "3 - Удалить этот личный кабинет" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
		int answer;

		line(70);
		person.personInfo();
		line(70);
		cout << "1 - Изменить персональную информацию" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
	int answer;

	line(70);
	cout << "Что вы хотите поменять?" << endl;
	line(70);
	cout << "1 - Имя" << endl;
	cout << "2 - Фамилия" << endl;
	cout << "3 - Отчество" << endl;
	cout << "4 - Возраст" << endl;
	cout << "5 - Никнейм" << endl;
	cout << "6 - Пароль" << endl;
	line(70);
	cout << "Ваш выбор: ";
	cin >> answer;
	system("cls"); //Очистка терминала 
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
	system("cls"); //Очистка терминала 
}

void user_infoAboutBankAccount() {
	for (;;) {
		int answer, aboutWhich;

		if (person.personAccs.empty()) {
			line(70);
			cout << "У вас ещё нет счетов!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(70);
		int a = 0; //Счётчик для нумерации
		//Перебор вектора и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт, про который\nхотите посмотреть информацию: ";
		cin >> aboutWhich;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (aboutWhich < 1 || aboutWhich > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		bankAcc = BankAccount();
		//Перебор вектора и поиск нужного счета
		for (auto& temp : person.personAccs) {
			if (temp.number == aboutWhich) {
				temp.bankAccountInfo();
				bankAcc = temp;
			}
		}
		line(70);
		cout << "1 - Изменить информацию" << endl;
		cout << "2 - Посмотреть транзакции счёта" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
		cout << "Ваш выбор: ";
		cin >> answer;

		system("cls");//Очистка терминал

		if (answer == 1) {
			user_chengeInfoAboutBankAccount(aboutWhich);
			break;
		}
		else if (answer == 2) {
			if (bankAcc.transactions1.empty() && bankAcc.transactions2.empty()) {
				line(70);
				cout << "Список транзакций у этого счёта пуст!" << endl;
				line(70);
				Sleep(3000);  //Задержка 3 секунды
				system("cls");//Очистка терминала
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
		cout << "1 - Транзакции между своими счетами" << endl;
		cout << "2 - Транзакции между другими счетами" << endl;
		line(70);
		cout << "Ваш выбор: ";
		cin >> choise;
		system("cls"); //Очистка терминала

		if (choise == 1) {
			//Если список ещё пустой
			if (bankAcc.transactions1.empty()) {
				line(70);
				cout << "Список транзакциий между персональными счетами пуст!" << endl;
				line(70);
				Sleep(3000);  //Задержка 3 секунды
				system("cls");//Очистка терминала
				break;
			}

			line(70);
			int a = 0; //Счётчик для нумерации
			//Перебор вектора и вывод списка транзакций
			for (auto& temp : bankAcc.transactions1) {
				temp.number = a + 1;  //Присваивание транзакции номера
				cout << temp << endl; //Вывод название транзакции

				a++; //Увиличение счётчика нумерации
			}
			line(70);
			cout << "Выберите номер транзакции\nпро которую хотите увидеть информацию: ";
			cin >> answer;
			system("cls"); //Очистка терминала

			//Проверка на правильность номера
			if (answer < 1 || answer > bankAcc.transactions1.size()) {
				thereIsNoSuchTipeOfAnswer();
				break;
			}

			line(70);
			for (auto& temp : bankAcc.transactions1) {
				//Поиск нужной транзакции
				if (temp.number == answer)
					temp.printInfo1();
			}
		}
		else if (choise == 2) {
			//Если список ещё пустой
			if (bankAcc.transactions2.empty()) {
				line(70);
				cout << "Список транзакциий между счетами других пользователей пуст!" << endl;
				line(70);
				Sleep(3000);  //Задержка 3 секунды
				system("cls");//Очистка терминала
				break;
			}

			line(70);
			int a = 0; //Счётчик для нумерации
			//Перебор вектора и вывод списка транзакций
			for (auto& temp : bankAcc.transactions2) {
				temp.number = a + 1;  //Присваивание транзакции номера
				cout << temp << endl; //Вывод название транзакции

				a++; //Увиличение счётчика нумерации
			}
			line(70);
			cout << "Выберите номер транзакции\nпро которую хотите увидеть информацию: ";
			cin >> answer;
			system("cls"); //Очистка терминала

			//Проверка на правильность номера
			if (answer < 1 || answer > bankAcc.transactions2.size()) {
				thereIsNoSuchTipeOfAnswer();
				break;
			}

			line(70);
			for (auto& temp : bankAcc.transactions2) {
				//Поиск нужной транзакции
				if (temp.number == answer)
					temp.printInfo2();
			}
		}
		else {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		cout << "0 - Вернуться назад" << endl;
		line(70);
		cout << "Ваш выбор: ";
		cin >> answer;
		system("cls"); //Очистка терминала

		if (answer == 0)
			break;
		else {
			thereIsNoSuchTipeOfAnswer();
			line(70);
			cout << "\t\t\tВозврат назад!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}
	}
}

void user_chengeInfoAboutBankAccount(int aboutWhich) {
	int answer;

	line(70);
	cout << "Что вы хотите поменять?" << endl;
	line(70);
	cout << "1 - Номер счёта" << endl;
	cout << "2 - id счёта" << endl;
	cout << "3 - Назначение счёта" << endl;
	cout << "4 - Пароль счёта" << endl;
	line(70);
	cout << "Ваш выбор: ";
	cin >> answer;
	system("cls"); //Очистка терминала
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

	//Перебор вектора и поиск нужного счета в общем списке счетов
	for (auto temp : person.personAccs) {
		if (temp.number == aboutWhich) {
			int index = aboutWhich - 1;
			auto iter = person.personAccs.begin() + index;
			person.personAccs.erase(iter);

			person.personAccs.push_back(bankAcc);
		}
	}

	Sleep(2000);   //Задержка 2 секунды
	system("cls"); //Очистка терминала
}

void user_delPrivateOffice() {
	int answer;

	line(70);
	cout << "Вы действительно хотите удалить этот аккаунт?\n(1 - да, 0 - нет)" << endl;
	line(70);
	cout << "Ваш ответ: ";
	cin >> answer;
	system("cls"); //Очистка терминала

	if (answer == 1) { //Если пользователь подтвердил удаление
		line(70);
		cout << "Пользователь был успешно удалён!" << endl;
		line(70);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
		addCheck = false;
	}
	else if (answer == 0) { //Если пользователь отменил удаление
		line(70);
		cout << "Операция отменена!" << endl;
		line(70);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
	}
	else { //Если пользователь ввёл неправильное число
		line(70);
		cout << "Такого ответа нету!\nОперация отменена!" << endl;
		line(70);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
	}
}

void user_addBankAccount() {
	if (person.count == 3) {
		line(70);
		cout << "У вас уже есть 3 счета, это максимальное количество счетов!" << endl;
		line(70);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала
	}
	else {
		person.count++; //Увеличиваем счётчик количества счетов пользователя
		line(70);
		bankAcc.owner = person.surname + " " + person.name + " " + person.patronymic;
		bankAcc.enterPurpose();
		bankAcc.enterMoney();
		bankAcc.enterPassword();
		bankAcc.idGeneration();
		bankAcc.numberGeneration();
		line(70);
		Sleep(2000);  //Задержка 2 секунды
		system("cls");//Очистка терминала

		person.personAccs.push_back(bankAcc);//Добавление счёта в список счетов пользователя
		accounts.push_back(bankAcc);         //Добавление счёта в список счтеов
	}
}

void user_delBankAccount() {
	for (;;) {
		int whoDelete, answer;

		if (person.personAccs.empty()) {
			line(70);
			cout << "У вас ещё нет счетов!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(70);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт, который хотите удалить: ";
		cin >> whoDelete;
		system("cls");//Очистка терминал
		//Проверка на правильность ввода номерва счета
		if (whoDelete < 1 || whoDelete > person.personAccs.size()) {
			thereIsNoSuchTipeOfAnswer();
			break;
		}
		line(70);
		cout << "Вы действительно хотите удалить этот счёт?\n(1 - да, 0 - нет)" << endl;
		line(70);
		cout << "Ваш ответ: ";
		cin >> answer;
		system("cls"); //Очистка терминала
		if (answer == 1) { //Если пользователь подтвердил удаление
			person.count--; //Уменшаем счётчик количества счетов пользователя
			
			int index = whoDelete - 1;
			auto iter = person.personAccs.begin() + index;

			person.personAccs.erase(iter); //Удаление счёта из списка счетов пользователя

			line(70);
			cout << "Этот счёт был успешно удалён!" << endl;
			line(70);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
		else if (answer == 0) { //Если пользователь отменил удаление
			system("mode con cols=20 lines=4"); //Устанавливает размер окна

			line(70);
			cout << "Операция отменена!" << endl;
			line(70);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
		else { //Если пользователь ввёл неправильное число
			system("mode con cols=20 lines=4"); //Устанавливает размер окна

			line(70);
			cout << "Такого ответа нету!\nОперация отменена!" << endl;
			line(70);

			Sleep(2000);   //Задержка 2 секунды
			system("cls"); //Очистка терминала
			break;
		}
	}
}

void user_sendMoney() {
	for (;;) {
		int answer;

		if (person.personAccs.empty()) {
			line(70);
			cout << "У вас ещё нет счетов!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(70);
		cout << "1 - Перевести деньги на свой счёт" << endl;
		cout << "2 - Перевести деньги на счёт другого пользователя" << endl;
		cout << "0 - Вернуться назад" << endl;
		line(70);
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
		int firstAcc, secondAcc;
		double sum;
		bool checkMoney = true;

		if (person.personAccs.size() == 1) {
			line(70);
			cout << "У вас ещё нет другого счёта!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(70);
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт с которого хотите перевести деньги: ";
		cin >> firstAcc;
		system("cls");//Очистка терминал

		line(70);
		a = 0; //Онуляем счётчик
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт на который хотите перевести деньги: ";
		cin >> secondAcc;
		system("cls");//Очистка терминал

		if (firstAcc == secondAcc) {
			line(70);
			cout << "Ошибка! Операция отменена!" << endl;
			cout << "Вы выбрали два одинаковых счёта!" << endl;
			line(70);
			Sleep(5000);  //Задержка 5 секунды
			system("cls");//Очистка терминала
			break;
		}
		line(70);
		cout << "Введите сумму перевода: ";
		cin >> sum;
		system("cls");//Очистка терминал
		//Цикл для перебора вектора счетов пользователя
		for (auto& temp : person.personAccs) {
			//Проверка на наличие суммы, указаной выше
			if (temp.number == firstAcc) {
				if (sum > temp.money) {
					checkMoney = false;
					line(70);
					cout << "Ошибка! Операция отменена!" << endl;
					cout << "Сумма, которую вы ввели, превышает сумму, которая есть на вашем счету!" << endl;
					line(70);
					Sleep(5000);  //Задержка 5 секунд
					system("cls");//Очистка терминала
					break;
				}
			}
			//Поиск счетов с которого переводить и на который переводить
			if (temp.number == firstAcc || temp.number == secondAcc) {
				if (temp.number == firstAcc) { //Первый счёт
					temp.money -= sum;

					payment.firstAcc = temp.purpose;
					payment.money = sum;
					line(70);
					payment.enterPaymentName();
				}
				else { //Второй счёт
					temp.money += sum;

					payment.secondAcc = temp.purpose;
				}
			}
		}
		//Сохранение платежей на два счёта
		for (auto& temp : person.personAccs) {
			if (temp.number == firstAcc || temp.number == secondAcc)
				temp.transactions1.push_back(payment);
		}

		if (checkMoney == false)
			break;
		else {
			line(70);
			cout << "Сумма успешно отправлена!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминал
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
		int a = 0; //Счётчик для нумерации
		//Перебор массива и вывод списка счетов
		for (auto& temp : person.personAccs) {
			temp.number = a + 1;  //Присваивание счету номера
			cout << temp << endl; //Вывод номера счета и назначения

			a++; //Увиличение счётчика нумерации
		}
		line(70);
		cout << "Выберите счёт с которого хотите перевести деньги: ";
		cin >> firstAcc;
		system("cls");//Очистка терминал

		line(70);
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
			line(70);
			cout << "Ошибка! Операция отменена!" << endl;
			cout << "Счёта с таким номером нет!" << endl;
			line(70);
			Sleep(3000);  //Задержка 3 секунды
			system("cls");//Очистка терминала
			break;
		}

		line(70);
		cout << "Введите сумму перевода: ";
		cin >> sum;
		system("cls");//Очистка терминал
		//Цикл для перебора вектора счетов пользователя
		for (auto& temp : person.personAccs) {
			//Проверка на наличие суммы, указаной выше
			if (temp.number == firstAcc)
				if (sum > temp.money) {
					checkMoney = false;
					line(70);
					cout << "Ошибка! Операция отменена!" << endl;
					cout << "Сумма, которую вы ввели, привышает сумму, которая есть на вашем счету!" << endl;
					line(70);
					Sleep(3000);  //Задержка 3 секунды
					system("cls");//Очистка терминала
					break;
				}
			//Поиск счёта с которого переводить
			if (temp.number == firstAcc) {
				temp.money -= sum;

				payment.sender = temp.owner;
				payment.money = sum;
				line(70);
				payment.enterPaymentName();
			}
		}
		//Цикл для перебора вектора счетов
		for (auto& temp : accounts) {
			//Поиск счёта на который переводить
			if (temp.AccNumber == secondAcc) {
				temp.money += sum;

				payment.recipient = temp.owner;
			}
		}
		//Добавление платежа в первый счёт
		for (auto& temp : person.personAccs) {
			if (temp.number == firstAcc)
				temp.transactions2.push_back(payment);
		}
		//Добавление платежа во втоорой счёт
		for (auto& temp : accounts) {
			if (temp.AccNumber == secondAcc)
				temp.transactions2.push_back(payment);
		}

		if (checkMoney == false)
			break;
		else {
			line(70);
			cout << "Сумма успешно отправлена!" << endl;
			line(70);
			Sleep(2000);  //Задержка 2 секунды
			system("cls");//Очистка терминал
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------------