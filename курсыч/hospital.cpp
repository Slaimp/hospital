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
			cout << "�������� ����. ���������." << endl;
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
		cout << "���������� �� ������������!" << endl;
		exit(0);
		break;
	}
	default: {
		system("cls");
		cout << "�������� ����. ���������." << endl;
		main();
		break;
	}
	}
}
void menuNach() {
	cout << "\t\t\t����" << endl;
	cout << "1. ����������� " << endl;
	cout << "2. ����������� " << endl;
	cout << "3. ����� �� ����������" << endl;
	cout << "��� �����: ";
}
void menuRega() {
	cout << "1. ������������������ �������������" << endl;
	cout << "2. ������������������ ���������������" << endl;
	cout << "3. ��������� � ����" << endl;
	cout << "��� �����: ";
}
void menuAftoriz() {
	cout << "1. �������������� �������������" << endl;
	cout << "2. �������������� ���������������" << endl;
	cout << "3. ��������� � ����" << endl;
	cout << "��� �����: ";
}

void menuadmina1() {
	cout << "1. ������� ���� ������������� � �������" << endl;
	cout << "2. ������������� ������������" << endl;
	cout << "3. �������������� ���������" << endl;
	cout << "4. ��������� ������ � �����" << endl;
	cout << "5. ������� ������� ������" << endl;
	cout << "6. ��������� ������ � �������" << endl;
	cout << "7. ����������� ������� ���������" << endl;
	cout << "8. ������������� ��������� �� ���������" << endl;
}
void menusort() {
	cout << "1. ����������� ��������� �� ����" << endl;
	cout << "2. ����������� �� ��������" << endl;
	cout << "3. ����������� �� ������" << endl;
}
void menu1() {

	int chislo;
	menuRega();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "�������� ����. ���������." << endl;
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
		cout << "�������� ����. ���������." << endl;
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
			cout << "�������� ����. ���������." << endl;
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
		cout << "�������� ����. ���������." << endl;
		menu1();
		break;
	}
	}
}

void menuRegaPathient() {

	int ind = 0;
	string user, password, userproverka, status;
	cout << "������� ��� ������������: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
		menuRegaPathient();
	}
	else {
		ifstream filepol("userlogpass.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "����� ������������ ����������, ������� ������ �������" << endl;
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
		cout << "����������� ������ ������� " << endl;
		main();

	}
}

void provekapassword(string& password) {
	cout << "������� ������: ";
	getline(cin, password);
	if (password.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
		provekapassword(password);
	}
}

