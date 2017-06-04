struct Student	
{				
	char ID_Num[25];			
	char Name[25];
	int	Age;
	char SurName[25];
	char University[25];
};
struct University
{
	char Name[25];
	char City[25];
	char Country[25];
	char Students[25];
};

// For Students
void Show_Data(int n, Student *s);
void Add_Data(int n, Student *s);

void Del_by_ID(int n, Student *s);
void Del_by_Name(int n, Student *s);
void Del_by_Age(int n, Student *s);
void Del_by_SurName(int n, Student *s);
void Del_by_University(int n, Student *s);

void Search_by_ID(int n, Student *s);
void Search_by_Name(int n, Student *s);
void Search_by_Age(int n, Student *s);
void Search_by_SurName(int n, Student *s);
void Search_by_University(int n, Student *s);

void Sort_by_ID(int n, Student *s);
void Sort_by_Name(int n, Student *s);
void Sort_by_Age(int n, Student *s);
void Sort_by_SurName(int n, Student *s);
void Sort_by_University(int n, Student *s);

// For University
void Show_Info(int n, University *u);
void Add_Info(int n, University *u);

void Del_by_Name1(int n, University *u);
void Del_by_City(int n, University *u);
void Del_by_Country(int n, University *u);
void Del_by_Students(int n, University *u);

void Search_by_Name1(int n, University *u);
void Search_by_City(int n, University *u);
void Search_by_Country(int n, University *u);
void Search_by_Students(int n, University *u);

void Sort_by_Name1(int n, University *u);
void Sort_by_City(int n, University *u);
void Sort_by_Country(int n, University *u);
void Sort_by_Students(int n, University *u);

void sizeS(int *size);
void sizeU(int *size);

void printS(int n, Student *s);
void printU(int n, University *u);

void Registration(int n, Student *s);

// --------- Statistics ---------
void Statistic_Uni_st(int n, Student *s);