// подключить библиотеку iostream (input output stream)
#include <iostream>

// Плохая практика
using namespace std;

// Использование из пространства std только функцию cout
using std::cout;

// точка входа в программу 
int main()
{
    // Вывод на экран
    // std:: - пространство имен
    // \n - перенос строки
    cout << "Hello World!\n";

    // Переменная
    int x = 10;  // целое число 4 байта (-2^31 .. 0 .. 2^31-1)
    char y = 1;  // целое число 1 байт (-128 .. 127)
    short z = 1; // целое число 2 байта (-65536 .. 65535)
    long long xx = 2; // целое число 8 байт (-2^63 .. 2^63-1)
    unsigned int yy = 10; // неотрицательные целые числа (0..2^32)
    float f = 1;   // вещественное число одинарной точности (4 байта)
    // 3.141592
    double d = 3.141592123567; // 13-14 знаков после запятой (8 байт)
    char c = 'a'; // ascii-таблица
    char r = 97;

    // Арифметические действия
    // +, -, *, /, %
    int a = 11;
    int b = 2;
    // возведение в степень pow(x,y)
    // sqrt(a)
    std::cout << a / b << std::endl;

    float aa = 11;
    float bb = 2;
    std::cout << aa / bb << std::endl;

    int k;
    std::cin >> k;
    std::cout << k * k << std::endl;

    std::cout << sqrt(k) << " " << pow(k,0.5) << std::endl;
}