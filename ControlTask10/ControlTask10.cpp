// ControlTask10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <math.h>
#include <array>
#include "Dot.h"

using namespace std;


class Triangle
{
public:    
    
    Triangle() {};

    Triangle(Dot *dot1, Dot *dot2, Dot *dot3)
    {        
        this->dot1 = dot1;
        this->dot2 = dot2;
        this->dot3 = dot3;
    }
      

    double Perimetr()
    {    
       double p = dot1->distanceTo(*dot2) + dot2->distanceTo(*dot3) + dot3->distanceTo(*dot1);
       cout << "Периметр треугольника равен " << p << endl;
       return p;
    }

    double Square()
    {
        double p = dot1->distanceTo(*dot2) + dot2->distanceTo(*dot3) + dot3->distanceTo(*dot1);
        double S = sqrt(p * (p - dot1->distanceTo(*dot2)) * (p - dot2->distanceTo(*dot3)) * (p - dot3->distanceTo(*dot1)));
        cout << "Площадь треугольника равна " << S << endl;
        return S;
    }

private:    
    Dot *dot1, *dot2, *dot3;
};

class Triang
{
public:

    Triang() {};

    Triang(Dot dot1, Dot dot2, Dot dot3)
    {
        this->dot1 = dot1;
        this->dot2 = dot2;
        this->dot3 = dot3;
    }

    double Perimetr()
    {
        double p = dot1.distanceTo(dot2) + dot2.distanceTo(dot3) + dot3.distanceTo(dot1);
        cout << "Периметр треугольника равен " << p << endl;
        return p;
    }

    double Square()
    {
        double p = dot1.distanceTo(dot2) + dot2.distanceTo(dot3) + dot3.distanceTo(dot1);
        double S = sqrt(p * (p - dot1.distanceTo(dot2)) * (p - dot2.distanceTo(dot3)) * (p - dot3.distanceTo(dot1)));
        cout << "Площадь треугольника равна " << S << endl;
        return S;
    }


private:

    /*class Point
    {
    public:
        Point()
        {
            x = 0; y = 0;
        }
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        double DistanceTo(Point point1, Point point2)
        {
            return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
        }
    private:
        double x, y;
    };

    Point point1, point2, point3;*/
    Dot dot1, dot2, dot3;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
   //double x, y;
   // //double a, b, c;
   // cout << "Введите координаты точек" << endl;
   // cout << "Координаты первой точки: " << endl;
   // cout << "x = " << endl;
   // cin >> x;
   // cout << "y = " << endl;
   // cin >> y;
   // Dot* d1 = new Dot(x, y);
   // cout << "Координаты второй точки: " << endl;
   // cout << "x = " << endl;
   // cin >> x;
   // cout << "y = " << endl;
   // cin >> y;
   // Dot* d2 = new Dot(x, y);
   // cout << "Координаты третьей точки: " << endl;
   // cout << "x = " << endl;
   // cin >> x;
   // cout << "y = " << endl;
   // cin >> y;
   // Dot* d3 = new Dot(x, y);
   ///* for (int i = 0; i < 3; i++)
   // {
   //     cout << "Координата " << i + 1 << " точки: " << endl;
   //     cin >> x;
   //     cin >> y;
   //     Dot d[i] = new Dot(x, y);        
   // }*/
   // Triangle* tr = new Triangle(*d1, *d2, *d3);    
   // tr->Perimetr();
   // tr->Square();
   // return 0;
    array<Dot, 3> d;


    for (int i = 0; i < 3; i++)
    {
        cout << "Координаты " << i + 1 << " точки: " << endl;
        double x, y;
        cout << "x = " << endl;
        cin >> x;
        cout << "y = " << endl;
        cin >> y;
        d[i] = Dot(x, y);    }

    Triangle* tr = new Triangle(&d[0], &d[1], &d[2]);
    
    tr->Perimetr();
    tr->Square();

    array<Dot, 3> d1;

    for (int i = 0; i < 3; i++)
    {
        cout << "Координаты " << i + 1 << " точки: " << endl;
        double x, y;
        cout << "x = " << endl;
        cin >> x;
        cout << "y = " << endl;
        cin >> y;
        d[i] = Dot(x, y);
    }
    Triang* tr1 = new Triang(d[0], d[1], d[2]);

    tr1->Perimetr();
    tr1->Square();

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
