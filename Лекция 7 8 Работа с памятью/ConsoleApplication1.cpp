#include <iostream>
#include <chrono>
#include <thread>

void swap(int& a, int& b)
{
    std::cout << &a << " " << &b << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}

/*void swap(char* a, int* b)
{
    std::cout << a << " " << b << std::endl;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}*/

// static_cast,   float p = (float)1/2; c-style
// float p = static_cast<float>(1)/2; c++
// reinterpret_cast

int main()
{
    int t;
    std::cin >> t;
    int mmmm[1000];


    int n = 3;
    int m = 5;
    int** mas = new int* [n];
    for (int i = 0; i < n; i++)
        mas[i] = new int[m];

    mas[0][1];

    for (int i = 0; i < n; i++)
        delete[] mas[i];
    delete[] mas;



    /*for (int i = 0; i < 1000; i++)
    {
        int* m = new int[100000000]; // 4Мб
        std::this_thread::sleep_for(std::chrono::microseconds(2000));
        delete[] m;
        std::this_thread::sleep_for(std::chrono::microseconds(2000));
    }*/


    // стек, разместить переменную на стеке, фиксированная, место резервируется при запуске
    // хип (heap) == куча, динамическая, место может быть 
    // получено/расширено в процессе работы программы

    // стек
    {
        int a = 5; // оперативная память освобождает автоматически
    }
    int mas[10000]; // 1, 10, 100

    // хип
    {
        int n;
        std::cin >> n;
        int* m = new int[n]; // создать 10000 переменных типа int и сохранить адрес
                                // первой из них в переменной int* m
        // ....
        delete[] m; // помечает ячейки памяти как неиспользуемые

        // malloc = memory allocate
        // free
    }

    // Проблемы:
    // 1. Затраты по времени на выделение памяти
    // 2. Очистка памяти вручную (сборщик мусора)




    /*int n = 10;
    int& tmp = n;       // Занимает ли int& tmp место в памяти???
    std::cout << &tmp << " " << &n << std::endl;
    tmp = tmp + 5;
    std::cout << tmp << " " << sizeof(tmp) << std::endl;


    int A = 10;
    int B = 5;
    std::cout << &A << " " << &B << std::endl;
    swap(A, B);*/

    /*int* p; // pointer
    int x = 10; // создана на стеке
    p = &x; // & - взятие адреса
    std::cout << p << std::endl;  // в переменной p хранится адрес переменной х
    std::cout << *p << std::endl; // получить значение по адресу (разыменование)*/

    /*double mas[10] = { 1,2,3,4 };
    std::cout << mas << std::endl;
    std::cout << mas + 1 << std::endl;
    std::cout << *(mas + 1) << std::endl;
    std::cout << mas[1] << std::endl;*/

    /*unsigned char mas[4] = { 232, 3, 0, 0 }; // LSB

    int y = mas[0] + mas[1] * 256 + mas[2] * 256 * 256 + mas[3] * 256 * 256 * 256;

    int x = *((int*)mas);

    // int* - "переменная, которая хранит адреc" <=> указатель
    // *x - разыменовать указатель, по адресу получить значение
    // 
    std::cout << x << std::endl;


    int testtesttest = 10;
    int& a = testtesttest;
    a = 16;
    std::cout << &a << " " << &testtesttest << std::endl;
    std::cout << a << " " << testtesttest << std::endl;*/

}