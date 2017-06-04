#include "List.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

//---------------- For Students ---------------
void Add_Data(int n, Student *s)
{
	ofstream of;
	of.open("List.st", ios::binary | ios_base::app);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter [" << i + 1 << "] ID code: ";		cin >> s[i].ID_Num;		
		cout << "Enter [" << i + 1 << "] Name: ";			cin >> s[i].Name;		s[i].Name[0] = toupper(s[i].Name[0]);
		cout << "Enter [" << i + 1 << "] Sur_Name: ";		cin >> s[i].SurName;	s[i].SurName[0] = toupper(s[i].SurName[0]);
age:	cout << "Enter [" << i + 1 << "] Age: ";			cin >> s[i].Age;
															if (s[i].Age<18 || s[i].Age>100)
															{
																cout << "Error" << endl;
																goto age;
															}
		cout << "Enter [" << i + 1 << "] University: ";		cin >> s[i].University;	s[i].University[0] = toupper(s[i].University[0]);

		system("cls");
		of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
}
void Show_Data(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(11) << "Age|" << setw(16) << "University|" << endl;
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		cout << "----------------------------------------------------------------------" << endl;
		cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(10) << s[i].Age << "|" << setw(15) << s[i].University << "|" << endl;
	};
	if (n == 0)	cout << "File is clear!!! " << endl;
	fo.close();
	system("pause");
}

// Delete data
void Del_by_ID(int n, Student *s)
{
	char id[25];
	cout << "Enter ID: "; cin >> id;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	ofstream of;
	of.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(id, s[i].ID_Num) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
	system("pause");
}
void Del_by_Name(int n, Student *s)
{
	char name[25];
	cout << "Enter name: "; cin >> name;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	ofstream of;
	of.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, s[i].Name) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
	system("pause");
}
void Del_by_SurName(int n, Student *s)
{
	char surname[25];
	cout << "Enter surname: "; cin >> surname;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	ofstream of;
	of.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(surname, s[i].SurName) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
	system("pause");
}
void Del_by_Age(int n, Student *s)
{
	int age;
	cout << "Enter age of student: "; cin >> age;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	ofstream of;
	of.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (age == s[i].Age) { cout << "Record has been deleted." << endl; }
		else { of.write((char*)&s[i], sizeof(Student)); }
	}
	of.close();
	system("pause");
}
void Del_by_University(int n, Student *s)
{
	char university[25];
	cout << "Enter name of University: "; cin >> university;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	ofstream of;
	of.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(university, s[i].University) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
	system("pause");
}

// Sort data
void Sort_by_ID(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(s[j].ID_Num, s[j - 1].ID_Num)<0)	swap(s[j], s[j - 1]);
	printS(n, s);
}
void Sort_by_Name(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(s[j].Name, s[j - 1].Name)<0)	swap(s[j], s[j - 1]);
	printS(n, s);
}
void Sort_by_SurName(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(s[j].SurName, s[j - 1].SurName)<0)	swap(s[j], s[j - 1]);
	printS(n, s);
}
void Sort_by_Age(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();				//записали в массив структур данные с файла
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (s[j].Age < s[j - 1].Age)	swap(s[j], s[j - 1]);
	printS(n, s);
}
void Sort_by_University(int n, Student *s)
{
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&s[i], sizeof(Student));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(s[j].University, s[j - 1].University)<0)	swap(s[j], s[j - 1]);
	printS(n, s);
}

