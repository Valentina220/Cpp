// ControlTask8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Time
{
public:

	Time() : hours(0), minutes(0), seconds(0) {}
	
	Time(int hours, int minutes, int seconds)
	{
		if (seconds >= 60)
		{
			minutes += seconds / 60;
			seconds -= seconds / 60 * 60;			
		}

		if (minutes >= 60)
		{
			hours += minutes / 60;
			minutes -= minutes / 60 * 60;			
		}
		set_hours(hours);
		set_minutes(minutes);
		set_seconds(seconds);
		
	}
	
	~Time() {}
	
	void set_hours(int hours)
	{
		this->hours = hours;
	}
	
	int get_hours()
	{
		return hours;
	}

	void set_minutes(int minutes)
	{
		this->minutes = minutes;
	}

	int get_minutes()
	{
		return minutes;
	}
	
	void set_seconds(int seconds)
	{
		this->seconds = seconds; 
	}
	
	int get_seconds()
	{
		return seconds;
	}	

	void showTime()
	{
		cout << "Введенное время " << hours << ":" << minutes <<":" << seconds << endl;
	}

	Time addTime(const Time& t2)
	{
		Time t;
		t.hours = hours + t2.hours;
		t.minutes = minutes + t2.minutes;
		t.seconds = seconds + t2.seconds;

		if (t.seconds >= 60)
		{
			t.minutes += t.seconds / 60;
			t.seconds -= t.seconds / 60 * 60;
		}

		if (t.minutes >= 60)
		{
			t.hours += t.minutes / 60;
			t.minutes -= t.minutes / 60 * 60;
		}		
		return t;			
	}

private:
	int hours; 
	int minutes;
	int seconds;
};


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);	

	int hours;
	int minutes;
	int seconds;
	
	cout << "Часы: " << endl;
	cin >> hours;
	cout << "Минуты: " << endl;
	cin >> minutes;
	cout << "Секунды: " << endl;
	cin >> seconds;


	Time* time1 = new Time(hours, minutes, seconds);
	Time time2(4,45,35);
	Time time3;	
	
	time1->showTime();
	time2.showTime();	
	time3=time1->addTime(time2);	
	time3.showTime();

	delete time1, time2, time3;
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
