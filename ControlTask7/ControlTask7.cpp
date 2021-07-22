// ControlTask7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;

// ---------------- Структура Time ------------------------------------------------
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

Time InputTime()
{
    Time t;    
    cout << "Введите часы: " << endl;
    cin >> t.hours;
    cout << "Введите минуты: " << endl;
    cin >> t.minutes;
    cout << "Введите секунды: " << endl;
    cin >> t.seconds;
    return t;
}

Time Number_ofSeconds(Time& t1) 
{
    Time t;
    t.seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    cout << "Общее количесвто секунд: " << t.seconds << endl;
    return t;
}

Time Addition(const Time& t1, const Time& t2)
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

    cout << "Сложенный интервал: " << t.hours << ":" << t.minutes << ":" << t.seconds << "\n";
    return t;
}

Time Subtr(const Time& t1, const Time& t2)
{
    Time t;
    t.hours = abs(t1.hours - t2.hours);
    t.minutes = abs(t1.minutes - t2.minutes);
    t.seconds = abs(t1.seconds - t2.seconds);

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

    cout << "Вычтенный интервал: " << t.hours << ":" << t.minutes << ":" << t.seconds << "\n";
    return t;
}

void ShowTime(Time t)
{
    cout << "Введенное время: " << t.hours << ":" << t.minutes << ":" << t.seconds << "\n";
    
}

// ---------------------------------------------------------------------------------------------------



//--------------------------Квадратное ураавнение ----------------------------------------------------


struct QuadrEquation
{
    double x1;
    double x2;
};

QuadrEquation Solution(double a, double b, double c)
{
    QuadrEquation qe;  
    double d = b * b - 4 * a * c;
    int r;

    if (d > 0)
    {
        qe.x1 = (-b + sqrt(d)) / (2 * a);
        qe.x2 = (-b - sqrt(d)) / (2 * a);
        r = 1;
        cout << "Уравнение имеет 2 корня: х1 = " << qe.x1 << ", x2 = " << qe.x2 << endl;
    }
    else if ( d == 0)
    {
        qe.x1 = qe.x2 = -b / (2 * a);
        r = 0;
        cout << "Уравнение имеет 1 корень: х1 = x2 = " << qe.x1 << endl;
    }
    else
    {
        r = -1;
        cout << "Уравнение не имеет корней " << endl;
    }
    return qe;
}

void Result(QuadrEquation qe)
{
    cout << qe.x1 << ", " << qe.x2 << endl;
}

// --------------------------------------------------------------------------------------------------------------


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Задание 1. Структура Time

    Time t1 = InputTime();
    Time t2 = InputTime();   
    
    ShowTime(t1);
    Number_ofSeconds(t1);    
    ShowTime(t2); 
    Number_ofSeconds(t2);
    
    Time t3 = Addition(t1, t2);
    Time t4 = Subtr(t1, t2);

    
    // Задание 2. Решение квадратного уравнения

    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения: " << endl;
    cout << "a = : " << endl;
    cin >> a;
    cout << "b = : " << endl;
    cin >> b;
    cout << "c = : " << endl;
    cin >> c;
    QuadrEquation qe1 = Solution(a, b, c);
    Result(qe1);
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
