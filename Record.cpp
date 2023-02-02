#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include "Record.h"
#include <string>
std::ofstream fout("E:\\InfSystem\\out.txt");
std::ifstream fin("E:\\InfSystem\\in.txt");
//RECORD
Record::Record()
{
	name; pol; adres; phone = 0; buro; aBuro; price = 0.0; mydate;
}
Record::Record(char* Name, char* Pol, char* Adres, int Phone, char* Buro, char* ABuro, double Price, int D, int M, int Y): 
	name(Name),pol(Pol),adres(Adres),phone(Phone),buro(Buro),aBuro(ABuro),price(Price),mydate(D,M,Y)
{}
Record::Record(const Record& A):
	name(A.name),pol(A.pol),adres(A.adres),phone(A.phone),buro(A.buro),aBuro(A.aBuro),price(A.price),mydate(A.mydate)
{}
Record* Record::copy()
{
	return new Record(*this);
}
int Record::cmp(Record* r)
{
	if (name.cmp(r->name) != 0)
		return name.cmp(r->name);
	else if (pol.cmp(r->pol) != 0)
		return pol.cmp(r->pol);
	else if (adres.cmp(r->adres) != 0)
		return adres.cmp(r->adres);
	else if ((phone - r->phone) != 0)
		return phone - r->phone;
	else if (buro.cmp(r->buro) != 0)
		return buro.cmp(r->buro);
	else if (aBuro.cmp(r->aBuro) != 0)
		return aBuro.cmp(r->aBuro);
	else if ((price - r->price) != 0)
		return price - r->price;
	else if ((mydate.getDay() - r->mydate.getDay()) != 0)
		return mydate.getDay() - r->mydate.getDay();
	else if ((mydate.getMonth() - r->mydate.getMonth()) != 0)
		return mydate.getMonth() - r->mydate.getMonth();
	else if ((mydate.getYear() - r->mydate.getYear()) != 0)
		return mydate.getYear() - r->mydate.getYear();
	return 0;
}
void Record::input()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Имя: "; name.input();
	std::cout << "Пол: "; std::cin >> pol;
	std::cout << "Адрес: "; std::cin >> adres;
	std::cout << "Телефон: "; std::cin >> phone;
	std::cout << "Бюро: "; buro.input();
	std::cout << "Адрес бюро: "; std::cin >> aBuro;
	std::cout << "Цена: "; std::cin >> price;
	std::cout << "Дата: "; std::cin >> mydate;
}
void Record::output()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Имя: " << name << std::endl;
	std::cout << "Пол: " << pol << std::endl;
	std::cout << "Адрес: "<< adres << std::endl;
	std::cout << "Телефон: " << phone << std::endl;
	std::cout << "Бюро: "<< buro << std::endl;
	std::cout << "Адрес бюро: "<< aBuro << std::endl;
	std::cout << "Цена: " << price << std::endl;
	std::cout << "Дата: " << mydate << std::endl;
}
void Record::finput()
{
	setlocale(LC_ALL, "rus");
	name.finput();
	fin >> pol;
	fin >> adres;
	fin >> phone;
	buro.finput();
	fin >> aBuro;
	fin >> price;
	fin >> mydate;
}
void Record::foutput()
{

	fout << name << std::endl;
	fout << pol << std::endl;
	fout << adres << std::endl;
	fout << phone << std::endl;
	fout << buro << std::endl;
	fout << aBuro << std::endl;
	fout << price << std::endl;
	fout << mydate << std::endl;
}

