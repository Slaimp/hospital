#define NOMINMAX
#include "Header.h"
using namespace std;
const string vrachPATH = "doctors.txt";
const string pathirntPATH = "Pathient.txt";
void file();
void menu1();
void menu2();
void menuAdmin();
void provekapassword(string& password);
void menuNach();
void menuRega();
void menuRegaPathient();
void menuRegaAdmin();
void menuAftoriz();
void menuAftorizPathient();
void menuAftorizAdmin();
void menusort();
void menuadmina1();
void menuSortPathient();
void SortPathientCity();
void SortPathientdiagnose();
void BlockPathientov();
void TablPathientov();
void RazblockPathientov();
void MenuUser();
int CreateInt();
void addVrach();
void addpathient();
void printVrach();
void printpathient();
int proverkanomera();
void SortPathient();
int getCountOfRecordsInFile(const string filePATH);
vector <vrach>vrachArr;
vector<pathient> pathientArr;
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	file();
	int chislo;
	menuNach();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuNach();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		menu1();
		break;
	}
	case 2: {
		system("cls");
		menu2();
		break;
	}

	case 3: {
		system("cls");
		cout << "Благодарим за использовние!" << endl;
		exit(0);
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		main();
		break;
	}
	}
}
void menuNach() {
	cout << "\t\t\tМеню" << endl;
	cout << "1. Регистрация " << endl;
	cout << "2. Авторизация " << endl;
	cout << "3. Выход из приложения" << endl;
	cout << "Ваш выбор: ";
}
void menuRega() {
	cout << "1. Зарегестрироваться пользователем" << endl;
	cout << "2. Зарегестрироваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void menuAftoriz() {
	cout << "1. Авторизоваться пользователем" << endl;
	cout << "2. Авторизоваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}

void menuadmina1() {
	cout << "1. Вывести всех пользователей в таблицу" << endl;
	cout << "2. Заблокировать пользователя" << endl;
	cout << "3. Разблокировать пацинента" << endl;
	cout << "4. Заполнить данные о враче" << endl;
	cout << "5. Вывести таблицу врачей" << endl;
	cout << "6. Заполнить данные о пацинте" << endl;
	cout << "7. Просмотреть таблицу пациентов" << endl;
	cout << "8. Отсортировать пациентов по параметру" << endl;
}
void menusort() {
	cout << "1. Сортировать пациентов по коду" << endl;
	cout << "2. Сортировать по диагнозу" << endl;
	cout << "3. Сортировать по городу" << endl;
}
void menu1() {

	int chislo;
	menuRega();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuRega();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuRegaPathient();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuRegaAdmin();
		break;
	}
	case 3: {
		system("cls");
		main();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu1();
		break;
	}
	}
}
void menu2() {

	int chislo;
	menuAftoriz();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuAftoriz();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuAftorizPathient();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuAftorizAdmin();
		break;
	}
	case 3: {
		system("cls");
		main();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu1();
		break;
	}
	}
}

void menuRegaPathient() {

	int ind = 0;
	string user, password, userproverka, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		menuRegaPathient();
	}
	else {
		ifstream filepol("userlogpass.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует, введите другой никнейм" << endl;
				menuRegaPathient();
			}
		}
		filepol.close();
		provekapassword(password);

		status = "g";
		ofstream filepolz("userlogpass.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно " << endl;
		main();

	}
}

void provekapassword(string& password) {
	cout << "Введите пароль: ";
	getline(cin, password);
	if (password.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		provekapassword(password);
	}
}

