// ControlTask5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

void Array_proc(int mas[], const int n) {
    int s = 0;
    int neg = 0;
    int pos = 0;
    int even = 0;
    int odd = 0;
    double avg = 0;
    int min = 0, max = 0, min_ind = 0, max_ind = 0;;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
        if (mas[i] < 0) {
            neg += mas[i];
        }
        else {
            pos += mas[i];
        }

        if (i % 2 == 0)
        {
            even += mas[i];
        }
        else {
            odd += mas[i];
        }

        if (mas[i] < min) {
            min = mas[i];
            min_ind = i;
        }

        if (mas[i] > max) {
            max = mas[i];
            max_ind = i;
        }
    }
    avg = s / 2;

    cout << "Сумма элементов массива s = " << s << endl << "Среднее зчаение элементов массива: " << avg << endl;
    cout << "Сумма отрицательных элементов массива: " << neg << endl << "Сумма положительных элементов массива: " << pos << endl;
    cout << "Сумма элементов массива с четными индексами: " << even << endl << "Сумма элементов массива с нечетными индексами: " << odd << endl;
    cout << "Максимальный элемент массива имеет индекс i = " << max_ind << endl;
    cout << "Минимальный элемент массива имеет индекс i = " << min_ind << endl;
}

void Array_Sort(int a[], int k) {
    int min = 0; 
    int buf = 0; 

    for (int i = 0; i < k; i++)
    {
        min = i; 
        for (int j = i + 1; j < k; j++)
            min = (a[j] < a[min]) ? j : min;       
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << endl;        
    }
        
}

int *max_vect(int kc, int c[], int d[]) {
    int* z = new int[kc];
    for (int i = 0; i < kc; i++)
    {
        z[i] = c[i] > d[i] ? c[i] : d[i];
    } 
    return z;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout.precision(3);

    //Задание 1. Передача массива в функци

    int n;
    cout << "Введите размер массива n: " << endl;
    cin >> n;
    //const int n = 10;
    //int mas[n];
    int* mas = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    
    Array_proc(mas, n);

    const int k = 10;
    int a[k] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    Array_Sort(a, k);


    // Задание 2. Возврат массива из функции


    int c[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(c) / sizeof(c[0]); //Количество элементов массива
    int* d; //Указатель на результирующий массив
    d = max_vect(kc, c, b); //вызов функции для создания массива

    
    for (int i = 0; i < kc; i++) //Вывод результата.
        cout << d[i] << " ";
    cout << endl;
    delete[]d; //Возврат памяти.
    
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
