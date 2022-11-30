#pragma once

namespace mt
{
	struct Point
	{
		float x;
		float y;
	};

	struct Vec
	{
		float x;
		float y;
	};

	class Ball
	{
	private:
		Point m_p0;
		Vec m_velocity;
		float m_r;
		sf::CircleShape* m_shape;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
		
	public:
		Ball(Point p0, Vec v, float r, sf::Color color)
		{
			m_p0 = p0;
			m_velocity = v;
			m_r = r;
			//m_shape = new sf::CircleShape(m_r);
			//m_shape->setFillColor(color);
			//m_shape->setOrigin(m_r, m_r);
		}

		bool Setup(const std::string& name)
		{
			m_texture = new sf::Texture;
			if (!m_texture->loadFromFile(name))
			{
				std::cout << "Can`t load " << name << std::endl;
				return false;
			}

			m_sprite = new sf::Sprite;
			m_sprite->setTexture(*m_texture);
			//m_texture->setSmooth(true);
			float scale_x = 0.1;
			float scale_y = 0.1;
			float x = m_texture->getSize().x;
			float y = m_texture->getSize().y;
			m_sprite->setScale(scale_x, scale_y);
			m_sprite->setOrigin(x / 2, y / 2);
			m_sprite->setRotation(90);

			return true;
		}

		~Ball()
		{
			//delete m_shape;
			if(m_texture!=nullptr)
				delete m_texture;
			if (m_sprite != nullptr)
				delete m_sprite;
		}

		void Move(double dt)
		{
			m_p0.x += m_velocity.x * dt;
			m_p0.y += m_velocity.y * dt;
			//std::cout << m_p0.x << " " << m_p0.y << std::endl;
			//std::cout << std::setprecision(7) << x << " " << y << std::endl;
			//m_shape->setPosition(m_p0.x, m_p0.y);
			m_sprite->setPosition(m_p0.x, m_p0.y);
		}

		sf::Sprite* Get() { return m_sprite; }

		void SetVelocity(Vec v)
		{
			m_velocity = v;
		}

		Point GetPosition() { return m_p0; }
		Vec GetVelocity() { return m_velocity; }

		float Radius() { return m_r; }
	};

}