void menuRegaAdmin() {

	int ind = 0;
	string user, password, userproverka, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		menuRegaAdmin();
	}
	else {
		ifstream filepol("userlogadmin.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует" << endl;
				menuRegaAdmin();
			}
		}
		filepol.close();
		provekapassword(password);

		status = "g";
		ofstream filepolz("userlogadmin.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно" << endl;
		main();

	}
}
void menuAftorizPathient() {
	int ind = 0, number = 0;
	string user, password, USer, PASSword, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 1;

	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		menuAftorizPathient();
	}
	else {
		provekapassword(password);
		ifstream fileavt("userlogpass.txt");
		while (!fileavt.eof()) {
			fileavt >> USer >> PASSword >> status;
			if (user == USer && PASSword == password) {
				ind = 1;
				break;
			}
		}
		fileavt.close();
	}
	if (status == "block") {
		system("cls");
		cout << "Вы в русской бане (" << endl;
		main();
	}
	if (ind == 1) {
		system("cls");

		cout << "Добро пожаловать!" << endl;
		MenuUser();
	}
	else {
		system("cls");
		cout << "Данные введены не верно " << endl;
		menuAftorizPathient();
	}

}
void menuAftorizAdmin() {

	int ind = 0, number = 0;
	string user, password, USer, PASSword, status;
	cout << "Введите имя администратора: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 2;

	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Проебелы запрещены\n";
		menuAftorizAdmin();
	}
	else {
		provekapassword(password);
		ifstream fileavt("userlogadmin.txt");
		while (fileavt >> USer >> PASSword >> status) {
			if (user == USer && PASSword == password) {
				ind = 1;
				break;
			}
		}
		fileavt.close();
	}
	if (ind == 1) {
		system("cls");
		cout << "Добро пожаловать!" << endl;
		menuAdmin();
	}
	else {
		system("cls");
		cout << "Данные введены не верно " << endl;
		menuAftorizAdmin();
	}


}

void menuAdmin() {
	setlocale(LC_ALL, "rus");
	int chislo;
	menuadmina1();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuadmina1();
		}
	}
	switch (chislo) {
	case 1: {
		TablPathientov();
		menuAdmin();
		break;
	}
	case 2: {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		BlockPathientov();
		menuAdmin();
		break;
	}
	case 3:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		RazblockPathientov();
		break;
	case 4:
		addVrach();

		break;
	case 5:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printVrach();
		break;
	case 6:
		addpathient();
		break;
	case 7:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printpathient();
		break;
	case 8:
		menuSortPathient();

		break;
		system("cls");
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menuAdmin();
		break;
	}
	}
}


