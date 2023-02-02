#pragma warning(disable : 4996)
#include "Tabl.h"

T** Tabl::begin() { return v.begin(); };
T** Tabl::end() { return cur; };
int Tabl::length() { return cur - v.begin(); };

Tabl::Tabl()
{
	cur = begin();
}
Tabl::Tabl(int sz):v(sz)
{
	cur = begin();
}
Tabl::~Tabl()
{
	for (T** t = begin(); t != cur; t++)
		delete* t;
}
T** Tabl::insert(T* t)
{
	if (length() >= v.getSize())
		return 0;
	*cur++ = t->copy();
	return cur;
}
void Tabl::sort()
{
	for (int j = 0; j < cur - begin() - 1; j++)
		for (int i = 0; i < cur - begin() - j - 1; i++)
			if (v.item(i)->cmp(v.item(i + 1)) > 0)
			{
				T* tmp = v.item(i);
				v.item(i) = v.item(i + 1);
				v.item(i + 1) = tmp;
			}
}
int Tabl::input()
{
	int nlines = cur - begin();
	if (nlines++ >= v.getSize())
		return 0;
	T* a;
	a = new T;
	a->input();
	cur = this->insert(a);
	return cur - begin();
}
int Tabl::finput()
{
	int nlines = cur - begin();
	if (nlines++ >= v.getSize())
		return 0;
	T* a;
	a = new T;
	a->finput();
	cur = this->insert(a);
	return cur - begin();
}
void Tabl::output()
{
	for (T** t = begin(); t != cur; t++)
	{
		std::cout << "_______¹" << t - begin() <<"_______"<< std::endl;
		(*t)->output();
	}

}
void Tabl::foutput()
{
	for (T** t = begin(); t != cur; t++)
	{
		(*t)->foutput();
	}
}
int Tabl::replace(T* Old, T* New)
{
	int n = 0;
	for (int i = 0; i < length(); i++)
		if ((v.item(i))->cmp(Old) == 0)
		{
			v.item(i) = New->copy();
			n++;
		}
	if (n == 0) return 0;
	return 1;
}
int Tabl::find(T* ind)
{
	T** i;
	for (i = begin(); i < cur; i++)
	{
		if ((*i)->cmp(ind) == 0)
		{
			return i - begin();
		}
	}
	return -1;
}
void Tabl::erase(int p)
{
	T** t;
	T** k;
	k = t = new T * [length() - 1];
	for (int i = 0; i < length(); i++)
		if (i != p)
			*t++ = v.item(i);
	cur = begin();
	for (; t - k; k++)
		*cur++ = (*k)->copy();
}
int Tabl::remove(T* d) 
{
	int n = 0;
	for (int i = 0; i < length(); i++)
		if ((v.item(i))->cmp(d) == 0)
			n++;
	if (n == 0)
		return 0;
	T** t;
	T** k;
	k = t = new T * [length() - n];
	for (int i = 0; i < length(); i++)
		if ((v.item(i))->cmp(d) != 0)
			*t++ = v.item(i);
	cur = begin();
	for (; t - k; k++)
		*cur++ = (*k)->copy();
	return 1;
}


