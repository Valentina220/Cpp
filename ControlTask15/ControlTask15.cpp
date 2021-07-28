// ControlTask15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map> 
#include <Windows.h>
#include <iterator>
#include <array>

using namespace std;

struct StudentGrade
{
    string student_name;
    char grade;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    map <string, char> studentsGrade;
    map <string, char> :: iterator sg;    

    const int n = 4;
    array<StudentGrade, n> Gr;

    string user_student;
    char user_grade;

    for (int i = 0; i < n; i++) 
    {
        cout << "Введите имя студента: " << endl;
        cin >> user_student;        
        Gr[i].student_name = user_student;        
        studentsGrade[Gr[i].student_name] = ' ';
    }

    string cont;
    bool check;
    do {
        cout << "Кому хотите поставить оценку? " << endl;
        cin >> user_student;
        
        if (studentsGrade.count(user_student) != 1)
            cout << "Такого студента нет!" << endl;
        else
        {
            cout << "Введите оценку: " << endl;
            cin >> user_grade;
            studentsGrade[user_student] = user_grade;
        }
        cout << "Продолжить? (y/n): " << endl;
        cin >> cont;
        if (cont == "y")
            check = true;
        else check = false;
    } while (check);    
        
    cout << "Список студентов: " << endl;
    for (sg = studentsGrade.begin(); sg != studentsGrade.end(); sg++)
    {
        cout << sg->first << ", " << sg->second << endl;
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