void BlockPathientov() {
	system("cls");
	string login, pass, status, blocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	TablPathientov();
	cout << "Введите логин пользователя, которого нужно заблокировать: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		BlockPathientov();
	}
	else {
		while (fin >> login >> pass >> status) {
			if (status == "block" && login == blocklogin) {
				system("cls");
				cout << "Этот пользователь уже был заблокирован" << endl;
				remove("temp.txt");
				menuAdmin();
			}
			if (login == blocklogin) {
				userfound = 1;
				status = "block";
			}
			fout << login << " " << pass << " " << status << endl;
		}
		fin.close();
		fout.close();
		if (userfound == 1) {
			remove("userlogpass.txt");
			rename("temp.txt", "userlogpass.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " заблокирован" << endl;
			menuAdmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " не найден" << endl;
			menuAdmin();
		}
	}
}
void TablPathientov() {
	system("cls");
	string login, pass, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  Таблица  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status) {
		cout << i << " Имя пользователя: " << login;
		if (status == "g")
			cout << "   Активен" << endl;
		else cout << "   Заблокирован" << endl;
		i++;
	}
	cout << "-----------------------------------------------------------\n\n";
	tablica.close();
}
void RazblockPathientov() {
	system("cls");
	string login, pass, status, blocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	TablPathientov();
	cout << "Введите логин пользователя, которого нужно разблокировать: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		system("cls");
		cout << "Пробелы запрещены\n";
		BlockPathientov();
	}
	else {
		while (fin >> login >> pass >> status) {
			if (status == "g" && login == blocklogin) {
				system("cls");
				cout << "Этот пользователь уже был разблокирован" << endl;
				remove("temp.txt");
				menuAdmin();
			}
			if (login == blocklogin) {
				userfound = 1;
				status = "g";
			}
			fout << login << " " << pass << " " << status << endl;
		}
		fin.close();
		fout.close();
		if (userfound == 1) {
			remove("userlogpass.txt");
			rename("temp.txt", "userlogpass.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " разблокирован" << endl;
			menuAdmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " не найден" << endl;
			menuAdmin();
		}
	}
}
void MenuUser()
{
	int choice = 1;
	while (1)
	{
		system("cls");
		cout << "Выберите желаемое действие" << endl;
		cout << "1.Поставить рейтинг врачу" << endl;
		cout << "2.Просмотреть всех врачей" << endl;
		cout << "3.Сортировка данных" << endl;
		cout << "4.Поиск данных" << endl;
		cout << "5.Заполнить талон" << endl;
		cout << "6.Выход" << endl;
		int choice = CreateInt();
		switch (choice)
		{
		case 1:
		{
			system("cls");

			break;
		}
		case 2:
		{
			printVrach();
			system("pause");
			system("cls");

			break;
		}
		case 3:
		{
			system("cls");

			break;
		}
		case 4:
		{

		}
		case 5:
		{
			choice--;
			break;
		}
		default:
			cout << "Ошибка ввода" << endl;
		}
	}
}
int CreateInt()
{
	int correct = 0;
	string str;
	while (!correct)
	{
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] < '0' || str[i]>'9')
			{
				correct = 0;
				if (!correct)
				{
					cout << "Вводите только цифры!\n";
				}
				break;
			}
			correct = 1;
		}
	}
	return stoi(str);
}
void addVrach()
{
	int kod;
	int kabinet;
	string FIO;
	string cpecilizacia;



	getchar();
	cout << "Введите код врача" << endl;

	cin >> kod;

	cout << "Введите кабинет врача" << endl;

	cin >> kabinet;

	cout << "Введите ФИО врача " << endl;

	getline(cin >> ws, FIO);

	cout << "Введите специлизацию врача " << endl;

	getline(cin >> ws, cpecilizacia);

	vrachArr.push_back({ kod, kabinet, FIO, cpecilizacia });

	ofstream filepolz("doctors.txt", ios::app);
	filepolz << kod << ' ' << kabinet << ' ' << FIO << endl << cpecilizacia << ' ' << endl;
	filepolz.close();
	cout << "Врач занесен в систему" << endl;
	filepolz.close();
	system("pause");
	menuAdmin();
}
void printVrach()
{
	ifstream fin(vrachPATH);
	int i = 0;
	vrachArr.clear();
	vrach doctor;

	while (fin >> doctor.kod)
	{
		fin >> doctor.kabinet;
		getline(fin, doctor.FIO);
		getline(fin, doctor.cpecilizacia);
		cout << doctor.kod << ' ' << doctor.kabinet << ' ' << doctor.FIO << ' ' << doctor.cpecilizacia << endl;
		vrachArr.push_back(doctor);
		i++;
	}
	system("cls");
	fin.close();
	{
		int length = 80;
		cout << " " << setfill('_') << setw(length - 2) << "" << setfill(' ') << " " << endl;
		cout << "| " << setiosflags(ios::left) << setw(3) << "Код" << " |" << setw(9) << "Кабинет" << " |" << setw(29) << "ФИО" << " |" << setw(29) << "Специализация" << " |" << endl;
		cout << "|" << setfill('=') << setw(length - 2) << "" << setfill(' ') << "|" << endl;

		for (int i = 0; i < vrachArr.size(); i++) {
			cout << "|" << setw(4) << vrachArr[i].kod << " |" << setw(9) << vrachArr[i].kabinet << " |" << setw(29) << vrachArr[i].FIO << " |" << setw(29) << vrachArr[i].cpecilizacia << " |" << endl;
			cout << "|" << setfill('-') << setw(length - 2) << "" << setfill(' ') << "|" << endl;
		}

		

	}
}

int getCountOfRecordsInFile(const string filePATH)
{
	ifstream file(filePATH);

	int numberOfRecords = 0;

	if (file.is_open())
	{
		string buffer;
		while (getline(file, buffer))
		{
			numberOfRecords++;
		}
	}

	file.close();
	return numberOfRecords;
}

