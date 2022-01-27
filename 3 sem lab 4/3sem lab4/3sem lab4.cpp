// 3sem lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;
class xxx
{
private:
	double* a;
public:
	xxx();               //конструктор по уполчанию
	xxx(double aa, double b, double c, double d, double e, double f, double g, double h, double i, double j);
    xxx(xxx&);
	~xxx() { delete[] a; };
	friend void out(xxx& m);
	friend void add(xxx& m);
	friend void change(xxx& nl);
	friend void printf1(xxx& m);
	friend void sort(xxx& m);
	friend void summ(xxx& m, xxx *t,int jj);
	void* operator new(size_t, int);
	void operator delete(void*);
};
void* xxx::operator new(size_t tip, int n) 
{
	return new xxx[tip * n];   
}
void xxx::operator delete(void* p)  
{ 
	delete p;               
}
xxx::xxx()
{
	a = new double[10];
	a[0] = 0;  a[5] = 0;
	a[1] = 0;  a[6] = 0;
	a[2] = 0;  a[7] = 0;
	a[3] = 0;  a[8] = 0;
	a[4] = 0;  a[9] = 0;
}
xxx::xxx(double aa, double b=0, double c=0, double d=0, double e=0, double f=0, double g=0, double h=0, double i=0, double j=0)
{
	a = new double[10];
	a[0] = aa; a[5] = f;
	a[1] = b;  a[6] = g;
	a[2] = c;  a[7] = h;
	a[3] = d;  a[8] = i;
	a[4] = e;  a[9] = j;
}
xxx::xxx( xxx& klass) 
{
	std::cout << "Constr copy:" << std::endl;
	a = new double[10];
	for (int i = 0; i < 10; i++) {
		a[i] = klass.a[i];
	}

}
void out(xxx &m)
{
	cout << "\n\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "a[" << i << "] = " << m.a[i] << "   ";
	}
}
void change(xxx& nl)
{
	int i=0;
	cout << "\n\nSelect the array element for change(0-9): ";
	while (!scanf_s("%d", &i) || i < 0 || i>9)
	{
		cout << "\nERROR!!!";
		cout << "\n\nSelect the array element for change(0-9): ";
		rewind(stdin);
	}
	cout << "\nEnter the number: ";
	while (!scanf_s("%lf", &nl.a[i]))
	{
		cout << "\nERROR!!!";
		cout << "\nEnter the number: ";
		rewind(stdin);
	}
}
void printf1(xxx& m)
{
	int i = 0;
	cout << "\n\nSelect the array element to view(0-9): ";
	while (!scanf_s("%d", &i) || i < 0 || i>9)
	{
		cout << "\nERROR!!!";
		cout << "\n\nSelect the array element for change(0-9): ";
		rewind(stdin);
	}
	cout << "\n\na[" << i << "]= " << m.a[i];
}
void sort(xxx& m)
{
	double r;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (m.a[i] > m.a[j])
			{
				r = m.a[i];
				m.a[i] = m.a[j];
				m.a[j] = r;
			}
		}
	}
 }
void add(xxx& m)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\nEnter the number a["<<i<<"] = ";
		while (!scanf_s("%lf", &m.a[i]))
		{
			cout << "\nERROR!!!";
			cout << "\nEnter the number: ";
			rewind(stdin);
		}
	}
}
void summ(xxx& m, xxx *t,int jj)
{
	for (int i = 0; i < jj; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m.a[j] += t[i].a[j];
		}
	}
}
int main()
{

	int jj;
	xxx b(9,5,2,1,4,90,70),h;
	//out(h);
	
	//xxx* obj1 = new (1) xxx; 
	//add(*obj1);
	//xxx* obj2 = new (1) xxx(*obj1);
	//sort(*obj1);
	//out(*obj1);
	//out(*obj2);
	//delete[]obj1;
	//delete[]obj2;
	
	cout << "\nEnter the cout of arrays: ";
	while (!scanf_s("%d", &jj) )
	{
		cout << "\nERROR!!!";
		rewind(stdin);
	}
    xxx* obj3 = new (jj) xxx;
	for(int i=0;i<jj;i++) add(obj3[i]);
	for (int i = 0; i < jj; i++) out(obj3[i]);
	summ(h, obj3, jj);
	out(h);
	//change(obj3[2]);
	//out(obj3[0]);
	//out(obj3[1]);
	//out(obj3[2]);
	//out(obj3[3]);
	delete[]obj3;
	return 0;
}

