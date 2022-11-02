#include <Car.hpp>
#include <iostream>

namespace mt
{
    // Конструктор
    Car::Car(double acceleration, std::string model, double maxVelocity)
    {
        std::cout << "Constructor works!" << std::endl;
        m_acceleration = acceleration;
        m_model = model;
        m_maxVelocity = maxVelocity;
        m_x = 0;
    }

    // Деструктор
    Car::~Car()
    {
        std::cout << "Destructor works!" << std::endl;
        if(m_persons != nullptr)
            delete[] m_persons;
    }

    void Car::Move(double dx)
    {
        m_x += dx;
    }

    // Геттер
    double Car::Position()
    {
        return m_x;
    }

    // Сеттер
    bool Car::SetRadiusOfWheel(int radius)
    {
        if (radius <= 0)
        {
            std::cout << "Error in radius of wheel" << std::endl;
            return false;
        }
        m_raduisOfWheel = radius;
    }

    double Car::Circumference()
    {
        return 2 * acos(-1) * m_raduisOfWheel;
    }

    void Car::Info()
    {
        std::cout << "Model: " << m_model << std::endl;
        std::cout << "Acc: " << m_acceleration << std::endl;
    }

    void Car::SetPersonsQuantity(int n)
    {
        m_persons = new Person[n];
    }
}