void addpathient()
{
	int kod;
	string FIO;
	int age;
	string city;
	int telephone;
	string diagnose;
	getchar();
	cout << "Введите код пациента" << endl;

	cin >> kod;

	cout << "Введите ФИО пациента " << endl;

	getline(cin >> ws, FIO);

	cout << "Введите кол-во полных лет пациента" << endl;

	cin >> age;

	cout << "Введите город проживания пациента " << endl;

	getline(cin >> ws, city);

	cout << "Введите телефон пациента" << endl;

	cin >> telephone;
	proverkanomera();

	cout << "Введите диагноз пациета " << endl;

	getline(cin >> ws, diagnose);

	pathientArr.push_back({ kod, FIO, age, city, telephone, diagnose });

	ofstream filepolz("Pathient.txt", ios::app);
	filepolz << kod << ' ' << FIO << endl << age << ' ' << city << endl << telephone << ' ' << diagnose << endl;
	filepolz.close();
	cout << "Пациент занесен в систему" << endl;
	filepolz.close();
	system("pause");
	menuAdmin();
}
int proverkanomera()
{
	char str[10];
	int telephone;
	bool correct = false;
	cout << "Введите телефонный номер: ";

	while (!correct)
	{
		cout << "+375";
		cin >> str;
		if (strlen(str) != 9)
		{
			cout << "Неверное количество цифр!" << endl;
		}
		else
		{
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "Неверный формат! Введите только цифры." << endl;
					break;
				}
				else
				{
					correct = true;
				}
			}
		}
	}
	cout << "Вы ввели номер: +375" << str << endl;
	return 0;
}
void file()
{
	ifstream fin(pathirntPATH);
	int i = 0;
	pathientArr.clear();
	pathient pathient;

	while (fin >> pathient.kod)
	{

		getline(fin, pathient.FIO);
		fin >> pathient.age;
		getline(fin, pathient.city);
		fin >> pathient.telephone;
		getline(fin, pathient.diagnose);
		pathientArr.push_back(pathient);
	}
	fin.close();
}
void printpathient()
{
		int length = 100;
		cout << ' ' << setfill('_') << setw(length - 2) << "" << setfill(' ') <<   endl;
		cout << "| " << setiosflags(ios::left) << setw(10) << "Код"
			<< " | " << setw(26) << "ФИО"
			<< " | " << setw(9) << "Возраст"
			<< " | " << setw(9) << "Город"
			<< " | " << setw(15) << "Телефон"
			<< " | " << setw(12) << "Диагноз" << " |" << endl;
		for (int i = 0; i < pathientArr.size(); i++)
		{
			cout << "|" << setfill('=') << setw(length - 2) << "" << setfill(' ') << "|" << endl;
			cout << "|" << setw(11) << pathientArr[i].kod << " |"
				<< setw(27) << pathientArr[i].FIO << " |"
				<< setw(10) << pathientArr[i].age << " |"
				<< setw(10) << pathientArr[i].city << " |"
				<< setw(16) << pathientArr[i].telephone << " |"
				<< setw(13) << pathientArr[i].diagnose << " |" << endl;
		}

		cout << "|" << setfill('_') << setw(length - 2) << "" << setfill(' ') << "|" << endl;
	
}
void SortPathient()
{
	for (int j = 0; j < pathientArr.size(); j++)
		for (int i = 0; i < pathientArr.size() - 1; i++)
			if (pathientArr[i].kod > pathientArr[i + 1].kod)
				swap(pathientArr[i], pathientArr[i + 1]);
}
void SortPathientCity()
{
	for (int j = 0; j < pathientArr.size(); j++)
		for (int i = 0; i < pathientArr.size() - 1; i++)
			if (pathientArr[i].city > pathientArr[i + 1].city)
				swap(pathientArr[i], pathientArr[i + 1]);
}
void SortPathientdiagnose()
{
	for (int j = 0; j < pathientArr.size(); j++)
		for (int i = 0; i < pathientArr.size() - 1; i++)
			if (pathientArr[i].diagnose > pathientArr[i + 1].diagnose)
				swap(pathientArr[i], pathientArr[i + 1]);
}
void menuSortPathient() {

	int chislo;
	system("cls");
	menusort();

	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuSortPathient();
		}
	}
	switch (chislo) {
	case 1: {
		SortPathient();
		menuAdmin();
		break;
	}
	case 2: {
	    SortPathientdiagnose();
		menuAdmin();
		break;
	}
	case 3: {
		SortPathientCity();
		menuAdmin();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu1();
		break;
	}
	}
}