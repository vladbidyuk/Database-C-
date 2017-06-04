#include "List.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int size;
	char d;
	char choise;
	string Password = "Password";
	string pass;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "---000----00000----000-00000--00000000000----0000-----00000------00000----" << endl;
	cout << "----000----000----000---000---00000000000---00--00----000-00----00-000----" << endl;
	cout << "----000----000----000---000-------000------00----00---000--00--00--000----" << endl;
	cout << "----000----000----000---000-------000------00000000---000---0000---000----" << endl;
	cout << "----000----000----000---000-------000------00000000---000----00----000----" << endl;
	cout << "----000----000----000---000-------000-----000----000--000----------000----" << endl;
	cout << "-----000---000---000----000-------000-----000----000--000----------000----" << endl;
	cout << "------00000---00000----00000-----00000----000----000--000----------000----" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	system("PAUSE");
	system("cls");

	cout << "Who you are?" << endl << "[1] Admin" << endl << "[2] User" << endl << "[0] Exit" << endl;
	cout << "Please, enter your choise: ";	cin >> choise;
	system("cls");
	while (choise != '0')
	{
	way:
		// Admin
		if (choise == '1')
		{
			for (int i = 0; i < 3; i++)
			{
				cout << "Please, enter password [" << i + 1 << "-3]: ";	cin >> pass;
				if (pass == Password)
				{
					cout << "Password is correct" << endl;
					system("pause");	system("cls");

					cout << "Select the Stucture: " << endl << "1. Students" << endl << "2. University" << endl << "0. Exit" << endl;
					cout << "Select: ";	cin >> choise;
					system("cls");
					while (choise != '0')
					{
						// Choise for Students
						if (choise == '1')
						{
							cout << "Select the function: " << endl << "1. Show Data" << endl << "2. Add Data" << endl << "3. Detele Data" << endl << "4. Sort Data" << endl << "5. Search Data" << endl << "6. Statistics" << endl << "7. Delete all Data" << endl << "0. Exit" << endl;
							cout << "Select: "; cin >> choise;
							system("cls");
							while (choise != '0')
							{
								// Show data
								if (choise == '1')
								{
									sizeS(&size);
									Student *s = new Student[size];
									Show_Data(size, s);
									system("cls");
								}
								// Add data
								if (choise == '2')
								{
									cout << "How many students you want add? " << endl;
									cin >> size;	
									system("cls");
									Student *s = new Student[size];
									Add_Data(size, s);
									system("cls");
								}
								// Delete data
								if (choise == '3')
								{
									system("cls");
									cout << "Select the criteria removal:" << endl << "1. By ID number" << endl << "2. By Name" << endl << "3. By SurName" << endl << "4. By Age" << endl << "5. By University" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");
									if (d == '1')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Del_by_ID(size, s);
									}
									if (d == '2')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Del_by_Name(size, s);
									}
									if (d == '3')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Del_by_SurName(size, s);
									}
									if (d == '4')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Del_by_Age(size, s);
									}
									if (d == '5')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Del_by_University(size, s);
									}	system("cls");
								}
								// Sort data
								if (choise == '4')
								{
									system("cls");
									cout << "Select the criteria sort:" << endl << "1. By ID number" << endl << "2. By Name" << endl << "3. By SurName" << endl << "4. By Age" << endl << "5. By University" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");

									if (d == '1')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Sort_by_ID(size, s);
									}
									if (d == '2')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Sort_by_Name(size, s);
									}
									if (d == '3')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Sort_by_SurName(size, s);
									}
									if (d == '4')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Sort_by_Age(size, s);
									}
									if (d == '5')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Sort_by_University(size, s);
									}	system("cls");
								}
								// Search data
								if (choise == '5')
								{
									system("cls");
									cout << "Select the criteria search:" << endl << "1. By ID number" << endl << "2. By Name" << endl << "3. By SurName" << endl << "4. By Age" << endl << "5. By University" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");

									if (d == '1')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Search_by_ID(size, s);
									}
									if (d == '2')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Search_by_Name(size, s);
									}
									if (d == '3')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Search_by_SurName(size, s);
									}
									if (d == '4')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Search_by_Age(size, s);
									}
									if (d == '5')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Search_by_University(size, s);
									}	system("cls");
								}
								// Statistics
								if (choise == '6')
								{
									cout << "Statistics about students." << endl << "1. Univesity" << endl << "0. Exit" << endl;
									cout << "Select: ";	cin >> d;	
									system("cls");
									// University
									if (d == '1')
									{
										sizeS(&size);
										Student *s = new Student[size];
										Statistic_Uni_st(size, s);
										system("cls");
									}
								}
								// Delete all data
								if (choise == '7')
								{
									cout << "Do you want delete all information about Students?" << endl << "Yes(1)" << endl << "No(2)" << endl;
									cout << "Your select: ";	cin >> d;
									system("cls");
									if (d == '1')
									{
										ofstream of;
										of.open("List.st", ios::binary);
										of.close();
										cout << "All information was delete." << endl;
										system("pause");
									}
									system("cls");
								}

								cout << "Select the function: " << endl << "1. Show Data" << endl << "2. Add Data" << endl << "3. Detele Data" << endl << "4. Sort Data" << endl << "5. Search Data" << endl << "6. Statistics" << endl << "7. Delete all Data" << endl << "0. Exit" << endl;
								cout << "Select: ";	cin >> choise;
								system("cls");
							}
						}
						// Choise for University
						if (choise == '2')
						{
							cout << "Select the function: " << endl << "1. Show Info" << endl << "2. Add Info" << endl << "3. Detele Data" << endl << "4. Sort Data" << endl << "5. Search Data" << endl << "6. Delete add data" << endl << "0. Exit" << endl;
							cout << "Select: "; cin >> choise;
							system("cls");
							while (choise != '0')
							{
								// Show Info
								if (choise == '1')
								{
									sizeU(&size);
									University *u = new University[size];
									Show_Info(size, u);
									system("cls");
								}
								// Add Info
								if (choise == '2')
								{
									cout << "How many University you want add? " << endl;
									cin >> size;
									system("cls");
									University *u = new University[size];
									Add_Info(size, u);
									system("cls");
								}
								// Delete Data
								if (choise == '3')
								{
									system("cls");
									cout << "Select the criteria removal:" << endl << "1. By Name" << endl << "2. By Country" << endl << "3. By City" << endl << "4. By number of Students" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");
									if (d == '1')
									{
										sizeU(&size);
										University *u = new University[size];
										Del_by_Name1(size, u);
									}
									if (d == '2')
									{
										sizeU(&size);
										University *u = new University[size];
										Del_by_Country(size, u);
									}
									if (d == '3')
									{
										sizeU(&size);
										University *u = new University[size];
										Del_by_City(size, u);
									}
									if (d == '4')
									{
										sizeU(&size);
										University *u = new University[size];
										Del_by_Students(size, u);
									}	system("cls");
								}
								// Sort Data
								if (choise == '4')
								{
									system("cls");
									cout << "Select the criteria sort:" << endl << "1. By Name" << endl << "2. By Country" << endl << "3. By City" << endl << "4. By number of free spaces" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");

									if (d == '1')
									{
										sizeU(&size);
										University *u = new University[size];
										Sort_by_Name1(size, u);
									}
									if (d == '2')
									{
										sizeU(&size);
										University *u = new University[size];
										Sort_by_Country(size, u);
									}
									if (d == '3')
									{
										sizeU(&size);
										University *u = new University[size];
										Sort_by_City(size, u);
									}
									if (d == '4')
									{
										sizeU(&size);
										University *u = new University[size];
										Sort_by_Students(size, u);
									}	system("cls");

								}
								// Search Data
								if (choise == '5')
								{

									system("cls");
									cout << "Select the criteria search:" << endl << "1. By Name" << endl << "2. By name of Country" << endl << "3. By name of City" << endl << "4. By number of Students" << endl << "0. Return" << endl << "Enter your choise: ";
									cin >> d;
									system("cls");

									if (d == '1')
									{
										sizeU(&size);
										University *u = new University[size];
										Search_by_Name1(size, u);
									}
									if (d == '2')
									{
										sizeU(&size);
										University *u = new University[size];
										Search_by_Country(size, u);
									}
									if (d == '3')
									{
										sizeU(&size);
										University *u = new University[size];
										Search_by_City(size, u);
									}
									if (d == '4')
									{
										sizeU(&size);
										University *u = new University[size];
										Search_by_Students(size, u);
									}	system("cls");
								}
								// Delete all data
								if (choise == '6')
								{
									cout << "Do you want delete all information about Students?" << endl << "Yes(1)" << endl << "No(2)" << endl;
									cout << "Your select: ";	cin >> d;
									system("cls");
									if (d == '1')
									{
										ofstream of;
										of.open("List.uni", ios::binary);
										of.close();
										cout << "All information was delete." << endl;
										system("pause");
									}
									system("cls");
								}

								cout << "Select the function: " << endl << "1. Show Info" << endl << "2. Add Info" << endl << "3. Detele Data" << endl << "4. Sort Data" << endl << "5. Search Data" << endl << "6. Delete add data" << endl << "0. Exit" << endl;
								cout << "Select: ";	cin >> choise;
								system("cls");
							}
						}

						cout << "Select the Stucture: " << endl << "1. Students" << endl << "2. University" << endl << "0. Exit" << endl;
						cout << "Select: ";	cin >> choise;
						system("cls");
					}	goto way;
				}
				else { cout << "Password is uncorrect" << endl;	system("cls"); }
			}
		}
		// User
		if (choise == '2')
		{
			cout << "Welcome.\n" << "Select the function:\n" << "[1] All University\n" << "[2] Registration\n" << "[0] Exit" << endl;
			cout << "Select: ";	cin >> choise;
			system("cls");
			
			while (choise != '0')
			{
				// отображение доступних университетов 
				if (choise == '1')
				{
					sizeU(&size);
					University *c = new University[size];
					Show_Info(size, c);
					system("cls");
				}
				// Registration
				if (choise == '2')
				{
					cout << "You can only register your account. " << endl;	system("pause"); system("cls");
					
					int size = { 1 };
					Student *s = new Student[size];
					Registration(size, s);
					system("cls");
				}

				cout << "Welcome.\n" << "Select the function:\n" << "[1] All University\n" << "[2] Registration\n" << "[0] Exit" << endl;
				cout << "Select: ";	cin >> choise;
				system("cls");
			}
			

		}

		cout << "Who you are?" << endl << "[1] Admin" << endl << "[2] User" << endl << "[0] Exit" << endl;
		cout << "Please, enter your choise: ";	cin >> choise;
		system("cls");
	}
	cout << "Goodbuy, and have a nice day !!!" << endl;
	system("pause");
	return 0;
}