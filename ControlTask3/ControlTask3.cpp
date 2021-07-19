// ControlTask3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <math.h>
#include <string>
using namespace std;

double getSide(double x1, double x2, double y1, double y2)
{
    double side = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return side;
}

double getSquare(double side1, double side2, double side3)
{
    double p = (side1 + side2 + side3) / 2;
    double S = sqrt(p * (p - side1) * (p - side2) * (p - side3));
    return S;
}

double cube_root(double a)
{
    double r = pow(a, 1.0 / 3);
    return r;
}

double cube_root(double a, double xi, double xi1)
{

    while (true)
    {
        xi1 = 1.0 / 3 * (a / (xi * xi) + 2.0 * xi); // итерационная формула вычисления корня кубического

        if (abs(xi1 - xi) < pow(10.0, -5.0)) // условие окончание итерации
            break; // выход из цикла

        xi = xi1; // сохраняем текущее значение y
    } 

    return xi;
}

double triangleSquare(double a)
{
    double S = (a * a * pow(3, 0.5)) / 4;
    return S;
}

double triangleSquare(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
}

double sum_ofSeries(int n)
{
    if (n == 1) return 5; // выход из рекурсии
    else return (5 * n + sum_ofSeries(n - 1));
}

string convert_toBinary(int num)
{
    string bin = "";
    int quot = num / 2;
    int mod = num % 2;
    bin += to_string(mod);
    if (num == 1) return "1"; // выход из рекурсии    
    else return (convert_toBinary(quot) + bin);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout.precision(2);

    // Задание 1. Расчет площади сложной фигуры

    double X[5];
    double Y[5];
    double tr_side[7];

    cout << "Введите вершины пятиугольника:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Вершина " << i + 1 << "\n";

        cin >> X[i];
        cin >> Y[i];
    }    

    /*for (int i = 0; i < 5; i++)
    {
        cout << "\t" << X[i] << "\t" << Y[i] << endl;
    }*/

    for (int i = 1; i < 5; i++)
    {
        tr_side[i-1] = getSide(X[i], X[0], Y[i], Y[0]);
        //cout << tr_side[i - 1] << endl;
    }

    tr_side[4] = getSide(X[2], X[1], Y[2], Y[1]);
    tr_side[5] = getSide(X[3], X[2], Y[3], Y[2]);
    tr_side[6] = getSide(X[4], X[3], Y[4], Y[3]);

    for (int i = 0; i < 7; i++)
    {
        cout << tr_side[i] << endl;
    }
   
    double triangle1 = getSquare(tr_side[0], tr_side[1], tr_side[4]);
    double triangle2 = getSquare(tr_side[1], tr_side[2], tr_side[5]);
    double triangle3 = getSquare(tr_side[2], tr_side[3], tr_side[6]);

    double Square = triangle1 + triangle2 + triangle3;

    cout << Square << endl;


    //Задание 2. Применение итерации реализации функции

    double a;
    cout << "Введите число для извлечения кубического корня:\n";
    cin >> a;

    double xi = a, xi1 = 0;

    double root1 = cube_root(a);
    double root2 = cube_root(a, xi, xi1);    

    cout << "Корень, вычесленный первым способом: " << root1 << endl;
    cout << "Корень, вычесленный вторым способом: " << root2 << endl;


    //Задание 3. Работа с различными треугольниками

    string ans;
    double e, b, c, d;

    cout << "Вы хотите посчитать площадь треугольника. Этот треугольник равносторонний? \n";
    cin >> ans;

    if (ans == "да" or ans == "yes" or ans == "y")
    {
        cout << "Введите сторону треугольника: \n" << endl;
        cin >> e;
        double tr1 = triangleSquare(e);
        cout << "Площадь даного треугольника: " << tr1 << endl;
    }
    else {
        cout << "Введите три стороны треугольника: \n" << endl;
        cin >> b;
        cin >> c;
        cin >> d;
        double tr2 = triangleSquare(b, c, d);
        cout << "Площадь даного треугольника: " << tr2 << endl;

    }


    // Задание 4. Рекурсивная функция суммы ряда

    int n;
    cout << "Введите количество членов ряда: \n" << endl;
    cin >> n;

    double sum = sum_ofSeries(n);
    cout << "Сумма членов ряда равна: " << sum << endl;


    // Задание 5. Применение рекурсии для перевода целого числа в двоичный код
    int num;
    cout << "введите десятичное число для перевода в двоичную систему: \n" << endl;
    cin >> num;

    /*int quot = num / 2;
    int mod = num % 2;*/

    //cout << quot << "\t" << mod << endl;

    string binary = convert_toBinary(num);
    cout << "Ваше число в двоичной системе: " << binary << endl;

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
