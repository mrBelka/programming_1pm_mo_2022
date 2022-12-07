#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Ball.hpp>

namespace mt
{
    enum class Errors
    {
        SUCCESS = 0,
        LOAD_PICTURE,
    };

    class Game
    {
    private:
        int m_width, m_height;
        std::string m_caption;
        sf::RenderWindow* m_window = nullptr;
        sf::Clock m_timer;
        std::vector<mt::Ball*> m_balls;

    private:
        void PrepareForDisplay()
        {
            for (int i = 0; i < m_balls.size(); i++)
                m_window->draw(*m_balls[i]->Get());
        }

    public:
        Game()
        {
        }

        ~Game();

        void SetCaption(const std::string& caption);

        void SetResolution(int width, int height);

        mt::Errors Setup();

        mt::Errors Run();
    };
}