//MYDATE
int MyDate::input()
{
	setlocale(LC_ALL, "rus");
	std::cout << "День: "; std::cin >> day;
	std::cout << "Месяц: "; std::cin >> month;
	std::cout << "Год: "; std::cin >> year; std::cout << std::endl;
	if (!validate()) { std::cout << "Ошибка даты!" << std::endl; day = month = year = 0; } return 1;
}
void MyDate::finput()
{
	fin >> day;
	fin >> month;
	fin >> year;
}
void MyDate::output()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Дата: " << day << '.' << month << '.' << year << std::endl;
}
void MyDate::foutput()
{
	fout << day << '.' << month << '.' << year << std::endl;
}
void MyDate::AddDays(int d)
{
	if (d > 0)
		while (d--)
		{
			day++;
			if (day > daytab[vis(year)][month])
			{
				day = 1; month++;
				if (month == 13)
					month = 1;
				year++;
			}
		}
	else while (d++)
	{
		day--;
		if (!day)
		{
			month--;
			if (!month)
			{
				month = 12;
				year--;
				if (!year)
				{
					year = 1; month = 1; day = 1; return;
				}
			}
			day = daytab[vis(year)][month];
		}
	}
}
void MyDate::AddMonths(int m)
{
	if (m > 0)
		while (m--)
		{
			month++;
			if (month == 13)
			{
				month = 1; year++;
			}
		}
	else while (m++)
	{
		month--;
		if (!month)
		{
			month = 12; year--;
			if (!year)
			{
				year = 1; month = 1; return;
			}
		}
	}
	int k;
	if (day > (k = daytab[vis(year)][month])) day = k;
}
void MyDate::AddYears(int y)
{
	year += y;
	if (year <= 0)
	{
		year = 1; month = 1; day = 1;
	}
	int k;
	if (day > (k = daytab[vis(year)][month])) day = k;
}
MyDate& MyDate::operator = (const MyDate& a)
{
	day = a.day;
	month = a.month;
	year = a.year;
	return *this;
}
void MyDate::operator + (int d)
{
		while (d--)
		{
			day++;
			if (day > daytab[vis(year)][month])
			{
				day = 1; month++;
				if (month == 13)
				{
					month = 1;
					year++;
				}
			}
		}
}
void MyDate::operator - (int d)
{
	while (d--)
	{
		day--;
		if (!day)
		{
			month--;
			if (!month)
			{
				month = 12;
				year--;
				if (!year)
				{
					year = 1; month = 1; day = 1;
				}
			}
			day = daytab[vis(year)][month];
		}
	}
}
int MyDate::daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31} };
const char* MyDate::MonthName[13] = { "null","January","February","March","April","May","June","July","August","September","October","November","December" };
const char* MyDate::DayNames[8] = { "null","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
int MyDate::validate()
{
	return(year > 0 && month > 0 && month <= 12 && day > 0 && day <= daytab[vis(year)][month]);
}
long MyDate::get_AllDays()
{
	unsigned long d, m, y;
	d = day;
	y = 1;
	m = 1;
	while (y < year)
	{
		d += 365 + vis(y);
		y++;
	}
	while (m < month)
	{
		d += daytab[vis(year)][m];
		m++;
	}
	return d;
}
int operator == (const MyDate& a, const MyDate& b)
{
	return((a.day == b.day) && (a.month == b.month) && (a.year == b.year));
}
int operator <= (const MyDate& a, const MyDate& b)
{
	if (a.year < b.year)
		return 1;
	else if (a.year == b.year)
	{
		if (a.month < b.month)
			return 1;
		else if (a.month == b.month)
			if (a.day <= b.day)
				return 1;
	}
	else
		return 0;
}
int operator >= (const MyDate& a, const MyDate& b)
{
	if (a.year > b.year)
		return 1;
	else if (a.year == b.year)
	{
		if (a.month > b.month)
			return 1;
		else if (a.month == b.month)
			if (a.day >= b.day)
				return 1;
	}
	else
		return 0;
}
std::ostream& operator << (std::ostream& os, const MyDate& md)
{
	if (md.year > 0 && md.month > 0 && md.month <= 12 && md.day > 0 && md.day <= md.daytab[md.vis(md.year)][md.month])
		os << md.day << "." << md.month << "." << md.year;
	else
		std::cout << "Ошибка даты!" << std::endl;
	return os;
}
std::istream& operator >> (std::istream& is, MyDate& md)
{
	
	is >> md.day >> md.month >> md.year;
	return is;
}


//MYSTRING
MyString::MyString() 
{ 
	s = new char[1];
	*s = '\0';
	len = 0; 
}
MyString::MyString(char* t)
{ 
	s = new char[strlen(t) + 1];
	*s = '\0'; 
	strcpy(s, t); 
	len = strlen(t);
}
MyString::MyString(const MyString& t)
{ 
	s = new char[t.len + 1];
	*s = '\0';
	strcpy(s, t.s);
	len = t.len;
}
MyString::~MyString()
{ 
	delete[] s;
}
char& MyString::item(int t) 
{
	char err = 'e';
	if (t <= len && t >= 0)
		return s[t];
	else 
		std::cout << "Error.";
	return err;
}
MyString* MyString::copy()
{ 
	return new MyString(*this);
}
void MyString::assign(const MyString& t)
{
	s = new char[t.len + 1];
	*s = '\0';
	strcpy(s, t.s);
	len = t.len;
}
int MyString::cmp(const MyString& t)
{ 
	return strcmp(s, t.s);
}
int MyString::equal(const MyString& t)
{ 
	return strcmp(s, t.s) == 0;
}
int MyString::input()
{
	if (std::cin.eof()) 
		return 0;
	char buf1[256];
	std::cin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0) 
		std::cin.getline(buf1, 254, '\n');
	s = new char[strlen(buf1) + 1];
	len = strlen(buf1);
	*s = '\0'; strcpy(s, buf1);
	return 0;
}
void MyString::output()
{
	std::cout << s << std::endl;
}
int MyString::finput()
{
	if (fin.eof())
		return 0;
	char buf1[256];
	fin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0)
		fin.getline(buf1, 254, '\n');
	s = new char[strlen(buf1) + 1];
	len = strlen(buf1);
	*s = '\0'; strcpy(s, buf1);
	return 0;
}
void MyString::foutput()
{
	fout << s << std::endl;
}
MyString& MyString::operator = (const MyString& t)
{ 
	if (this == &t)
		return *this;
	delete[]s;
	s = new char[(len = t.len) + 1];
	strcpy(s, t.s);
	return *this;
}
int operator == (const MyString & a, const MyString & b) 
{ 
	return(strcmp(a.s, b.s));
}
int operator <= (const MyString& a, const MyString& b)
{
	return(strcmp(a.s, b.s) <= 0);
}
int operator >= (const MyString& a, const MyString& b)
{
	return(strcmp(a.s, b.s) >= 0);
}
MyString& MyString::operator += (const MyString& t)
{ 
	char* p = new char[len = (len + t.len) + 1];
	strcpy(p, s);
	strcat(p, t.s);
	delete[]s;
	s = p;
	return *this;
}
MyString& operator + (MyString& a, const MyString& b)
{
	a += b;
	return a;
}
std::ostream& operator << (std::ostream& os, const MyString& ms) 
{ 
	os << ms.s;
	return os; 
}
std::istream& operator >> (std::istream& is, MyString& ms) 
{ 
	char buf[256];
	is.getline(buf, 254, '\n');
	ms = buf; 
	return is;
}


//VEC
vec::vec()
{
	v = new Record * [size = 10];
	for (int i = 0; i < size; i++)
		v[i] = NULL;
}
vec::vec(int sz)
{
	v = new Record * [size = sz];
}
vec::vec(const vec& a)
{
	v = new Record * [size = a.size];
	for (int i = 0; i < size; i++)
		v[i] = a.v[i];
}
vec::~vec()
{
	delete[]v;
}
Record*& vec::item(int it) //доступ к эл-ту
{
	if (it < 0 || it > size)
	{
		std::cout << "Index Error";
		exit(1);
	}
	return v[it];
}
void vec::reSize(int n)
{
	Record** t = new Record * [size + n];
	for (int i = 0; i < size && v[i] != NULL; i++)
		t[i] = v[i]->copy();
	for (Record** a = v; a - v < size && *a != NULL; a++)
		delete* a;
	v = t;
	size = size + n;
}

