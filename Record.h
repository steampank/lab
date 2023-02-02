#pragma once
#ifndef RecordH
#define RecordH
#include <iostream>
class MyString
{
	char* s;
	int len;
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&);
	int input();
	void output();
	int finput();
	void foutput();
	MyString& operator = (const MyString&);
	friend int operator == (const MyString&, const MyString&);
	friend int operator <= (const MyString&, const MyString&);
	friend int operator >= (const MyString&, const MyString&);
	MyString& operator += (const MyString&);
	friend MyString& operator + (MyString&, const MyString&);
	friend std::ostream& operator << (std::ostream&, const MyString&);
	friend std::istream& operator >> (std::istream&, MyString&);
};

class MyDate {
	int day;
	int month;
	int year;
	static int daytab[2][13];
	static const char* MonthName[13];
	static const char* DayNames[8];
public:
	MyDate() { day = 1; month = 1; year = 2000; }
	MyDate(int dd, int mm, int yy) { day = dd; month = mm; year = yy; if (!validate()) { std::cout << "Error"; day = month = year = 0; }; }
	MyDate(const MyDate& A) { day = A.day; month = A.month; year = A.year; }
	~MyDate() { day = 0; month = 0; year = 0; };
	int getDay() { return day; };
	int getMonth() { return month; };
	int getYear() { return year; };
	void setDay(int dd) { int tmp = day;   day = dd;     if (!validate()) day = tmp; };
	void setMonth(int mm) { int tmp = month; month = mm; if (!validate()) month = tmp; };
	void setYear(int yy) { int tmp = year; year = yy; if (!validate()) year = tmp; };
	static int vis(int yy) { return ((!(yy % 4)) && (yy % 100) || (!(yy % 400))); };
	int input();
	void output();
	void finput();
	void foutput();
	int validate();
	long get_AllDays();
	void AddDays(int);
	void AddMonths(int);
	void AddYears(int);
	MyDate& operator = (const MyDate&);
	friend int operator == (const MyDate&, const MyDate&);
	friend int operator <= (const MyDate&, const MyDate&);
	friend int operator >= (const MyDate&, const MyDate&);
	void operator + (int);
	void operator - (int);
	friend std::ostream& operator << (std::ostream&, const MyDate&);
	friend std::istream& operator >> (std::istream&, MyDate&);
};
class Record
{
	MyString name;
	MyString pol;
	MyString adres;
	int phone = 0;
	MyString buro;
	MyString aBuro;
	double price = 0;
	MyDate mydate;
public:
	Record();
	Record(char*, char*, char*, int, char*, char*, double, int, int, int);
	Record(const Record&);
	~Record() {};
	Record* copy();
	int cmp(Record*);
	void input();
	void output();
	void finput();
	void foutput();
};
class vec
{
	Record** v;
	int size;
public:
	vec();
	vec(int);
	vec(const vec&);
	~vec();
	Record** begin() { return v; };
	Record** end() { return v + size; };
	int getSize() { return size; };
	Record*& item(int);
	void reSize(int);
};

#endif