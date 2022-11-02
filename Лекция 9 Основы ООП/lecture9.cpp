#include <iostream>
#define N 10

// Объектно-ориентированное программирование
// Структура. Основное назначение - хранение сложных типов данных
struct Person
{
    int age;
    std::string name;
    std::string surname;
};

// Класс. Хранение данных и операции над ними
class Car
{
private:
    // 1 принцип: Абстракция - от реального объекта берем минимальный набор параметров,
    // необходимых для решения задачи
    double m_acceleration = 0;
    std::string m_model = "";
    double m_maxVelocity = 0;
    double m_x = 0;
    double m_raduisOfWheel = 0;

// 2 принцип: Инкапсуляция - разграничение доступа к полям и методам класса
public:
    // Конструктор
    Car(double acceleration, std::string model, double maxVelocity)
    {
        std::cout << "Constructor works!" << std::endl;
        m_acceleration = acceleration;
        m_model = model;
        m_maxVelocity = maxVelocity;
        m_x = 0;
    }

    // Деструктор
    ~Car() 
    {
        std::cout << "Destructor works!" << std::endl;
    }

    void Move(double dx)
    {
        m_x += dx;
    }

    // Геттер
    double Position()
    {
        return m_x;
    }

    // Сеттер
    bool SetRadiusOfWheel(int radius)
    {
        if (radius <= 0)
        {
            std::cout << "Error in radius of wheel" << std::endl;
            return false;
        }
        m_raduisOfWheel = radius;
    }

    double Circumference()
    {
        return 2 * acos(-1) * m_raduisOfWheel;
    }

private:
    int m_y = 0;

private:
    void sum() {}
};

// ООП
// 1. Структурирование кода
// 2. Упрощается написание кода

// Сложный тип данных
int age[N];
std::string name[N];
std::string surname[N];

Person addPerson()
{
    Person person;
    person.age = 18;

    return person;
}

int main()
{
    // Тип данных Car
    // Создает объекта car1
    // Передаются его параметры
    Car car1(3, "Tesla", 150);
    car1.SetRadiusOfWheel(100);
    std::cout << car1.Position() << std::endl;

    car1.Move(10);

    std::cout << car1.Position() << std::endl;

    /*Person person1;
    person1.age = 21;
    person1.name = "Petr";

    Person persons[10];
    persons[0].age = 18;
    persons[1].age = 21;

    // 1 человек
    age[0] = 21;
    name[0] = "Petr";
    surname[0] = "Ivanov";

    // 2 человек
    age[1] = 18;
    // ...*/
    std::cout << "End of program" << std::endl;
}