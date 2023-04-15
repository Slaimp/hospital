#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cctype>
#include <string>
#include<vector>
#include<iomanip>
using namespace std;
struct vrach {
	int kod;
	int kabinet;
	string FIO;
	string cpecilizacia;
};
extern vector <vrach> vrachArr;

struct pathient {
	int kod;
	string FIO;
	int age;
	string city;
	int telephone;
	string diagnose;
};
extern vector <pathient> pathientArr;
