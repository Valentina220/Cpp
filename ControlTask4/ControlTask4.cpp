// ControlTask4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

int Myroot(double, double, double, double&, double&);

int Input(int& e, int& d)
{
    cout << "Введите 2 числа: \n";
    cout << "a = " << endl;
    cin >> e;
    cout << "b = " << endl;
    cin >> d;
    bool chek;
    if (e % d == 0)
    {
        chek = true;
    }
    else chek = false;

    return chek;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Задание 1. Вычисление корней квадратного уравнения

    double x1 = 0, x2 = 0;
    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения: \n";
    cout << "a = " << endl;
    cin >> a;
    cout << "b = " << endl;
    cin >> b;
    cout << "c = " << endl;
    cin >> c;

    int res = Myroot(a, b, c, x1, x2);
    
    if (res == 1)
    {
        cout << "Уравнение имеет 2 корня. х1 = " << x1 << "; x2 = " << x2 << endl;
    }
    else if (res == 0)
    {
        cout << "Уравнение имеет 1 корень. х1 = x2 = " << x1 << endl;
    }
    else
    {
        cout << "Уравнение не имеет корней." << endl;
    }


    //Задание 2. Реализация ввода данных

    int e, d;
    if (Input(e, d) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = e + d;
    cout << "s = " << s << endl;
    return 0;


    return 0;
}

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    double D = b * b - 4 * a * c;
    int r;
    if (D > 0)
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        r = 1;
    }
    else if (D == 0)
    {
        x1 = x2 = -b / (2 * a);
        r = 0;
    }
    else {
        r = -1;
    }

    return r;
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
