#pragma once
#ifndef TablH
#define TablH
#include "Record.h"
typedef Record T;
class Tabl
{
	vec v;
	T** cur;
public:
	Tabl();
	Tabl(int);
	~Tabl();
	T** begin();
	T** end();
	int length();
	T** insert(T*);
	void sort();
	int input();
	void output();
	int finput();
	void foutput();
	int find(T*);
	int remove(T*);
	int replace(T* Old, T* New);
	void erase(int);
};
#endif
