// ControlTask11.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm> 

using namespace std;

class Point
{
private:
    double x, y;

public:

    Point() : x(0), y(0) {}

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    
    double Dist_toCenter() const
    {
        return sqrt(pow(x - 0, 2) + pow(y - 0, 2));
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& p);

    //friend bool operator> (const Point& p1);

    bool operator> (const Point& p1)
    {
        if (this->Dist_toCenter() > p1.Dist_toCenter())
            return true;
        else
            return false;        
    }

    bool operator< (const Point& p1)
    {
        if (this->Dist_toCenter() < p1.Dist_toCenter())
            return true;
        else
            return false;        
    }
};

std::ostream& operator<< (std::ostream& out, const Point& p)
{
    out << "( " << p.x << "; " << p.y << " )" << "\n";
    return out;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    sort(v.begin(), v.end()); 

    for (auto& point : v)
        cout << point << '\n';
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
