#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <locale>

using namespace std;

double first(double, int, double &);
double second(double, double, int &);

int main()
{
	setlocale(LC_ALL, "rus");
	double last, x, left, right, term, E;
	int n, q = 1;
	cout << endl << "  -------������� 4-------" << endl << endl;
	while (q != 0)
	{
		cout << "  �������� ��������:" << endl << "  1 - ������." << endl << "  0 - �����." << endl << "  ����: ";
		cin >> q;
		cout << endl;
		if (q == 1)
		{
			cout << "     �������� 1." << endl;
			cout << "  ������� x (x < -1)" << endl << "  x == ";
			cin >> x;
			cout << endl;
			if (x >= -1)
			{
				while (x >= -1)
				{
					cout << "  ������� ������������ ��������. ��������� �������." << endl << "  x == ";
					cin >> x;
					cout << endl;
				}
			}
			cout << "  ������� ��������� ��������� ������������������." << endl << "  n = ";
			cin >> n;
			cout << endl;
			if (n < 1)
			{
				while (n < 1)
				{
					cout << "  � ������������������ ������ ���� ���� �� 1 �������. ��������� �������." << endl << "  n == ";
					cin >> n;
					cout << endl;
				}
			}
			right = first(x, n, last);
			left = atan(x);
			cout << "  ������ �������� ������� == " << setprecision(10) << left << endl;
			cout << "  ��������� ����� ���� == " << right << endl;
			cout << "  ���������� ����������� == " << fabs(right - left) << endl;
			cout << "  ���������� ��������� == " << last << endl;
			cout << endl << endl;

			cout << "     �������� 2." << endl;
			cout << "  ������� x (x < -1)" << endl << "  x == ";
			cin >> x;
			cout << endl;
			if (x >= -1)
			{
				while (x >= -1)
				{
					cout << "  ������� ������������ ��������. ��������� �������." << endl << "  x == ";
					cin >> x;
					cout << endl;
				}
			}
			cout << "  ������� E" << endl << "  E == ";
			cin >> E;
			cout << endl;
			if (E < 0)
			{
				while (E < 0)
				{
					cout << "  ������� ������������ ��������. ��������� �������." << endl << "  E == ";
					cin >> E;
					cout << endl;
				}
			}
			right = second(x, E, n);
			left = atan(x);
			cout << "  ������ �������� ������� == " << setprecision(10) << left << endl;
			cout << "  ��������� ����� ���� ��� �������� �������� == " << right << endl;
			cout << "  ���������� ��������� ��� �������� E == " << n << endl;
			right = second(x, E/10, n);
			cout << "  ��������� ����� ���� ��� ��������, ����������� � 10 ��� == " << right << endl;
			cout << "  ���������� ��������� ��� �������� 10*E == " << n << endl;
			cout << endl << endl;
		}
		else if (q == 0)
		{
			return 0;
		}
		else
		{
			cout << "  ������� ������������ ��������. ����������, ���������� �����." << endl;
		}
	}
	system("pause");
	return 0;
}


double first(double x, int n, double &last)
{
	double right = -1 * asin(1);
	last = right;
	double term = x;
	int i = 1;
	for (i; i < n; ++i)
	{
		term = -1 * (term / (((2*i) - 1)*(x*x)));
		right = right + term;
		last = term;
	}
	return right;
}

double second(double x, double E, int &n)
{
	double right = -1 * asin(1);
	double last;
	last = right;
	double term = x;
	for (n=1; fabs(last) > E; ++n)
	{
		term = -1 * (term / (((2*n) - 1)*(x*x)));
		right  = right + term;
		last = term;
	}
	return right;
}