// ControlTask11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
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
		cout << "Введенное время " << hours << ":" << minutes << ":" << seconds << endl;
	}

	/*Time addTime(const Time& t1, const Time& t2)
	{
		Time t;
		t.hours = t1.hours + t2.hours;
		t.minutes = t1.minutes + t2.minutes;
		t.seconds = t1.seconds + t2.seconds;

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
	}*/

	Time operator+ (const Time&) const;
	Time operator- (const Time&) const;
	friend Time operator+ (const Time& t, double x);	
	friend Time operator+ (double x, const Time& t);
	friend bool operator> (const Time& t1, const Time& t2);
	
};

Time operator+ (const Time& t, double x)
{	
	int h = int(x);
	int min = 60 * (x - h);
	int sec = min - 60 * (x - h);

	int new_hours = h + t.hours;
	int new_min = min + t.minutes;
	int new_sec = sec + t.seconds;

	if (new_sec >= 60)
	{
		new_min += new_sec / 60;
		new_sec -= new_sec / 60 * 60;
	}

	if (new_min >= 60)
	{
		new_hours += new_min / 60;
		new_min -= new_min / 60 * 60;
	}

	return Time(new_hours, new_min, new_sec);
}

Time operator+  (double x, const Time& t)
{	
	int h = int(x);
	int min = 60 * (x - h);
	int sec = min - 60 * (x - h);

	int new_hours = h + t.hours;
	int new_min = min + t.minutes;
	int new_sec = sec + t.seconds;

	if (new_sec >= 60)
	{
		new_min += new_sec / 60;
		new_sec -= new_sec / 60 * 60;
	}

	if (new_min >= 60)
	{
		new_hours += new_min / 60;
		new_min -= new_min / 60 * 60;
	}

	return Time(new_hours, new_min, new_sec);
}

Time Time::operator+ (const Time& t2) const
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

Time Time::operator- (const Time& t2) const
{
	int h = abs(hours - t2.hours);
	int min = abs(minutes - t2.minutes);
	int sec = abs(seconds - t2.seconds);
	if (sec >= 60)
	{
		min += sec / 60;
		sec -= sec / 60 * 60;
	}

	if (min >= 60)
	{
		h += min / 60;
		min -= min / 60 * 60;
	}

	return Time(h, min, sec);
}

bool operator> (const Time& t1, const Time& t2)
{
	return t1.hours > t2.hours;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	double x = 2.8;
	int hours, minutes, seconds;

	cout << "Введите время: " << endl;
	cout << "Часы: " << endl;
	cin >> hours;
	cout << "Минуты: " << endl;
	cin >> minutes;
	cout << "Секунды: " << endl;
	cin >> seconds;

	Time* time1 = new Time(hours, minutes, seconds);
	Time time2(6, 45, 50);
	Time time3, time4, time5, time6;	
	time3 = *time1 + time2;
	time4 = *time1 - time2;
	time5 = *time1 + x;
	time6 = x + time2;

	time1->showTime();
	time2.showTime();
	cout << "Перегрузка оператора сложения:" << endl;
	time3.showTime();
	cout << "Перегрузка оператора вычитания:" << endl;
	time4.showTime();
	cout << "Сложение типа time и вещественного числа:" << endl;
	time5.showTime();
	cout << "Сложение вещественного числа и типа timе:" << endl;
	time6.showTime();

	if (*time1 > time2)
		cout << "Первое время больше второго" << endl;
	else cout << "Первое время меньше второго" << endl;

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
