#include<iostream>
#include<conio.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void elevator(int floor);
int factorial(int n);
double power(double a, int n);
int fib(int n);
int fib_speed(int s);

//#define RECURSION_BASICS
//#define FACTORIAL
//#define POWER

void main()
{
	setlocale(LC_ALL, "");

#ifdef RECURSION_BASICS
	system("cls");
	cout << "Hello World!\n";

	int floor;
	cout << "�� ����� �� �����?"; cin >> floor;
	elevator(floor);

	cout << "��� �������?(y/n):";
	if (_getch() == 'y')main(); //_getch() - ������� ������� �������, � ���������� ASCII-��� ������� �������
	main();
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "������� ����� ��� ���������� ����������: "; cin >> n;
	cout << "��������� ��� ����� " << n << " = " << factorial(n) << endl << endl;
	
#endif // FACTORIAL

#if POWER
	int a = 0;
	int n = 0;
	cout << "������� ��������� �������: "; cin >> n;
	cout << "������� ����� ��� ���������� ����������: "; cin >> a;
	cout << "��������� ��� ����� � ������� " << a << " = " << power(a, n) << endl << endl;
#endif // POWER

	int n = 0, h = 0, s = 0;
	cout << "������� �������� ���������� ����� ��� ���������� ����� ���������: "; cin >> n;
	cout << "������������������ ����� ���������:" << endl;
	for (int i = 0; i < n; ++i) cout << fib(i) << " | ";
	cout << endl;

	cout << "������� ������� ��� ����� ��������� �� ���������� �����: "; cin >> h;
	for (int i = 0; fib(i) < h; ++i) cout << fib(i) << " | ";
	cout << endl;

	cout << "������� ������� ������� �������� ���������� ����� ���������: "; cin >> s;
	fib_speed(s);
	cout << endl;
}

int factorial(int n)
{
	//1 ������
	/*if (n == 0) return 1;
	else return n * factorial(n - 1);*/

	//2 ������
	return n == 0 ? 1 : n * factorial(n - 1);
	
}

double power(double a, int n)
{
	//1 ������
	/*if (n == 0) return 1;
	return a * power(a, n - 1);*/

	//2 ������
	/*if (n == 0) return 1;
	if (n > 0) return a * power(a, n - 1);
	if (n < 0) return 1 / a * power(a, n + 1);*/

	//3 ������
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
	
	//4 ������
	//return (!n) ? 1 : ((n & 1) ? a : 1) * power(a * a, n / 2);
}

int fib(int n)
{
	//1 ������
	/*if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);*/

	//2 ������
	return n == 0 ? 0 : (n <= 2) ? 1 : (fib(n - 1) + fib(n - 2));
}

int fib_speed(int s)
{
	const int SIZE = 200;
	unsigned long long fibonachi[SIZE] = { 0, 1 };

	for (int i = 2; i < SIZE; i++)
		fibonachi[i] = fibonachi[i - 1] + fibonachi[i - 2];
	for (int i = 0; i < s; i++)
		cout << fibonachi[i] << " | ";
	return 0;
}

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "������ ������!" << endl;
		return;
	}
	static int counter = 0;
	cout << "�� �� " << floor << " �����" << "\t";
	cout << counter++ << endl;
	elevator(floor-1);
	cout << "�� �� " << floor << " �����" << "\t";
	cout << counter++ << endl;
}