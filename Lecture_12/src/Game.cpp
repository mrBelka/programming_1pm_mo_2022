#include <Game.hpp>
#include <iomanip>

namespace mt
{
    Game::~Game()
    {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::SetCaption(const std::string& caption)
    {
        m_caption = caption;
    }

    void Game::SetResolution(int width, int height)
    {
        m_width = width;
        m_height = height;
    }

    void Game::Setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
    }

    void Game::Run()
    {
        std::vector<mt::Ball*> balls;
        balls.emplace_back(new mt::Ball({ 0,0 }, { 20,40 }, 10, sf::Color::Red));
        balls.emplace_back(new mt::Ball({ 0,0 }, { 10, 10 }, 50, sf::Color::Yellow));

        sf::Clock timer;

        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            for (int i = 0; i < balls.size(); i++)
            {
                Point p = balls[i]->GetPosition();
                float r = balls[i]->Radius();

                if (p.y + r > m_height)
                {
                    Vec v = balls[i]->GetVelocity();
                    balls[i]->SetVelocity({ v.x, -v.y });
                }
            }

            sf::Time dt = timer.restart();

            for(int i=0;i<balls.size();i++)
                balls[i]->Move(dt.asSeconds());

            m_window->clear();
            for (int i = balls.size() - 1; i >= 0; i--)
                m_window->draw(*balls[i]->Get());
            m_window->display();
        }

        for (int i = 0; i < balls.size(); i++)
            delete balls[i];

    }
}

