#pragma once
#include <string>

namespace mt
{
    struct Person
    {
        int age;
        std::string name;
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
        Person* m_persons = nullptr;

        // 2 принцип: Инкапсуляция - разграничение доступа к полям и методам класса
    public:
        // Конструктор по умолчанию
        Car() {}

        // Конструктор
        Car(double acceleration, std::string model, double maxVelocity);

        // Деструктор
        ~Car();

        // Паттерн строитель
        void SetModel(std::string model)
        {
            m_model = model;
        }

        void SetAcceleration(double acceleration)
        {
            m_acceleration = acceleration;
        }

        void Move(double dx);

        // Геттер
        double Position();

        // Сеттер
        bool SetRadiusOfWheel(int radius);
        void SetPersonsQuantity(int n);

        double Circumference();

        void Info();
    };
}

