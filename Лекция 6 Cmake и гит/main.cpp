#include <iostream>
#include <fstream>
#include <Func.hpp>


// Процедурное программирование

// Функция
bool isPrime(int x);

// Процедура
void print10()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
    }
}

// Правила
// 1. название функции
// 2. функция выполняет одно действие
// 3. Массивы всегда передаются по ссылке
// 4. Если хотим изменить переменную, передаем ее по ссылке

int maxOfDigits(int x)
{
    int max = 0;
    while (x > 0)
    {
        if (max < x % 10)
            max = x % 10;
        x /= 10;
    }
    return max;
}

// Передача параметров в функцию: по значению и по ссылке
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//void swapSort(int mas[10], int n)
void swapSort(int* mas, int n)  // Указатель
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (mas[i] > mas[j])
                swap(mas[i], mas[j]);
}

void printMenu(int& n)
{
    std::cout << "This is menu" << std::endl;
    std::cout << "1. Press K to write something" << std::endl;
    std::cin >> n;
}

//void test(int matrix[100][100])

int main()
{
    std::ifstream in("text.txt");
    if (!in.is_open())
    {
        std::cout << "File error!" << std::endl;
        return -1;
    }
    std::string str;
    in >> str;
    std::cout << str;

    return 0;

    std::cout << mt::cout(123);

    /*int n;
    printMenu(n);
    std::cout << n;*/
    /*int mas[10] = { 6,2,3,4,6 };
    swapSort(mas, 5);
    for (int i = 0; i < 5; i++)
        std::cout << mas[i] << " ";*/
    /*int x = 123;
    std::cout << sumOfDigits(x) << std::endl;
    std::cout << x << std::endl;*/

    /*int a = 5, b = 10;
    swap(a, b);
    std::cout << a << " " << b << std::endl;*/

    /*print10();

    int n;
    std::cin >> n;

    if (isPrime(n))
        std::cout << "Prime" << std::endl;
    else
        std::cout << "Not prime" << std::endl;


    /////

    isPrime(10);*/
}

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int d = 2; d <= sqrt(x); d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}