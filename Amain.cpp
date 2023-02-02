#include "Tabl.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Tabl* tabl = new Tabl;
	int flag = 0;
	Record* R1 = new Record;
	Record* R2 = new Record;
	do 
	{
		cout << "Выберите кейс:" << endl;
		cout << "0 - выход" << endl;
		cout << "1 - ввод" << endl;
		cout << "2 - ввод из файла" << endl;
		cout << "3 - поиск" << endl;
		cout << "4 - замена" << endl;
		cout << "5 - сортировка" << endl;
		cout << "6 - удаление по номеру" << endl;
		cout << "7 - удаление" << endl;
		cout << "8 - вывод" << endl;
		cout << "9 - вывод в файл" << endl;
		cout << "10 - операторы строки" << endl;
		cout << "11 - операторы даты" << endl;
		cin >> flag;
		switch (flag)
		{
		case 0: break;
		case 1: tabl->input(); break;
		case 2: tabl->finput(); break;
		case 3: 
		{
			cout << "Что найти?" << endl;
			R1->input();
			int a = tabl->find(R1);
			if (a >= 0) cout << "Найдено! Номер = " << a << endl;
			else cout << "Не найдено" << endl;
			break;
		}
		case 4:
		{
			cout << "Что заменить?" << endl;
			R1->input();
			cout << "На что заменить?" << endl;
			R2->input();
			int a = tabl->replace(R1, R2);
			if (a == 0) cout << "Не найдено!" << endl;
			else cout << "Успешно!";
			break;
		}
		case 5: tabl->sort(); cout << "Выполнена сортировка!" << endl; break;
		case 6: 
		{
			cout << "Номер = ";
			int p; 
			cin >> p;
			if (p < 0) { cout << "Ошибка!" << endl; break; }
			tabl->erase(p);
			break;
		}
		case 7:
		{
			cout << "Что удалить?" << endl;
			R1->input();
			int i = tabl->remove(R1);
			if (i == 0) cout << "Не найдено!" << endl;
			else cout << "Успешно!";
			break;
		}
		case 8: tabl->output(); break;
		case 9: tabl->foutput(); break;
		case 10: 
		{
			int gg = 0;
			do 
			{
				cout << "0 - выход" << endl;
				cout << "1 - =" << endl;
				cout << "2 - ==" << endl;
				cout << "3 - +" << endl;
				cout << "4 - +=" << endl;
				cout << "5 - >=" << endl;
				cout << "6 - <=" << endl;
				cin >> gg;
				switch (gg)
				{
				case 0: break;
				case 1:
				{
					MyString a1;
					MyString a2;
					cout << "a1 = "; cin >> a1 >> a1;
					a2 = a1;
					cout << "a2 = " << a2 << endl;
					break;
				}
				case 2:
				{
					MyString a1;
					MyString a2;
					cout << "a1 = "; cin >> a1 >> a1;
					cout << "a2 = "; cin >> a2;
					if (!(a1 == a2))
						cout << "Равны!" << endl;
					else cout << "Не равны!" << endl;
					break;
				}
				case 3:
				{
					MyString a1;
					MyString a2;
					MyString a;
					cout << "a1 = "; cin >> a1 >> a1;
					cout << "a2 = "; cin >> a2;
					cout << "a1 + a2 = " << (a1 + a2) << endl;
					break;
				}
				case 4:
				{
					MyString a1;
					MyString a2;
					cout << "a1 = "; cin >> a1 >> a1;
					cout << "a2 = "; cin >> a2;
					cout << "a1 += a2 = " << (a1 += a2) << endl;
					break;
				}
				case 5:
				{
					MyString a1;
					MyString a2;
					cout << "a1 = "; cin >> a1 >> a1;
					cout << "a2 = "; cin >> a2;
					if (a1 >= a2)
						cout << a1 << " >= " << a2 << endl;
					else cout << a1 << " < " << a2 << endl;
					break;
				}
				case 6:
				{
					MyString a1;
					MyString a2;
					cout << "a1 = "; cin >> a1 >> a1;
					cout << "a2 = "; cin >> a2;
					if (a1 <= a2)
						cout << a1 << " <= " << a2 << endl;
					else cout << a1 << " > " << a2 << endl;
					break;
				}
				}
			} while (gg);
			break;
		}
		case 11:
		{
			int gg = 0;
			do
			{
				cout << "0 - выход" << endl;
				cout << "1 - =" << endl;
				cout << "2 - ==" << endl;
				cout << "3 - <=" << endl;
				cout << "4 - >=" << endl;
				cout << "5 - ++" << endl;
				cout << "6 - --" << endl;
				cout << "7 - +" << endl;
				cout << "8 - -" << endl;
				cin >> gg;
				switch (gg)
				{
				case 0:break;
				case 1:
				{
					MyDate d1;
					MyDate d2;
					cout << "d1 = "; cin >> d1;
					if (!(d1.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					d2 = d1;
					cout << "d2 = " << d2 << endl;
					break;
				}
				case 2:
				{
					MyDate d1;
					MyDate d2;
					cout << "d1 = "; cin >> d1;
					cout << "d2 = "; cin >> d2;
					if (!(d1.validate()) || !(d2.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					if (d1 == d2)
						cout << "Равны!" << endl;
					else cout << "Не равны!" << endl;
					break;
				}
				case 3:
				{
					MyDate d1;
					MyDate d2;
					cout << "d1 = "; cin >> d1;
					cout << "d2 = "; cin >> d2;
					if (!(d1.validate()) || !(d2.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					if (d1 <= d2)
						cout << d1 << " <= " << d2 << endl;
					else cout << d1 << " > " << d2 << endl;
					break;
				}
				case 4:
				{
					MyDate d1;
					MyDate d2;
					cout << "d1 = "; cin >> d1;
					cout << "d2 = "; cin >> d2;
					if (!(d1.validate()) || !(d2.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					if (d1 >= d2)
						cout << d1 << " >= " << d2 << endl;
					else cout << d1 << " < " << d2 << endl;
					break;
				}
				case 5:
				{
					MyDate d;
					cout << "d = "; cin >> d;
					if (!(d.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					d + 1; cout << d << endl; break;
				}
				case 6:
				{
					MyDate d;
					cout << "d = "; cin >> d;
					if (!(d.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					d - 1; cout << d << endl; break;
				}
				case 7:
				{
					MyDate d;
					int n = 0;
					cout << "d = "; cin >> d;
					if (!(d.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					cout << "number = "; cin >> n;
					d + n; cout << d << endl; break;
				}
				case 8:
				{
					MyDate d;
					int n = 0;
					cout << "d = "; cin >> d;
					if (!(d.validate()))
					{
						cout << "Ошибка даты!" << endl;
						break;
					}
					cout << "number = "; cin >> n;
					d - n; cout << d << endl; break;
				}
				}
			} while (gg);
			break;
		}
		}
	} while (flag);
	return 0;
}