// Search data
void Search_by_ID(int n, Student *s)
{
	char id[25];
	int res = 0;
	cout << "Enter ID: "; cin >> id;
	system("cls");
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(16) << "University|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (strcmp(id, s[i].ID_Num) == 0) 
		{ 
			cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(15) << s[i].University << "|" << endl;
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_Name(int n, Student *s)
{
	char name[25];
	int res = 0;
	cout << "Enter Name: "; cin >> name;
	system("cls");
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(16) << "University|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (strcmp(name, s[i].Name) == 0) 
		{ 
			cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(15) << s[i].University << "|" << endl;
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_SurName(int n, Student *s)
{
	char surname[25];
	int res = 0;
	cout << "Enter Surname: "; cin >> surname;
	system("cls");
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(16) << "University|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (strcmp(surname, s[i].SurName) == 0) 
		{ 
			cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(15) << s[i].University << "|" << endl;
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_Age(int n, Student *s)
{
	int age;
	int res = 0;
	cout << "Enter age of student: "; cin >> age;
	system("cls");
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(11) << "Age|" << setw(16) << "University|" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (age == s[i].Age) 
		{ 
			cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(10) << s[i].Age << "|" << setw(15) << s[i].University << "|" << endl;
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_University(int n, Student *s)
{
	char university[25];
	int res = 0;
	cout << "Enter name of University: "; cin >> university;
	system("cls");
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(16) << "University|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (strcmp(university, s[i].University) == 0) 
		{ 
			cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(15) << s[i].University << "|" << endl;
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}

//--------------- For University ---------------

void Add_Info(int n, University *u) 
{
	ofstream of;
	of.open("List.uni", ios::binary | ios_base::app);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter [" << i + 1 << "] Name of University: ";	cin >> u[i].Name;		u[i].Name[0] = toupper(u[i].Name[0]);
		cout << "Enter [" << i + 1 << "] Name of City: ";		cin >> u[i].City;		u[i].City[0] = toupper(u[i].City[0]);
		cout << "Enter [" << i + 1 << "] Name of Country: ";	cin >> u[i].Country;	u[i].Country[0] = toupper(u[i].Country[0]);
		cout << "Enter [" << i + 1 << "] Number of free spaces: ";	cin >> u[i].Students;

		system("cls");
		of.write((char*)&u[i], sizeof(University));
	}
	of.close();
}
void Show_Info(int n, University *u)
{
	ifstream fo;
	fo.open("List.uni", ios::binary);
	cout << setw(11) << "Name|" << setw(16) << "Country|" << setw(16) << "City|" << setw(11) << "Spaces|" << endl;
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&u[i], sizeof(University));
		cout << "------------------------------------------------------" << endl;
		cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(15) << u[i].City << "|" << setw(10) << u[i].Students << "|" << endl;
	};
	if (n == 0)	cout << "File is clear!!! " << endl;
	fo.close();
	system("pause");
}

void Del_by_Name1(int n, University *u)
{
	char name[25];
	cout << "Enter name: "; cin >> name;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	ofstream of;
	of.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, u[i].Name) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&u[i], sizeof(University));
	}
	of.close();
	system("pause");
}
void Del_by_City(int n, University *u)
{
	char name[25];
	cout << "Enter name of City: "; cin >> name;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	ofstream of;
	of.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, u[i].City) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&u[i], sizeof(University));
	}
	of.close();
	system("pause");
}
void Del_by_Country(int n, University *u)
{
	char name[25];
	cout << "Enter name of Country: "; cin >> name;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	ofstream of;
	of.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name, u[i].Country) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&u[i], sizeof(University));
	}
	of.close();
	system("pause");
}
void Del_by_Students(int n, University *u)
{
	char number[25];
	cout << "Enter number of free spaces: "; cin >> number;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	ofstream of;
	of.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(number, u[i].Students) == 0) cout << "Record has been deleted." << endl;
		else  of.write((char*)&u[i], sizeof(University));
	}
	of.close();
	system("pause");
}

void Sort_by_Name1(int n, University *u)
{
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(u[j].Name, u[j - 1].Name)<0)	swap(u[j], u[j - 1]);
	printU(n, u);
}
void Sort_by_City(int n, University *u)
{
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(u[j].City, u[j - 1].City)<0)	swap(u[j], u[j - 1]);
	printU(n, u);
}
void Sort_by_Country(int n, University *u)
{
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(u[j].Country, u[j - 1].Country)<0)	swap(u[j], u[j - 1]);
	printU(n, u);
}
void Sort_by_Students(int n, University *u)
{
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
		fo.read((char*)&u[i], sizeof(University));
	fo.close();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(u[j].Students, u[j - 1].Students)<0)	swap(u[j], u[j - 1]);
	printU(n, u);
}

