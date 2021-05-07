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
unsigned long long int fib_speed(int s);
void Fibonacci1(int n, unsigned long long int a = 0, unsigned long long int b = 1);
void Fibonacci2(int n, unsigned long long int a = 0, unsigned long long int b = 1);

//#define RECURSION_BASICS
//#define FACTORIAL
//#define POWER
//#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");

#ifdef RECURSION_BASICS
	system("cls");
	cout << "Hello World!\n";

	int floor;
	cout << "На каком вы этаже?"; cin >> floor;
	elevator(floor);

	cout << "Еще разочек?(y/n):";
	if (_getch() == 'y')main(); //_getch() - ожидает нажатие клавиши, и возвращает ASCII-код нажатой клавиши
	main();
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	cout << "Факториал для числа " << n << " = " << factorial(n) << endl << endl;
	
#endif // FACTORIAL

#if POWER
	int a = 0;
	int n = 0;
	cout << "Введите основание степени: "; cin >> n;
	cout << "Введите число для вычисления факториала: "; cin >> a;
	cout << "Факториал для числа в степени " << a << " = " << power(a, n) << endl << endl;
#endif // POWER

#if HOME_WORK
	int n = 0, h = 0, s = 0;
	cout << "Введите заданное количество чисел для вычисления числа Фибоначчи: "; cin >> n;
	cout << "Последовательность числа Фибоначчи:" << endl;
	for (int i = 0; i < n; ++i) cout << i << ": " << fib(i) << endl;
	cout << endl;

	cout << "Функция выведет ряд чисел Фибоначчи до указанного числа: "; cin >> h;
	for (int i = 0; fib(i) < h; ++i) cout << fib(i) << " | ";
	cout << endl << endl;

	cout << "Быстрая функция выведет заданное количество чисел Фибоначчи: "; cin >> s;
	//fib_speed(s);
	for (int i = 0; i < s; ++i) cout << i << ": " << fib_speed(i) << endl;
	cout << endl;
#endif // HOME_WORK

	int n;
	//cout << "Введите значение, до которого нужно вывести ряд Фибоначчи: "; cin >> n;
	//Fibonacci1(n);
	cout << "Сколько чисел из ряда Фибоначчи нужно вывести: "; cin >> n;
	Fibonacci2(n);
}

int factorial(int n)
{
	//1 способ
	/*if (n == 0) return 1;
	else return n * factorial(n - 1);*/

	//2 способ
	return n == 0 ? 1 : n * factorial(n - 1);
	
}

double power(double a, int n)
{
	//1 способ
	/*if (n == 0) return 1;
	return a * power(a, n - 1);*/

	//2 способ
	/*if (n == 0) return 1;
	if (n > 0) return a * power(a, n - 1);
	if (n < 0) return 1 / a * power(a, n + 1);*/

	//3 способ
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
	
	//4 способ
	//return (!n) ? 1 : ((n & 1) ? a : 1) * power(a * a, n / 2);
}

int fib(int n)
{
	//1 способ
	/*if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return fib(n - 1) + fib(n - 2);*/

	//2 способ
	//return n == 0 ? 0 : (n <= 2) ? 1 : (fib(n - 1) + fib(n - 2));

	//3 способ
	return n < 2 ? n : fib(n - 2) + fib(n - 1);
}

unsigned long long int fib_speed(int s)
{
	/*const int SIZE = 200;
	unsigned long long int fibonachi[SIZE] = { 0, 1 };

	for (int i = 2; i < SIZE; i++)
		fibonachi[i] = fibonachi[i - 1] + fibonachi[i - 2];
	for (int i = 0; i < s; i++)
		cout << fibonachi[i] << " | ";
	return 0;*/

	//Числа Фибоначчи итерация
	unsigned long long int c = 0;
	unsigned long long int a = 1;
	unsigned long long int b = 1;
	for (int i = 0; i < s; i++)
	{
		if (i < 2) c = 1;
		else if(s >= 2)
		{
		c = a + b;
		a = b;
		b = c;
		}
	}
	return c;
}

void Fibonacci1(int n, unsigned long long int a, unsigned long long int b)
{
	//Выводит числа Фибоначчи, до заданного предела
	if (a > n) return;
	cout << a << '\t';
	Fibonacci1(n, b, a + b);
}

void Fibonacci2(int n, unsigned long long int a, unsigned long long int b)
{
	//Выводит заданное количество чисел из ряда Фибоначчи
	if (n == 0) return;
	cout << a << '\t';
	Fibonacci2(n-1, b, a + b);
}

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Привет подвал!" << endl;
		return;
	}
	static int counter = 0;
	cout << "Мы на " << floor << " этаже" << "\t";
	cout << counter++ << endl;
	elevator(floor-1);
	cout << "Мы на " << floor << " этаже" << "\t";
	cout << counter++ << endl;
}