void menuRegaAdmin() {

	int ind = 0;
	string user, password, userproverka, status;
	cout << "������� ��� ������������: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
		menuRegaAdmin();
	}
	else {
		ifstream filepol("userlogadmin.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "����� ������������ ����������" << endl;
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
		cout << "����������� ������ �������" << endl;
		main();

	}
}
void menuAftorizPathient() {
	int ind = 0, number = 0;
	string user, password, USer, PASSword, status;
	cout << "������� ��� ������������: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 1;

	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
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
		cout << "�� � ������� ���� (" << endl;
		main();
	}
	if (ind == 1) {
		system("cls");

		cout << "����� ����������!" << endl;
		MenuUser();
	}
	else {
		system("cls");
		cout << "������ ������� �� ����� " << endl;
		menuAftorizPathient();
	}

}
void menuAftorizAdmin() {

	int ind = 0, number = 0;
	string user, password, USer, PASSword, status;
	cout << "������� ��� ��������������: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 2;

	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "�������� ���������\n";
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
		cout << "����� ����������!" << endl;
		menuAdmin();
	}
	else {
		system("cls");
		cout << "������ ������� �� ����� " << endl;
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
			cout << "�������� ����. ���������." << endl;
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
		cout << "�������� ����. ���������." << endl;
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
	cout << "������� ����� ������������, �������� ����� �������������: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
		BlockPathientov();
	}
	else {
		while (fin >> login >> pass >> status) {
			if (status == "block" && login == blocklogin) {
				system("cls");
				cout << "���� ������������ ��� ��� ������������" << endl;
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
			cout << "������������ " << blocklogin << " ������������" << endl;
			menuAdmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "������������ " << blocklogin << " �� ������" << endl;
			menuAdmin();
		}
	}
}
void TablPathientov() {
	system("cls");
	string login, pass, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  �������  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status) {
		cout << i << " ��� ������������: " << login;
		if (status == "g")
			cout << "   �������" << endl;
		else cout << "   ������������" << endl;
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
	cout << "������� ����� ������������, �������� ����� ��������������: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		system("cls");
		cout << "������� ���������\n";
		BlockPathientov();
	}
	else {
		while (fin >> login >> pass >> status) {
			if (status == "g" && login == blocklogin) {
				system("cls");
				cout << "���� ������������ ��� ��� �������������" << endl;
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
			cout << "������������ " << blocklogin << " �������������" << endl;
			menuAdmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "������������ " << blocklogin << " �� ������" << endl;
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
		cout << "�������� �������� ��������" << endl;
		cout << "1.��������� ������� �����" << endl;
		cout << "2.����������� ���� ������" << endl;
		cout << "3.���������� ������" << endl;
		cout << "4.����� ������" << endl;
		cout << "5.��������� �����" << endl;
		cout << "6.�����" << endl;
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
			cout << "������ �����" << endl;
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
					cout << "������� ������ �����!\n";
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
	cout << "������� ��� �����" << endl;

	cin >> kod;

	cout << "������� ������� �����" << endl;

	cin >> kabinet;

	cout << "������� ��� ����� " << endl;

	getline(cin >> ws, FIO);

	cout << "������� ������������ ����� " << endl;

	getline(cin >> ws, cpecilizacia);

	vrachArr.push_back({ kod, kabinet, FIO, cpecilizacia });

	ofstream filepolz("doctors.txt", ios::app);
	filepolz << kod << ' ' << kabinet << ' ' << FIO << endl << cpecilizacia << ' ' << endl;
	filepolz.close();
	cout << "���� ������� � �������" << endl;
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
		cout << "| " << setiosflags(ios::left) << setw(3) << "���" << " |" << setw(9) << "�������" << " |" << setw(29) << "���" << " |" << setw(29) << "�������������" << " |" << endl;
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
	cout << "������� ��� ��������" << endl;

	cin >> kod;

	cout << "������� ��� �������� " << endl;

	getline(cin >> ws, FIO);

	cout << "������� ���-�� ������ ��� ��������" << endl;

	cin >> age;

	cout << "������� ����� ���������� �������� " << endl;

	getline(cin >> ws, city);

	cout << "������� ������� ��������" << endl;

	cin >> telephone;
	proverkanomera();

	cout << "������� ������� ������� " << endl;

	getline(cin >> ws, diagnose);

	pathientArr.push_back({ kod, FIO, age, city, telephone, diagnose });

	ofstream filepolz("Pathient.txt", ios::app);
	filepolz << kod << ' ' << FIO << endl << age << ' ' << city << endl << telephone << ' ' << diagnose << endl;
	filepolz.close();
	cout << "������� ������� � �������" << endl;
	filepolz.close();
	system("pause");
	menuAdmin();
}
int proverkanomera()
{
	char str[10];
	int telephone;
	bool correct = false;
	cout << "������� ���������� �����: ";

	while (!correct)
	{
		cout << "+375";
		cin >> str;
		if (strlen(str) != 9)
		{
			cout << "�������� ���������� ����!" << endl;
		}
		else
		{
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] < '0' || str[i] > '9')
				{
					cout << "�������� ������! ������� ������ �����." << endl;
					break;
				}
				else
				{
					correct = true;
				}
			}
		}
	}
	cout << "�� ����� �����: +375" << str << endl;
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
		cout << "| " << setiosflags(ios::left) << setw(10) << "���"
			<< " | " << setw(26) << "���"
			<< " | " << setw(9) << "�������"
			<< " | " << setw(9) << "�����"
			<< " | " << setw(15) << "�������"
			<< " | " << setw(12) << "�������" << " |" << endl;
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
			cout << "�������� ����. ���������." << endl;
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
		cout << "�������� ����. ���������." << endl;
		menu1();
		break;
	}
	}
}