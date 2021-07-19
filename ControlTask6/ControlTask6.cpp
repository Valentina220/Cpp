// ControlTask6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Задание 1. Запись текста в файл

    char str[500];
    cout << "Напишите стихотворение. Когда закончите, нажмите '@': ";
    cin.getline(str, 500, '@');
    //getch(str);

   
    ofstream out("poem", ios::out | ios::binary);
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }

    out.write((char*)str, sizeof(str));
    out.close();

    ifstream in("poem", ios::in | ios::binary);
    if (!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }
    in.read((char*)&str, sizeof(str));
       
    cout << "\nВаше стихотворение: " << str << endl;
    in.close();

    //Задание 2. Сохранение данных в текстовый файл

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; 
    int buf = 0; 

    ofstream fout;
    fout.open("E:\\Array.txt", ofstream::out);

    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        //cout << "Файл открыт!" << endl;
        for (int i = 0; i < N; i++)
        {
            fout << a[i] << "; ";
        }
        
    }

    fout.close();    

    for (int i = 0; i < N; i++)
    {
        min = i; 
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;        
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    fout.open("E:\\Array.txt", ofstream::app);

    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        //cout << "Файл открыт!" << endl;
        fout << "Отсортированный массив: ";
        for (int i = 0; i < N; i++)
        {
            fout << a[i] << " ";
        }        
    }

    fout.close();
        
    ifstream fin;
    fin.open("E:\\Array.txt");

    if (!fin.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        cout << "Файл открыт!" << endl;
        char ch;
        while (fin.get(ch))
        {
            cout << ch << " ";
        }
        
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