void Search_by_Name1(int n, University *u)
{
	char name[25];
	int res = 0;
	cout << "Enter Name: "; cin >> name;
	system("cls");
	cout << setw(11) << "University|" << setw(16) << "Country|" << setw(21) << "City|" << setw(28) << "Number of free spaces|" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&u[i], sizeof(University));
		if (strcmp(name, u[i].Name) == 0) 
		{ 
			cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(20) << u[i].City << "|" << setw(27) << u[i].Students << "|" << endl; 
			res = 1; 
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_City(int n, University *u)
{
	char name[25];
	int res = 0;
	cout << "Enter Name: "; cin >> name;
	system("cls");
	cout << setw(11) << "University|" << setw(16) << "Country|" << setw(21) << "City|" << setw(28) << "Number of free spaces|" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&u[i], sizeof(University));
		if (strcmp(name, u[i].City) == 0)
		{
			cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(20) << u[i].City << "|" << setw(27) << u[i].Students << "|" << endl;
			res = 1;
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_Country(int n, University *u)
{
	char name[25];
	int res = 0;
	cout << "Enter Name: "; cin >> name;
	system("cls");
	cout << setw(11) << "University|" << setw(16) << "Country|" << setw(21) << "City|" << setw(28) << "Number of free spaces|" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&u[i], sizeof(University));
		if (strcmp(name, u[i].Country) == 0)
		{
			cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(20) << u[i].City << "|" << setw(27) << u[i].Students << "|" << endl;
			res = 1;
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}
void Search_by_Students(int n, University *u)
{
	char name[25];
	int res = 0;
	cout << "Enter Name: "; cin >> name;
	system("cls");
	cout << setw(11) << "University|" << setw(16) << "Country|" << setw(21) << "City|" << setw(28) << "Number of free spaces|" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	ifstream fo;
	fo.open("List.uni", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&u[i], sizeof(University));
		if (strcmp(name, u[i].Students) == 0)
		{
			cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(20) << u[i].City << "|" << setw(27) << u[i].Students << "|" << endl;
			res = 1;
		}
	}
	if (res == 0) cout << "Not found" << endl;
	fo.close();
	system("Pause");
}

//--------------- Other ---------------

void sizeS(int *size)
{
	ifstream f("List.st", ios::binary);
	f.seekg(0, ios::end);
	*size = f.tellg() / sizeof(Student);
	f.close();
}
void sizeU(int *size)
{
	ifstream f("List.uni", ios::binary);
	f.seekg(0, ios::end);
	*size = f.tellg() / sizeof(University);
	f.close();
}

void printS(int b, Student *s)
{
	cout << setw(11) << "ID|" << setw(16) << "Name|" << setw(16) << "Surname|" << setw(11) << "Age|" << setw(16) << "University|" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "----------------------------------------------------------------------" << endl;
		cout << setw(10) << s[i].ID_Num << "|" << setw(15) << s[i].Name << "|" << setw(15) << s[i].SurName << "|" << setw(10) << s[i].Age << "|" << setw(15) << s[i].University << "|" << endl;
	};
	system("PAUSE");
}
void printU(int b, University *u)
{
	cout << setw(11) << "Name|" << setw(16) << "Country|" << setw(16) << "City|" << setw(11) << "Spaces|" << endl;
	for (int i = 0; i < b; i++)
	{
		cout << "------------------------------------------------------" << endl;
		cout << setw(10) << u[i].Name << "|" << setw(15) << u[i].Country << "|" << setw(15) << u[i].City << "|" << setw(10) << u[i].Students << "|" << endl;
	};
	system("PAUSE");
}

void Registration(int n, Student *s)
{
	ofstream of;
	of.open("List.st", ios::binary | ios_base::app);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter ID: ";			cin >> s[i].ID_Num;
		cout << "Enter name: ";			cin >> s[i].Name;		s[i].Name[0] = toupper(s[i].Name[0]);
		cout << "Enter surname: ";		cin >> s[i].SurName;	s[i].SurName[0] = toupper(s[i].SurName[0]);
age:	cout << "Enter age: ";			cin >> s[i].Age;
										if (s[i].Age<18 || s[i].Age>100)
										{
											cout << "Error" << endl;
											goto age;
										}
		cout << "Enter University: ";	cin >> s[i].University;	s[i].University[0] = toupper(s[i].University[0]);

		system("cls");
		of.write((char*)&s[i], sizeof(Student));
	}
	of.close();
}

// --------------- Statistics ---------------
void Statistic_Uni_st(int n, Student *s)
{
	char university[25];
	int res = 0;
	cout << "Enter name of university: ";	cin >> university;
	system("cls");
	ifstream fo;
	fo.open("List.st", ios::binary);
	for (int i = 0; i < n; i++)
	{
		fo.read((char*)&s[i], sizeof(Student));
		if (strcmp(university, s[i].University) == 0) 	res++;
	}
	if (res == 0) cout << "Not found" << endl; 
	else {	cout << "We are find ["  << res << "] students in that university." << endl;	}

	fo.close();
	system("Pause");
}