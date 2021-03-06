// ControlTask2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Високосный год 

	int year;
	cout << "Введите год для проверки: \n";
	cin >> year;

	if (year % 4 == 0 or (year % 100 == 0 and year % 400 == 0))
	{
		cout << year << " год високосный \n";
	}
	else
	{
		cout << year << " год не високосный \n";
	}


	// Наибольшее число

	double a, b, c, max;

	cout << "Введите 3 числа для сравнения: \n";
	cin >> a;
	cin >> b;
	cin >> c;

	max = a;

	if (b > a and b > c)
	{
		max = b;
	}
	else {
		if (c > a and c > b) 
		{
			max = c;
		}
	}

	cout << "Наибольшее число " << max << "\n";

	// Размен монет

	int cash;
	cout << "Какую сумму выдать? \n ";
	cin >> cash;
	int hundreds = cash / 100;
	int halfHundr = (cash % 100) / 50;
	int tenner = ((cash % 100) - halfHundr * 50) / 10;
	int five_coin = (cash % 10) / 5 ;
	int two_coin = ((cash % 10) - 5 * five_coin) / 2;
	int one_coin = (cash % 10) - 5 * five_coin - 2 * two_coin;	
	
	cout << "Ваша сумма будет выдана: \n";
	cout << "\t" << "сотнями: " << "\t" << hundreds * 100 << " рублей" << endl << "\t" << "полтинниками: " << "\t" << halfHundr * 50 << " рублей" << endl << "\t" << "десятками: " << "\t" << tenner * 10 << " рублей" << endl << "\t" << "пятаками: " << "\t" << five_coin * 5 << " рублей" << endl << "\t" << "двушками: " << "\t" << two_coin * 2 << " рубля" << endl << "\t" << "по 1 рублю: " << "\t" << one_coin << " рубль" << endl;


	// Стрельба по мишени
	
	double score = 0;
	int i = 1;
	int count = 0;
	double x, y;

	cout << "Введите координаты точек попадания в мишень: \n";
	do
	{
		cout << "Выстрел " << i  << endl;
		cin >> x;
		cin >> y;

		if (x * x + y * y <= 1)
		{
			score += 10;
		}
		else if (x * x + y * y > 1 && x * x + y * y <= 4)
		{
			score += 5;
		}
		else {
			score += 0;
		}

		i++;
		count++;

	} 	while (score < 50);

	if (count == 5)
	{
		cout << "Вы снайпер!! Вы набрали " << score << " очков за " << count << " выстрелов" << endl;
	}
	else if (count > 5 and count <= 9)
	{
		cout << "Вы стрелок-любитель. Вы набрали " << score << " очков за" << count << " выстрелов" << endl;
	}
	else
	{
		cout << "Вы новичок. Вы набрали " << score << " очков за" << count << " выстрелов" << endl;
	}	

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
