#include <Game.hpp>
#include <iomanip>
#include <thread>
#include <chrono>

namespace mt
{
    Game::~Game()
    {
        for (int i = 0; i < m_balls.size(); i++)
            delete m_balls[i];

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

    mt::Errors Game::Setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
    
        mt::Ball* ball = new mt::Ball({ 200,200 }, { 0, 20 });
        if (!ball->Setup("image.png", 0.3, 0.3))
            return Errors::LOAD_PICTURE;
        m_balls.push_back(ball);

        ball = new mt::Ball({ 200,250 }, { -100, -20 });
        if (!ball->Setup("redcircle.png", 0.1, 0.1))
            return Errors::LOAD_PICTURE;
        m_balls.push_back(ball);

        ball = new mt::Ball({ 200,250 }, { -20, -20 });
        if (!ball->Setup("redcircle.png", 0.1, 0.1))
            return Errors::LOAD_PICTURE;
        m_balls.push_back(ball);

        return mt::Errors::SUCCESS;
    }

    mt::Errors Game::Run()
    {
        m_timer.restart();
        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            mt::Ball*& blue = m_balls[0];
            for(int i=1;i<m_balls.size();i++)
                m_balls[i]->CheckCollision(blue);    

            for (int i = 0; i < m_balls.size(); i++)
            {
                utils::Point p = m_balls[i]->GetPosition();
                float r = m_balls[i]->Radius();

                if (p.y + r > m_height)
                {
                    utils::Vec v = m_balls[i]->GetVelocity();
                    m_balls[i]->SetVelocity({ v.x, -v.y });
                }
            }

            sf::Time dt = m_timer.restart();

            for(int i=0;i<m_balls.size();i++)
                m_balls[i]->Move(dt.asSeconds());

            m_window->clear();
            PrepareForDisplay();
            m_window->display();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

