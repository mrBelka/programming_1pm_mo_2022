#include <iostream>

#include <math.h>
using namespace std;

// 1
using std::cin;
using std::cout;

// pow(x,y)
// sqrt(x)
// sin(rad)
// cos(rad)
// acos(x)

// число PI
//#define PI acos(-1) // PI - константа
const double PI = acos(-1);

// XCode, CLion
// виртуальная машина Virtual Box, Parellels
// 16Гб, 30Гб

int x = 256;

int main()
{
    // 2.
    std::cout << "Hello World!\n";

    // Тип данных bool
    bool flag = true;
    bool flag1 = false; // 1 байт, true (1), false (0)

    // Логические операторы
    // ! - НЕ
    // || - ИЛИ (or)
    // && - И (and)

    std::cout << !flag << std::endl;
    std::cout << (flag || flag1) << std::endl << "\n";
    std::cout << (flag && flag1) << std::endl;

    // Битовые операции
    // | - битовая ИЛИ
    int a = 0b1101; // 13
    int b = 0b1000; // 8
    std::cout << (a | b) << std::endl; // 0b1101
    std::cout << (a & b) << std::endl; // 0b0000
    std::cout << ~a << std::endl;   // битовая инверсия
    std::cout << (10 << 2) << std::endl; // 10*(2^2)
    std::cout << (10 >> 2) << std::endl; // 10 / (2^2)

    // Операторы сравнения
    // <, >, <=, >=, ==, !=
    int cnt = 10;
    std::cout << "cnt > 5 " << (cnt > 5) << std::endl;
    bool res = (cnt > 5);

    // Условия
    // if, if..else
    if (cnt == 10)
        std::cout << "CNT == 10" << std::endl;

    if (cnt == 10) 
    {
        std::cout << "1" << std::endl;
        std::cout << "2" << std::endl;
    }

    if (cnt > 10)
    {
        std::cout << "First block";
    }
    else
    {
        std::cout << "Second block";
    }

    if (cnt < 2)
    {

    }
    else if (cnt == 4)
    {

    }
    else
    {

    }

    if(cnt < 2)
        if (cnt > 10)
        {

        }

    if (cnt < 2 || cnt > 10)
    {

    }

    // 
    if (cnt == 1)
    {
        std::cout << "One";
    }
    else if (cnt == 2)
    {
        std::cout << "Two";
    }
    else if (cnt == 3)
    {
        std::cout << "Three";
    }

    // Switch
    switch (cnt)
    {
    case 0: std::cout << "Zero";
        break;
    case 1: std::cout << "One";
        break;
    case 2:
    case 3: std::cout << "Two or Three";
        break;
    default: std::cout << "default";
    }

    // Тернарный
    std::cout << (cnt > 2 ? "True" : "False") << std::endl;

    // Область видимости переменной: глобальная и локальная
    std::cout << x << std::endl;

    int x = 10;

    std::cout << x << std::endl;

    if (cnt > 2)
    {
        int y = 100;
    }

    //std::cout << y << std::endl;

    // Циклы
    int i = 0;          // Итератор, счетчик
    while (i < 10)      // Условие, до которого будет выполняться цикл
    {
        std::cout << i << std::endl;
        i++;            // Увеличение/уменьшение счетчика
    }

    // i++ - инкремент, i-- - декремент
    // i = i + 1, i += 1, i = i - 1, i-=1
    int j = 0;
    //int k = j++;        // Постфиксный инкремент
    int k = ++j;        // Префиксный инкремент
    std:: cout << "k = " << k << std::endl;

    j = 10;
    while (j > 0)
    {
        std::cout << j << std::endl;
        j--;
    }

    // do while используется, когда цикл должен выполниться хотя бы 1 раз
    j = 0;      // Счетчик
    do
    {
        std::cout << j << std::endl;
        j++; // Увеличение счетчика
    } while (j < 10);   // Условие

    // счетчик; условие; изменение счетчика
    for (int j = 0; j < 10; j++)
    {
        std::cout << j << std::endl;
    }

    // continue - завершить цикл и перейти на новую итерацию
    int sum = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i % 2 != 0)
            continue;
        std::cout << i << std::endl;
        sum += i;
    }

    /*int sum = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << i << std::endl;
            sum += i;
        }
    }*/

    // break
    // Поиск числа в последовательности, с которого сумма s > 1000
    int s = 0;
    for (int i = 1; i < 10000; i++)
    {
        s += i;
        if (s > 1000)
            break;
    }

    // Алгоритм поиска натур. числа https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D1%81%D1%82%D0%BE%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%BE
    {
        //...
    }

    int sumOfDigits = 0; // lower camel-case
    int SumOfDigits = 0; // upper camel-case
    int sum_of_digits = 0;
    int sumofdigits = 0;
}